/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 15:06:44 by mcha              #+#    #+#             */
/*   Updated: 2022/05/22 13:40:25 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int	main(void)
{
	char		*buf;
	t_unit_head	*cmd_lst;

	g_exit_status = 0;
	while(1)
	{
		buf = readline("minishell > ");
		add_history(buf);
		// parsing
		free(buf);
	}
	return (0);
}
