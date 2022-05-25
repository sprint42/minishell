#include "head.h"
#include "execute.h"

int	check_validity(char *str)
{
	int	validity;
	int	i;

	validity = 1;
	if (!(ft_isalpha(str[0]) || str[0] == '_'))
		validity = 0;
	i = 0;
	while (str[i])
	{
		if (!(ft_isalnum(str[i]) || str[i] == '=' || str[i] == '_'))
			validity = 0;
		i++;
	}
	if (!validity)
	{
		ft_putstr_fd("not a valid identifier\n", STDOUT_FILENO);
		return (0);
	}
	return (1);
}

t_unit_env	*create_env(char *str)
{
	t_unit_env	*pnew;
	int			i;

	pnew = malloc(sizeof(t_unit_env));
	if (pnew == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '=')
		i++;
	pnew->key = ft_substr(str, 0, i);
	if (pnew->key == NULL)
	{
		free(pnew);
		return (NULL);
	}
	pnew->value = ft_substr(str, i + 2, ft_strlen(str));
	if (pnew->value == NULL)
	{
		free(pnew->key);
		free(pnew);
		return (NULL);
	}
	pnew->env_next = NULL;
	return (pnew);
}

int	find_and_change_env(t_unit_head *cmd_lst, char *key)
{
	t_unit_env	*curr;
	char		*temp;

	curr = cmd_lst->env_next;
	while (curr)
	{
		if (strncmp(curr->key, key, ft_strlen(key) + 1) == 0)
		{
			free(curr->key);
			curr->key = key;
			return (1);
		}
		if (curr->env_next == NULL)
			break ;
		curr = curr->env_next;
	}
	return (0);
}

int	add_env(t_unit_head *cmd_lst, char *str)
{
	t_unit_env	*pnew;
	int			i;
	char		*key;

	i = 0;
	while (str[i] != '=')
		i++;
	if (key == NULL)
		return (1);
	if (find_and_change_env(cmd_lst, key))
		return (0);
	free(key);
	pnew = create_env(str);
	if (pnew == NULL)
		return (1);
	if (cmd_lst->env_next == NULL)
		cmd_lst->env_next = pnew;
	else
	{
		pnew->env_next = cmd_lst->env_next;
		cmd_lst->env_next = pnew;
	}
	return (0);
}

int	execute_export(t_unit_head *cmd_lst, t_unit_pipe *curr_cmd)
{
	int			i;
	int			exit_code;
	t_unit_env	*pnew;
	char		*key;

	if (curr_cmd->commands[1] == NULL)
		return (print_env(cmd_lst));
	i = -1;
	exit_code = 0;
	while (curr_cmd->commands[++i])
	{
		if (ft_strchr(curr_cmd->commands[i], '=') == NULL)
			continue;
		if (check_validity(curr_cmd->commands[i]) == 0)
			exit_code = 1;
		else if (add_env(cmd_lst, curr_cmd->commands[i]) != 0)
		{
			ft_putstr_fd("failure in adding env : ", STDOUT_FILENO);
			ft_putstr_fd(curr_cmd->commands[i], STDOUT_FILENO);
			exit_code = 1;
		}
	}
	return (exit_code);
}