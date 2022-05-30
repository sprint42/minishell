#include "execute.h"

int	main(void)
{
	char		*buf;
	t_unit_head	*cmd_lst;
	int	fd_stdin;
	int	fd_stdout;
	int	idx;

	cmd_lst = NULL;
	g_exit_status = 0;
	fd_stdin = 0;
	fd_stdout = 1;
	idx = 0;
	cmd_lst = malloc_head();
	if (!cmd_lst)
		exit(EXIT_FAILURE);
	if (dup2(STDIN_FILENO, fd_stdin) < 0 || dup2(STDOUT_FILENO, fd_stdout) < 0)
			return (handle_main_process_error("fail in dup2", cmd_lst));
	while(1)
	{
		if (!cmd_lst)
			cmd_lst = malloc_head();
		buf = readline("minishell > ");
		add_history(buf);
		if (!is_error(buf) && (ft_strlen(buf) > 0))
		{
			cmd_lst = test(&cmd_lst, buf, idx);
			if (cmd_lst && g_exit_status == 0)
			{
				execute_cmds(cmd_lst);
				cmd_lst->cmd_cnt = 0;
			}
			idx++;
		}
		free(buf);
		if (dup2(fd_stdin, STDIN_FILENO) < 0 || dup2(fd_stdout, STDOUT_FILENO) < 0)
			return (handle_main_process_error("fail in dup2", cmd_lst));
	}
	return (0);
}
