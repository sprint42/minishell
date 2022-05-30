#include "execute.h"

char	count_env(t_unit_head *cmd_lst)
{
	int			i;
	t_unit_env	*curr;

	i = 0;
	curr = cmd_lst->env_next;
	while (curr)
	{
		if (curr->value)
			i++;
		curr = curr->env_next;
	}
	return (i);
}

char	*make_env_line(t_unit_env *curr)
{
	char	*result;
	char	*temp;

	if (curr->value == NULL)
		return (ft_strdup(curr->key));
	temp = ft_strjoin(curr->key, "=");
	if (temp == NULL)
		return (NULL);
	result = ft_strjoin(temp, curr->value);
	free(temp);
	if (result == NULL)
		return (NULL);
	return(result);
}

char	**make_env_array(t_unit_head *cmd_lst)
{
	char		**envp;
	int			i;
	t_unit_env	*curr;

	envp = malloc(sizeof(char *) * (count_env(cmd_lst) + 1));
	if (envp == NULL)
		return (NULL);
	i = 0;
	curr = cmd_lst->env_next;
	while (curr)
	{
		if (curr->value)
		{
			envp[i] = make_env_line(curr);
			if (envp[i] == NULL)
			{
				free_env_array(envp);
				return (NULL);
			}
			i++;
		}
		curr = curr->env_next;
	}
	envp[i] = NULL;
	return (envp);
}

int	execute_env(t_unit_head *cmd_lst, t_unit_pipe *curr_cmd)
{
	char		**envp;
	int			i;

	if (curr_cmd->commands[1] != NULL)
		return (handle_default_error("too many arguments : env"));
	envp = make_env_array(cmd_lst);
	if (envp == NULL)
		return (handle_default_error("fail in making env : env"));
	i = 0;
	while (envp[i])
	{
		ft_putstr_fd(envp[i], STDOUT_FILENO);
		ft_putchar_fd('\n', STDOUT_FILENO);
		i++;
	}
	free_env_array(envp);
	return (0);
}