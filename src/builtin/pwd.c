#include "execute.h"

int	execute_pwd(t_unit_head *cmd_lst, t_unit_pipe *curr_cmd)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (pwd == NULL)
		exit_with_error();
	ft_putstr_fd(pwd, STDOUT_FILENO);
	free(pwd);
	return (0);
}