#include "execute.h"

int	execute_export(t_unit_head *cmd_lst, t_unit_pipe *curr_cmd)
{
	int			i;
	int			exit_code;

	if (curr_cmd->commands[1] == NULL)
		return (print_env(cmd_lst));
	i = 1;
	exit_code = 0;
	while (curr_cmd->commands[i])
	{
		if (check_export_validity(curr_cmd->commands[i]) == 0)
			exit_code = 1;
		else if (add_env(cmd_lst, curr_cmd->commands[i]) != 0)
		{
			ft_putstr_fd("failure in adding env : ", STDOUT_FILENO);
			ft_putstr_fd(curr_cmd->commands[i], STDOUT_FILENO);
			exit_code = 1;
		}
		i++;
	}
	return (exit_code);
}