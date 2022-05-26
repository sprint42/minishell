#include "head.h"
#include "execute.h"

int	wait_childs(t_unit_head *cmd_lst, int **pipe_fd)
{
	int	i;
	int ret;

	i = 0;
	while (i < cmd_lst->cmd_cnt)
	{	
		if (cmd_lst->child.pid[i] > 0)
			ret = waitpid(cmd_lst->child.pid[i], &(cmd_lst->child.status[i]), 0);
		i++;
	}
	g_exit_status = (cmd_lst->child.status[--i] & 0x0f) >> 8;
	free_cmd_lst(cmd_lst);
	free_pipe(pipe_fd);
	return (0);
}

int	**generate_pipe(int cmd_cnt)
{
	int	**pipe_fd;
	int	i;
	int	j;

	pipe_fd = malloc(sizeof(int *) * (cmd_cnt - 1));
	if (pipe_fd == NULL)
		return (0);
	i = 0;
	while (i < cmd_cnt - 1)
	{
		pipe_fd[i] = malloc(sizeof(int) * 2);
		if (pipe_fd[i] == NULL)
		{
			j = 0;
			while (j < i)
				free(pipe_fd[j++]);
			free(pipe_fd);
			return (0);
		}
		i++;
	}
	return (pipe_fd);
}

int	execute_last_cmd(t_unit_pipe *curr_cmd, t_unit_head *cmd_lst, int **pipe_fd, int i)
{
	extern char	**environ;

	cmd_lst->child.pid[i] = fork();
	if (cmd_lst->child.pid[i] < 0)
		return (handle_main_process_error("fail in fork\n", cmd_lst));
	if (cmd_lst->child.pid[i] == 0)
		return (execute_childprocess(cmd_lst, curr_cmd, pipe_fd, i));
	return (0);
}

int	breed_childs(t_unit_head *cmd_lst)
{
	int				i;
	int				**pipe_fd;
	t_unit_pipe		*curr_cmd;
	
	i = 0;
	curr_cmd = cmd_lst->pp_next;
	pipe_fd = generate_pipe(cmd_lst->cmd_cnt);
	if (pipe_fd == NULL)
		return (handle_main_process_error("fail in allocating pipe\n", cmd_lst));
	while (i < cmd_lst->cmd_cnt - 1)
	{
		if (pipe(pipe_fd[i]) < 0)
			return (handle_main_process_error("fail in pipe\n", cmd_lst));
		cmd_lst->child.pid[i] = fork();
		if (cmd_lst->child.pid[i] < 0)
			return (handle_main_process_error("fail in fork\n", cmd_lst));
		if (cmd_lst->child.pid[i] == 0)
			return (execute_childprocess(cmd_lst, curr_cmd, pipe_fd, i));
		curr_cmd = curr_cmd->pp_next;
		i++;
	}
	execute_last_cmd(curr_cmd, cmd_lst, pipe_fd, i);
	return (wait_childs(cmd_lst, pipe));
}

int	check_builtin(t_unit_pipe *cmd)
{
	char	*command;

	command = cmd->commands[0];
	if (ft_strlen(command) == 4 && ft_strncmp(command, "echo", 4) == 0)
		return (1);
	if (ft_strlen(command) == 2 && ft_strncmp(command, "cd", 2) == 0)
		return (1);
	if (ft_strlen(command) == 3 && ft_strncmp(command, "pwd", 3) == 0)
		return (1);
	if (ft_strlen(command) == 6 && ft_strncmp(command, "export", 6) == 0)
		return (1);
	if (ft_strlen(command) == 3 && ft_strncmp(command, "env", 3) == 0)
		return (1);
	if (ft_strlen(command) == 4 && ft_strncmp(command, "exit", 4) == 0)
		return (1);
	return (0);
}

int execute_cmds(t_unit_head *cmd_lst)
{
	int	fd_stdin;
	int	fd_stdout;

	if (cmd_lst->cmd_cnt == 1 && check_builtin(cmd_lst->pp_next))
	{
		if (dup2(STDIN_FILENO, fd_stdin) < 0 || dup2(STDOUT_FILENO, fd_stdout) < 0)
			return (handle_main_process_error("fail in dup2\n"));
		g_exit_status = execute_builtin(cmd_lst, cmd_lst->pp_next);
		if (dup2(fd_stdin, STDIN_FILENO) < 0 || dup2(fd_stdout, STDOUT_FILENO) < 0)
			return (handle_main_process_error("fail in dup2\n"));
		close(fd_stdin);
		close(fd_stdout);
		free_cmd_lst(cmd_lst);
		return (0);
	}
	cmd_lst->child.pid = malloc(sizeof(pid_t) * cmd_lst->cmd_cnt);
	cmd_lst->child.status = malloc(sizeof(int) * cmd_lst->cmd_cnt);
	if (cmd_lst->child.pid == NULL || cmd_lst->child.status == NULL)
		return (handle_main_process_error("fail in malloc\n"));
	return (breed_childs(cmd_lst));
}