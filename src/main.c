#include "execute.h"

int	main(void)
{
	char		*buf;
	t_unit_head	*cmd_lst;
	int	fd_stdin;
	int	fd_stdout;

	cmd_lst = NULL;
	g_exit_status = 0;
	fd_stdin = 0;
	fd_stdout = 1;
	if (dup2(STDIN_FILENO, fd_stdin) < 0 || dup2(STDOUT_FILENO, fd_stdout) < 0)
			return (handle_main_process_error("fail in dup2", cmd_lst));
	while(1)
	{
		buf = readline("minishell > ");
		add_history(buf);
		if (!is_error(buf) && (ft_strlen(buf) > 0))
		{
			cmd_lst = test(cmd_lst, buf);
			if (cmd_lst)
				execute_cmds(cmd_lst);
		}
		free(buf);
		if (dup2(fd_stdin, STDIN_FILENO) < 0 || dup2(fd_stdout, STDOUT_FILENO) < 0)
			return (handle_main_process_error("fail in dup2", cmd_lst));
	}
	return (0);
}
