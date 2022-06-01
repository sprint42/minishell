/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 00:44:06 by yejin             #+#    #+#             */
/*   Updated: 2022/06/02 00:44:06 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

int	handle_default_error(char *message)
{
	ft_putstr_fd(message, STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
	return (1);
}

int	handle_main_process_error(char *message, t_unit_head *cmd_lst)
{
	ft_putstr_fd(message, STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
	g_exit_status = 1;
	free_cmd_lst(cmd_lst);
	return (1);
}

int	handle_child_process_error(int exit_num, int errnum, char *str)
{
	if (errnum == EACCESS)
		ft_putstr_fd("command not found", STDERR_FILENO);
	else
		ft_putstr_fd(strerror(errnum), STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
	exit(exit_num);
}

int	handle_while_generating_error(char *message, t_unit_head *cmd_lst, int i)
{
	int	j;

	ft_putstr_fd(message, STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
	g_exit_status = 1;
	j = 0;
	while (j < i)
	{
		kill(cmd_lst->child.pid[j], SIGTERM);
		j++;
	}
	free_cmd_lst(cmd_lst);
	return (1);
}
