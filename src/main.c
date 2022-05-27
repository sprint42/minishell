#include "execute.h"

int	main(void)
{
	char		*buf;
	t_unit_head	*cmd_lst;

	cmd_lst = NULL;
	g_exit_status = 0;
	while(1)
	{
		buf = readline("minishell > ");
		add_history(buf);
		if (!is_error(buf))
			cmd_lst = test(cmd_lst);
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
	}
	return (0);
}
