#include "execute.h"

int	execute_env(t_unit_head *cmd_lst, t_unit_pipe *curr_cmd)
{
	t_unit_env	*curr;

	if (curr_cmd->commands[1] != NULL)
		return (handle_default_error("too many arguments : env"));
	curr = cmd_lst->env_next;
	while (curr)
	{
		ft_putstr_fd(curr->key, STDOUT_FILENO);
		ft_putchar_fd('=', STDOUT_FILENO);
		ft_putstr_fd(curr->value, STDOUT_FILENO);
		ft_putchar_fd('\n', STDOUT_FILENO);
		if (curr->env_next == NULL)
			break ;
		curr = curr->env_next;
	}
	return (0);
}