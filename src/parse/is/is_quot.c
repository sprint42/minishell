/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_quot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:33:24 by mcha              #+#    #+#             */
/*   Updated: 2022/05/27 20:43:25 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

static int	is_real_squot(t_point *pck)
{
	if (!(pck->flag & DBQT))
		return (1);
	return (0);
}

static int	is_real_dquot(t_point *pck)
{
	if (!(pck->flag & SNQT))
		return (1);
	return (0);
}

int	is_quot(t_point *pck, char c)
{
	if (c == '\'' && is_real_squot(pck))
		return (1);
	else if (c == '\"' && is_real_dquot(pck))
		return (1);
	return (0);
}
