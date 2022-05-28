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
	while(1)
	{
		if (dup2(STDIN_FILENO, fd_stdin) < 0 || dup2(STDOUT_FILENO, fd_stdout) < 0)
			return (handle_main_process_error("fail in dup2", cmd_lst));
		buf = readline("minishell > ");
		add_history(buf);
		if (!is_error(buf))
		{
			cmd_lst = test(cmd_lst);
			execute_cmds(cmd_lst);
		}
		/* 테스트 출력 */
		// t_unit_pipe	*tmp;

		// tmp = cmd_lst->pp_next;
		// while (tmp)
		// {
		// 	while (tmp->commands && *tmp->commands)
		// 	{
		// 		printf("commands	: %s\n", *tmp->commands);
		// 		(tmp->commands)++;
		// 	}
		// 	while (tmp->rd)
		// 	{
		// 		printf("redir		: %s\n", tmp->rd->filename);
		// 		tmp->rd = tmp->rd->next;
		// 	}
		// 	tmp = tmp->pp_next;
		// 	printf("\n");
		// }
		/* 출력 종료 */
		// parsing
		free(buf);
		if (dup2(fd_stdin, STDIN_FILENO) < 0 || dup2(fd_stdout, STDOUT_FILENO) < 0)
			return (handle_main_process_error("fail in dup2", cmd_lst));
		close(fd_stdin);
		close(fd_stdout);
	}
	return (0);
}
