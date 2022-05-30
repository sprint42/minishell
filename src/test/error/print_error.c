/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 21:29:51 by mcha              #+#    #+#             */
/*   Updated: 2022/05/30 16:26:58 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	print_error(t_unit_head *head, int errorcode)
{
	if (errorcode == ERROR_QUOT)
		printf("\n[Error] quote is not closed :<\n\n");
	else if (errorcode == ERROR_BSLA)
		printf("[Error] backslash is appeared :<\n\n");
	else if (errorcode == ERROR_SEMC)
		printf("\n[Error] semicolon is appeared :<\n\n");
	else if (errorcode == ERROR_REDR)
		printf("\n[Error] parse error near redirection :<\n\n");
	else if (errorcode == ERROR_PIPE)
		printf("\n[Error] parse error near pipe :<\n\n");
	g_exit_status = 1;
	head->error_flag = 1;
}
