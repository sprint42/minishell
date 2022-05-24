/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_space.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 15:04:32 by mcha              #+#    #+#             */
/*   Updated: 2022/05/24 16:39:50 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

/*
**	white space 판별
**	현재 single quote나 double quote가 켜져 있으면 스페이스바로 인식하지 않음 문자 그대로로 인식한다.
*/

static int	is_real_space(t_point *pck)
{
	if (!(pck->flag & SNQT) && !(pck->flag & DBQT))
		return (1);
	return (0);
}

int	is_space(t_point *pck, char c)
{
	if (find_wspace(pck, c) && is_real_space(pck))
		return (1);
	return (0);
}
