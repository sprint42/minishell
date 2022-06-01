#include "execute.h"

void	free_redirection(t_unit_pipe *curr_cmd)
{
	t_unit_rd	*curr;
	t_unit_rd	*temp;

	curr = curr_cmd->rd;
	while (curr)
	{
		temp = curr;
		curr = curr->next;
		if (temp->filename)
			free(temp->filename);
		free(temp);
	}
	curr_cmd->rd = NULL;
}

void	free_unit_pipe(t_unit_head *cmd_lst)
{
	t_unit_pipe *curr;
	t_unit_pipe *temp;

	curr = cmd_lst->pp_next;
	while (curr)
	{
		temp = curr;
		curr = curr->pp_next;
		if (temp->commands)
			free_array_d2(temp->commands);
		if (temp->rd)
			free_redirection(temp);
		free(temp);
	}
	cmd_lst->pp_next = NULL;
}

void	free_cmd_lst(t_unit_head *cmd_lst)
{
	free_unit_pipe(cmd_lst);
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

void	free_array_d2(char	**array_d2)
{
	int	i;

	if (array_d2)
	{
		i = 0;
		while (array_d2[i])
			free(array_d2[i++]);
		free(array_d2);
	}
}