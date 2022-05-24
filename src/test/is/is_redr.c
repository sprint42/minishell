/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_redr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 16:40:02 by mcha              #+#    #+#             */
/*   Updated: 2022/05/24 16:41:22 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

static int is_real_redr(t_point *pck)
{
	if (!(pck->flag & SNQT) && !(pck->flag & DBQT))
		return (1);
	return (0);
}

int	is_redr(t_point *pck, char c)
{
	(void)pck;
	if ((c == '<' || c == '>') && is_real_redr(pck))
		return (1);
	return (0);
}
