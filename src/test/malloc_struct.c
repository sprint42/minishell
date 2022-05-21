/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 15:56:33 by mcha              #+#    #+#             */
/*   Updated: 2022/05/21 16:54:08 by mcha             ###   ########.fr       */
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
