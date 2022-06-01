/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 23:57:13 by yejin             #+#    #+#             */
/*   Updated: 2022/06/01 23:57:14 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

long long	check_first_arg(char *str, int *arg_status)
{
	long long	result;
	int			i;
	int			neg;

	neg = 0;
	if (str[0] == '-')
		neg = 1;
	i = neg - 1;
	while (str[++i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (*arg_status = 1);
	}
	if (i - neg > 19)
		return (*arg_status = 1);
	else if ((i == 20 && ft_strncmp(&(str[neg]), LL_N_MAX, 19) > 0) || \
			(i == 19 && ft_strncmp(&(str[neg]), LL_MAX, 19) > 0))
		return (*arg_status = 1);
	result = 0;
	i = 0;
	while (str[i])
		result = result * 10 + (str[i++] - '0');
	if (neg)
		return (result * -1);
	return (result);
}

int	execute_exit(t_unit_head *cmd_lst, t_unit_pipe *curr_cmd)
{
	int			arg_status;
	long long	exit_num;

	arg_status = 0;
	exit_num = 0;
	if (curr_cmd->commands[1] != NULL)
		exit_num = check_first_arg(curr_cmd->commands[1], &arg_status);
	ft_putstr_fd("exit\n", STDERR_FILENO);
	if (arg_status)
	{
		ft_putstr_fd("numeric argument required : exit\n", STDERR_FILENO);
		free_cmd_lst(cmd_lst);
		free_unit_env(cmd_lst);
		exit(255);
	}
	if (!(curr_cmd->commands[1] == NULL || curr_cmd->commands[2] == NULL))
	{
		ft_putstr_fd("too many arguments : exit\n", STDERR_FILENO);
		return (1);
	}
	free_cmd_lst(cmd_lst);
	free_unit_env(cmd_lst);
	exit((unsigned char)exit_num);
}
