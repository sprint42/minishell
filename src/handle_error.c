#include "head.h"
#include "execute.h"

int	hanlde_main_process_error(char *message, t_unit_head *cmd_lst)
{
	ft_putstr_fd(message, STDERR_FILENO);
	g_exit_status = 1;
	return (1);
}