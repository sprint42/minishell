#include <head.h>
#include <execute.h>

void	get_infile(char	*limiter)
{
	int		fd;
	size_t	len;
	char	*temp;

	fd = open("temp_file", O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd < 0)
		exit_with_error();
	len = ft_strlen(limiter);
	while (1)
	{
		// stdout 복구 값 가지고 넘어와야함 (복구 값을 어디에 저장할 지 생각해봐야함)
		ft_putstr_fd("> ", 1);
		temp = get_next_line(0);
		if (temp == 0)
			exit_with_error(EXIT_FAILURE, "failure in gnl", NULL);
		if (ft_strlen(temp) == len + 1 && strncmp(temp, limiter, len) == 0)
		{
			free(temp);
			break ;
		}
		ft_putstr_fd(temp, fd);
	}
	close(fd);
}

void	redirect_dbin(t_unit_rd *rd)
{
	int		fd;

	get_infile(rd->filename);
	// 해당 파일 open해서 in으로 받고 나중에 unlink -> unlink 시점에 따른 파일의 사용불가능 여부 체크해야 함
	fd = open(rd->filename, O_RDONLY);
	if (fd < 0)
		exit_with_error();
	if (dup2(fd, STDIN_FILENO) < 0)
		exit_with_error();
	close(fd);
}

void	redirect_dbout(t_unit_rd *rd)
{
	int	fd;

	fd = open(rd->filename, O_WRONLY | O_APPEND | O_CREAT, 0644);
	if (fd < 0)
		exit_with_error();
	if (dup2(fd, STDOUT_FILENO) < 0)
		exit_with_error();
	close(fd);
}