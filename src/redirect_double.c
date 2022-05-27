#include "execute.h"

int	get_infile(char	*limiter, int curr_out)
{
	size_t	len;
	char	*temp;

	len = ft_strlen(limiter);
	while (1)
	{
		ft_putstr_fd("> ", STDIN_FILENO);
		temp = get_next_line(0);
		if (temp == NULL)
			return (handle_default_error("fail in gnl"));
		if (ft_strlen(temp) == len + 1 && strncmp(temp, limiter, len) == 0)
		{
			free(temp);
			break ;
		}
		free(temp);
		ft_putstr_fd(temp, curr_out);
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
		if (get_infile(rd->filename, pipe_fd[1]) != 0)
			return (1);
		close(pipe_fd[1]);
	}
	close(pipe_fd[1]);
	waitpid(pid, &status, 0);
	if (dup2(pipe_fd[0], STDIN_FILENO) < 0)
		return (handle_default_error(strerror(errno)));
	close(pipe_fd[0]);
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