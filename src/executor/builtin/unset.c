/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 00:39:16 by yejin             #+#    #+#             */
/*   Updated: 2022/06/02 00:39:17 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

static int	check_unset_validity(char *str)
{
	int	validity;
	int	i;

	validity = 1;
	if (!(ft_isalpha(str[0]) || str[0] == '_'))
		validity = 0;
	i = 0;
	while (str[i])
	{
		if (!(ft_isalnum(str[i]) || str[i] == '_'))
			validity = 0;
		i++;
	}
	if (!validity)
	{
		ft_putstr_fd("not a valid identifier : ", STDERR_FILENO);
		ft_putstr_fd(str, STDERR_FILENO);
		ft_putchar_fd('\n', STDERR_FILENO);
		return (0);
	}
	return (1);
}

void	free_env_element(t_unit_env *env)
{
	if (env == NULL)
		return ;
	if (env->key)
		free(env->key);
	if (env->value)
		free(env->value);
	free(env);
}

void	delete_env(t_unit_head *cmd_lst, char *key)
{
	t_unit_env	*temp;
	t_unit_env	*curr;

	if (cmd_lst->env_next == NULL)
		return ;
	curr = cmd_lst->env_next;
	if (ft_strncmp(curr->key, key, ft_strlen(key) + 1) == 0)
	{
		temp = curr;
		cmd_lst->env_next = curr->env_next;
		free_env_element(temp);
		return ;
	}
	while (curr->env_next)
	{
		if (ft_strncmp(curr->env_next->key, key, ft_strlen(key) + 1) == 0)
		{
			temp = curr->env_next;
			curr->env_next = temp->env_next;
			free_env_element(temp);
			break ;
		}
		curr = curr->env_next;
	}
}

int	execute_unset(t_unit_head *cmd_lst, t_unit_pipe *curr_cmd)
{
	int	i;
	int	exit_code;

	if (curr_cmd->commands[1] == NULL)
		return (handle_default_error("not enough arguments : unset"));
	i = 1;
	exit_code = 0;
	while (curr_cmd->commands[i])
	{
		if (check_unset_validity(curr_cmd->commands[i]) == 0)
			exit_code = 1;
		delete_env(cmd_lst, curr_cmd->commands[i]);
		i++;
	}
	return (exit_code);
}
