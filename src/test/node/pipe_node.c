/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 19:08:27 by mcha              #+#    #+#             */
/*   Updated: 2022/05/27 19:10:07 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	link_new_pipe_node(t_unit_head *head, t_unit_pipe *new)
{
	t_unit_pipe	*ptr;

	if (!head->pp_next)
	{
		head->pp_next = new;
	}
	else
	{
		ptr = head->pp_next;
		while (ptr->pp_next)
			ptr = ptr->pp_next;
		ptr->pp_next = new;
	}
}
