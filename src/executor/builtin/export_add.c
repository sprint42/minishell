/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 00:34:09 by yejin             #+#    #+#             */
/*   Updated: 2022/06/02 00:34:10 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	alloc_key_and_value(t_unit_env **pnew, char *str, int eq_idx)
{
	(*pnew)->key = ft_substr(str, 0, eq_idx);
	if ((*pnew)->key == NULL)
	{
		free(*pnew);
		(*pnew) = NULL;
	}
	if (str[eq_idx] == '=')
	{
		(*pnew)->value = ft_substr(str, eq_idx + 1, ft_strlen(str));
		if ((*pnew)->value == NULL)
		{
			free((*pnew)->key);
			free((*pnew));
			(*pnew) = NULL;
		}
	}
}

t_unit_env	*create_env(char *str)
{
	t_unit_env	*pnew;
	int			i;

	pnew = malloc(sizeof(t_unit_env));
	if (pnew == NULL)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	pnew->value = NULL;
	pnew->env_next = NULL;
	alloc_key_and_value(&pnew, str, i);
	return (pnew);
}

static int	change_env(t_unit_env *curr, char *str, char *key, int eq_idx)
{
	if (str[eq_idx] == '\0')
		return (1);
	if (curr->value)
		free(curr->value);
	curr->value = ft_substr(str, eq_idx + 1, ft_strlen(str));
	if (curr->value == NULL)
	{
		free(key);
		return (-1);
	}
	return (1);
}

int	find_and_change_env(t_unit_head *cmd_lst, char *str, int eq_idx)
{
	t_unit_env	*curr;
	char		*key;

	key = ft_substr(str, 0, eq_idx);
	if (key == NULL)
		return (-1);
	curr = cmd_lst->env_next;
	while (curr)
	{
		if (strncmp(curr->key, key, ft_strlen(key) + 1) == 0)
			return (change_env(curr, str, key, eq_idx));
		curr = curr->env_next;
	}
	free(key);
	return (0);
}

int	add_env(t_unit_head *cmd_lst, char *str)
{
	t_unit_env	*pnew;
	int			ret;
	int			i;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	ret = find_and_change_env(cmd_lst, str, i);
	if (ret < 0)
		return (handle_default_error("fail in change env : export"));
	else if (ret == 1)
		return (0);
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
