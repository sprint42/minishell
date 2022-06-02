/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_special.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 15:45:28 by mcha              #+#    #+#             */
/*   Updated: 2022/05/29 16:54:19 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

char	*init_special_space(void)
{
	char	*space;

	space = (char *)malloc(sizeof(char) * 7);
	space[0] = ' ';
	space[1] = '\t';
	space[2] = '\n';
	space[3] = '\v';
	space[4] = '\f';
	space[5] = '\r';
	space[6] = 0;
	return (space);
}

char	*init_special_dolr(void)
{
	char	*trm;

	trm = (char *)malloc(sizeof(char) * 13);
	trm[0] = ' ';
	trm[1] = '\t';
	trm[2] = '\n';
	trm[3] = '\v';
	trm[4] = '\f';
	trm[5] = '\r';
	trm[6] = '<';
	trm[7] = '>';
	trm[8] = '|';
	trm[9] = '$';
	trm[10] = '\'';
	trm[11] = '\"';
	trm[12] = 0;
	return (trm);
}

void	init_special(t_point *ptr)
{
	ptr->junction->space_trim_set = init_special_space();
	ptr->junction->dolr_trim_set = init_special_dolr();
	init_environ(ptr);
}
