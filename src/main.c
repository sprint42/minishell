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
		test(cmd_lst);
		// parsing
		free(buf);
	}
	return (0);
}
