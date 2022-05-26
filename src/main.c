#include "head.h"

int	main(void)
{
	char		*buf;
	t_unit_head	*cmd_lst;

	(void)cmd_lst;
	g_exit_status = 0;
	while(1)
	{
		buf = readline("minishell > ");
		add_history(buf);
		test();
		// parsing
		free(buf);
	}
	return (0);
}
