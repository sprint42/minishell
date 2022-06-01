#include "execute.h"

int	buf_nn(char *buf, t_unit_head *head)
{
	if (!buf)
	{
		free_unit_env(head);
		free_cmd_lst(head);
		exit(EXIT_SUCCESS);
	}
	return (1);
}

int	main(void)
{
	char		*buf;
	t_unit_head	*cmd_lst;
	int			fd_stdin;
	int			fd_stdout;

	cmd_lst = NULL;
	g_exit_status = 0;
	cmd_lst = malloc_head();
	if ((fd_stdin = dup(STDIN_FILENO)) < 0 || (fd_stdout = dup(STDOUT_FILENO)) < 0)
		return (handle_main_process_error("fail in dup2", cmd_lst));
	while(1)
	{
		loader(sig_handler);
		malloc_if_cmd_null(&cmd_lst);
		buf = readline("minishell$ ");
		signal(SIGINT, sig_after_readline_handler);
		signal(SIGQUIT, sig_after_readline_handler);
		add_history(buf);
		if (buf_nn(buf, cmd_lst) && !is_error(cmd_lst, buf) && (ft_strlen(buf) > 0))
		{
			cmd_lst = test(&cmd_lst, buf, cmd_lst->idx);
			if (cmd_lst && cmd_lst->error_flag == 1)
				free_cmd_lst(cmd_lst);
			else
				execute_cmds(cmd_lst);
			cmd_lst->idx++;
		}
		if (dup2(fd_stdin, STDIN_FILENO) < 0 || dup2(fd_stdout, STDOUT_FILENO) < 0)
			return (handle_main_process_error("fail in dup2", cmd_lst));
		rollback_cmd_obj_buffer(&cmd_lst, buf);
	}
	return (0);
}
