#include "head.h"
#include "execute.h"

void	free_unit_pipe(t_unit_head *cmd_lst)
{
	t_unit_pipe *curr;
	t_unit_pipe *temp;

	curr = cmd_lst->pp_next;
	while (curr)
	{
		temp = curr;
		curr = curr->pp_next;
		free(temp);
	}
	cmd_lst->pp_next = NULL;
}

void	free_cmd_lst(t_unit_head *cmd_lst)
{
	t_unit_pipe	*curr;
	t_unit_pipe *temp;

	if (cmd_lst->pp_next)
		free_unit_pipe(cmd_lst->pp_next);
	if (cmd_lst->child.pid)
	{
		free(cmd_lst->child.pid);
		cmd_lst->child.pid = NULL;
	}
	if (cmd_lst->child.status)
	{
		free(cmd_lst->child.status);
		cmd_lst->child.status = NULL;
	}
}

void	free_unit_env(t_unit_head *cmd_lst)
{
	t_unit_env	*curr;
	t_unit_env	*temp;

	curr = cmd_lst->env_next;
	while (curr)
	{
		temp = curr;
		curr = curr->env_next;
		if (temp->key)
			free(temp->key);
		if (temp->value)
			free(temp->value);
		free(temp);
	}
	cmd_lst->env_next = NULL;
}

void	free_path(int	**path)
{
	int	i;

	if (path)
	{
		i = 0;
		while (path[i])
			free(path[i++]);
		free(path);
	}
}