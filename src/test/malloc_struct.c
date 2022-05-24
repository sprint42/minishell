/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 15:56:33 by mcha              #+#    #+#             */
/*   Updated: 2022/05/22 22:42:15 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

t_point	*malloc_point(t_point *ptr)
{
	ptr = (t_point *)malloc(sizeof(t_point));
	if (!ptr)
		exit(EXIT_FAILURE);
	return (ptr);
}

t_special	*malloc_junction(t_special *ptr)
{
	ptr = (t_special *)malloc(sizeof(t_special));
	if (!ptr)
		exit(EXIT_FAILURE);
	return (ptr);
}

t_parsed	*malloc_parsed(t_parsed *ptr)
{
	ptr = (t_parsed *)malloc(sizeof(t_parsed));
	if (!ptr)
		exit(EXIT_FAILURE);
	ptr->str = NULL;
	ptr->type = NULL;
	ptr->next = NULL;
	ptr->prev = NULL;
	return (ptr);
}
