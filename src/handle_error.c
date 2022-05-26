#include "head.h"
#include "execute.h"

int	handle_main_process_error(char *message, t_unit_head *cmd_lst)
{
	ft_putstr_fd(message, STDERR_FILENO);
	g_exit_status = 1;
	free_cmd_lst(cmd_lst);
	return (1);
}

int handle_child_process_error(int exit_num, int errno, char *str)
{
	// error 문구 출력 후
	exit(exit_num);
}