#include "execute.h"

int	wait_childs(t_unit_head *cmd_lst)
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
	return (0);
}

int	breed_childs(t_unit_head *cmd_lst)
{
	int				i;
	int				curr_in;
	int				pipe_fd[2];
	
	i = 0;
	curr_in = STDIN_FILENO;
	while (i < cmd_lst->cmd_cnt)
	{
		if (i != cmd_lst->cmd_cnt - 1 && pipe(pipe_fd) < 0)
			return (handle_while_generating_error("fail in pipe", cmd_lst, i));
		cmd_lst->child.pid[i] = fork();
		if (cmd_lst->child.pid[i] < 0)
			return (handle_while_generating_error("fail in fork", cmd_lst, i));
		if (cmd_lst->child.pid[i] == 0)
			execute_childprocess(cmd_lst, pipe_fd, curr_in, i);
		close(pipe_fd[1]);
		curr_in = pipe_fd[0];
		i++;
	}
	return (wait_childs(cmd_lst));
}

int execute_cmds(t_unit_head *cmd_lst)
{
	int	fd_stdin;
	int	fd_stdout;

	fd_stdin = 0;
	fd_stdout = 1;
	if (cmd_lst->cmd_cnt == 1 && check_builtin(cmd_lst->pp_next))
	{
		if (dup2(STDIN_FILENO, fd_stdin) < 0 || dup2(STDOUT_FILENO, fd_stdout) < 0)
			return (handle_main_process_error("fail in dup2", cmd_lst));
		g_exit_status = execute_builtin(cmd_lst, cmd_lst->pp_next);
		if (dup2(fd_stdin, STDIN_FILENO) < 0 || dup2(fd_stdout, STDOUT_FILENO) < 0)
			return (handle_main_process_error("fail in dup2", cmd_lst));
		close(fd_stdin);
		close(fd_stdout);
		free_cmd_lst(cmd_lst);
		return (0);
	}
	cmd_lst->child.pid = malloc(sizeof(pid_t) * cmd_lst->cmd_cnt);
	cmd_lst->child.status = malloc(sizeof(int) * cmd_lst->cmd_cnt);
	if (cmd_lst->child.pid == NULL || cmd_lst->child.status == NULL)
		return (handle_main_process_error("fail in malloc", cmd_lst));
	return (breed_childs(cmd_lst));
}