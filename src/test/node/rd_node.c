/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rd_node.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 17:24:23 by mcha              #+#    #+#             */
/*   Updated: 2022/05/30 14:23:05 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

t_unit_rd	*new_rd_node(int rd_type, char *filename)
{
	t_unit_rd	*node;

	node = (t_unit_rd *)malloc(sizeof(t_unit_rd));
	if (!node)
	{
		print_malloc_error(ERROR_MALL);
		exit(EXIT_FAILURE);
	}
	node->rd_type = rd_type;
	node->filename = ft_strdup(filename);
	node->next = NULL;
	return (node);
}

void	link_new_rd_node(t_unit_pipe *unit, t_unit_rd *new)
{
	t_unit_rd	*ptr;

	if (!unit->rd)
		unit->rd = new;
	else
	{
		ptr = unit->rd;
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = new;
	}
}
