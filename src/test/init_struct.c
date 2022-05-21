/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 15:30:42 by mcha              #+#    #+#             */
/*   Updated: 2022/05/21 16:56:22 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	bind_pointer_value(t_point *ptr, t_special *jnc)
{
	ptr->flag = 0;
	ptr->prev = 0;
	ptr->pile = 0;
	ptr->move = 0;
	ptr->junction = jnc;
}

t_point	*init_struct(void)
{
	t_point		*ptr;
	t_special	*junction;
	
	ptr = NULL;
	junction = NULL;
	ptr = malloc_point(ptr);
	junction = malloc_junction(junction);
	bind_pointer_value(ptr, junction);
	return (ptr);
}
