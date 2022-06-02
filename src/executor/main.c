/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 23:46:57 by yejin             #+#    #+#             */
/*   Updated: 2022/06/02 13:30:36 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

int	buf_nn(char *buf, t_unit_head *head)
{
	if (!buf)
	{
		free_unit_env(head);
		free_cmd_lst(head);
		exit(EXIT_SUCCESS);
	}
	return (1);
}

void	check_cmdline(char *buf, t_unit_head *cmd_lst)
{
	if (buf_nn(buf, cmd_lst) && !is_error(cmd_lst, buf) && (ft_strlen(buf) > 0))
	{
		cmd_lst = test(&cmd_lst, buf, cmd_lst->idx);
		if (cmd_lst && cmd_lst->error_flag == 1)
			free_cmd_lst(cmd_lst);
		else
			execute_cmds(cmd_lst);
		cmd_lst->idx++;
	}
}

int	main(void)
{
	char		*buf;
	t_unit_head	*cmd_lst;
	int			fd_stdin;
	int			fd_stdout;

	g_exit_status = 0;
	cmd_lst = malloc_head();
	save_stream(&fd_stdin, &fd_stdout, cmd_lst);
	while (1)
	{
		loader(sig_handler, sig_handler);
		malloc_if_cmd_null(&cmd_lst);
		buf = readline("minishell$ ");
		loader(sig_after_readline_handler, sig_after_readline_handler);
		add_history(buf);
		check_cmdline(buf, cmd_lst);
		rollback_stream(fd_stdin, fd_stdout, cmd_lst);
		rollback_cmd_obj_buffer(&cmd_lst, buf);
	}
	return (0);
}
