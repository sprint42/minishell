/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_stream.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 00:43:33 by yejin             #+#    #+#             */
/*   Updated: 2022/06/02 00:43:33 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	save_stream(int	*fd_stdin, int *fd_stdout, t_unit_head *cmd_lst)
{
	*fd_stdin = dup(STDIN_FILENO);
	*fd_stdout = dup(STDOUT_FILENO);
	if (fd_stdin < 0 || fd_stdout < 0)
		exit(handle_main_process_error("fail in dup2", cmd_lst));
}

void	rollback_stream(int fd_stdin, int fd_stdout, t_unit_head *cmd_lst)
{
	if (dup2(fd_stdin, STDIN_FILENO) < 0 || \
		dup2(fd_stdout, STDOUT_FILENO) < 0)
		exit(handle_main_process_error("fail in dup2", cmd_lst));
}
