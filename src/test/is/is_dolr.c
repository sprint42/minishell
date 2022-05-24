/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dolr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:01:41 by mcha              #+#    #+#             */
/*   Updated: 2022/05/24 17:31:04 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

static int	is_real_dolr(t_point *pck)
{
	if (!(pck->flag & SNQT) || !(pck->flag & DBQT))
		return (1);
	return (0);
}

int	is_dolr(t_point *pck, char c)
{
	(void)pck;
	if (c == '$' && is_real_dolr(pck))
		return (1);
	return (0);
}
