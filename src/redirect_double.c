#include "execute.h"

int	get_infile(char	*limiter, int curr_out)
{
	size_t	len;
	char	*buf;
	
	signal(SIGINT, SIG_DFL);
	len = ft_strlen(limiter);
	while (1)
	{
		buf = readline("> ");
		if (buf == NULL)
			return (0);
		if (ft_strlen(buf) == len && strncmp(buf, limiter, len) == 0)
		{
			free(buf);
			break ;
		}
		free(buf);
		ft_putstr_fd(buf, curr_out);
		ft_putchar_fd('\n', curr_out);
	}
	return (0);
}

int	redirect_dbin(t_unit_rd *rd)
{
	int		pipe_fd[2];
	pid_t	pid;
	int		status;

	if (pipe(pipe_fd) < 0)
		return (handle_default_error(strerror(errno)));
	pid = fork();
	if (pid < 0)
		return (handle_default_error(strerror(errno)));
	if (pid == 0)
	{
		close(pipe_fd[0]);
		get_infile(rd->filename, pipe_fd[1]);
		close(pipe_fd[1]);
		exit(0);
	}
	close(pipe_fd[1]);
	if (dup2(pipe_fd[0], STDIN_FILENO) < 0)
		return (handle_default_error(strerror(errno)));
	close(pipe_fd[0]);
	waitpid(pid, &status, 0);
	if ((status & 0x00ff) != 0)
		return (1);
	return (0);
}

int	redirect_dbout(t_unit_rd *rd)
{
	int	fd;

	fd = open(rd->filename, O_WRONLY | O_APPEND | O_CREAT, 0644);
	if (fd < 0)
		return (handle_default_error(strerror(errno)));
	if (dup2(fd, STDOUT_FILENO) < 0)
		return (handle_default_error(strerror(errno)));
	close(fd);
	return (0);
}