/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejikim <yejikim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 15:06:44 by mcha              #+#    #+#             */
/*   Updated: 2022/05/21 17:56:56 by yejikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int	main(void)
{
	char		*buf;
	t_unit_head	*cmd_lst;

	while(1)
	{
		buf = readline("minishell > ");
		add_history(buf);
		// parsing
		free(buf);
	}
	return (0);
}
