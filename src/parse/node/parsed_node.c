/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsed_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 22:19:19 by mcha              #+#    #+#             */
/*   Updated: 2022/05/30 14:11:24 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

t_parsed	*new_node(char *type, char *str)
{
	t_parsed	*node;

	node = (t_parsed *)malloc(sizeof(t_parsed));
	if (!node)
	{
		print_malloc_error(ERROR_MALL);
		exit(EXIT_FAILURE);
	}
	node->type = ft_strdup(type);
	node->str = ft_strdup(str);
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

void	link_new_node(t_parsed *og, t_parsed *new)
{
	t_parsed	*ptr;

	ptr = og;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = new;
	new->prev = ptr;
}
