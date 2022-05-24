/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 15:30:42 by mcha              #+#    #+#             */
/*   Updated: 2022/05/24 19:12:24 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

/*
**	flag	: Special 문자를 만났을 때 비트 ON / OFF
**	prev	: 현재 문자의 이전 문자
**	pile	: 말뚝
**	move	: 움직이는 포인터
*/

void	bind_pointer_value(t_point *ptr, t_special *jnc, t_parsed *parsed)
{
	ptr->flag = 0;
	ptr->prev = 0;
	ptr->pile = 0;
	ptr->move = 0;
	ptr->junction = jnc;
	ptr->parsed = parsed;
}

/*
**	ptr			: 구조체 본체
**	junction	: 파싱의 기준점이 될 문자열
**	parsed		: 파싱의 결과물이 저장될 링크드 리스트
*/

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
