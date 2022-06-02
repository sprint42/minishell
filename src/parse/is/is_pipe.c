/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 16:19:26 by mcha              #+#    #+#             */
/*   Updated: 2022/05/24 17:33:18 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

/*
**	PIPE 판별
**	현재 파이프가 따옴표 내에 들어가있지 않으면 진짜 파이프
**	그렇지 않으면 가짜 파이프 -> 일반 문자로 인식한다
*/

static int	is_real_pipe(t_point *pck)
{
	if (!(pck->flag & SNQT) && !(pck->flag & DBQT))
		return (1);
	return (0);
}

int	is_pipe(t_point *pck, char c)
{
	(void)pck;
	if (c == '|' && is_real_pipe(pck))
		return (1);
	return (0);
}
