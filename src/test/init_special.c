/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_special.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 15:45:28 by mcha              #+#    #+#             */
/*   Updated: 2022/05/21 16:56:24 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

char	*init_special_space(void)
{
	char	*space;

	space = (char *)malloc(sizeof(char) * 2);
	space[0] = ' ';
	space[1] = 0;
	return (space);
}

void	init_special(t_point *ptr)
{
	ptr->junction->space = init_special_space();
	printf("result : %s\n", ptr->junction->space);
}
