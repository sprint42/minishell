/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 15:30:42 by mcha              #+#    #+#             */
/*   Updated: 2022/05/23 18:54:01 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	bind_pointer_value(t_point *ptr, t_special *jnc, t_parsed *parsed)
{
	ptr->flag = 0;
	ptr->prev = 0;
	ptr->pile = 0;
	ptr->move = 0;
	ptr->junction = jnc;
	ptr->parsed_lst = parsed;
}

t_point	*init_struct(void)
{
	t_point		*ptr;
	t_special	*junction;
	t_parsed	*parsed;

	ptr = NULL;
	junction = NULL;
	parsed = NULL;
	ptr = malloc_point(ptr);
	junction = malloc_junction(junction);
	parsed = malloc_parsed(parsed);
	bind_pointer_value(ptr, junction, parsed);
	return (ptr);
}
