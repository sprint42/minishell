/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 23:57:36 by yejin             #+#    #+#             */
/*   Updated: 2022/06/02 00:18:15 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

int	check_export_validity(char *str)
{
	int	validity;
	int	i;

	validity = 1;
	if (!(ft_isalpha(str[0]) || str[0] == '_'))
		validity = 0;
	i = 1;
	while (str[i] && str[i] != '=')
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
