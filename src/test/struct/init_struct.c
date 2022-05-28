/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 15:30:42 by mcha              #+#    #+#             */
/*   Updated: 2022/05/28 20:33:50 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

/*
**	flag	: Special 문자를 만났을 때 비트 ON / OFF
**	prev	: 현재 문자의 이전 문자
**	pile	: 말뚝
**	move	: 움직이는 포인터
*/

static void	bnd_ptr_val(t_point *ptr)
{
	ptr->flag = 0;
	ptr->prev = 0;
	ptr->pile = 0;
	ptr->move = 0;
	ptr->junction = NULL;
	ptr->parsed = NULL;
	ptr->env = NULL;
}

/*
**	ptr			: 구조체 본체
**	junction	: 파싱의 기준점이 될 문자열
**	parsed		: 파싱의 결과물이 저장될 링크드 리스트
**	env			: 환경 변수가 저장 될 링크드 리스트
*/

t_point	*init_struct(void)
{
	t_point	*ptr;

	ptr = malloc_point();
	bnd_ptr_val(ptr);
	ptr->junction = malloc_junction();
	ptr->parsed = malloc_parsed();
	ptr->env = malloc_env();
	return (ptr);
}
