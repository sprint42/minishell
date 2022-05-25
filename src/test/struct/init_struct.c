/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 15:30:42 by mcha              #+#    #+#             */
/*   Updated: 2022/05/25 15:18:19 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

/*
**	flag	: Special 문자를 만났을 때 비트 ON / OFF
**	prev	: 현재 문자의 이전 문자
**	pile	: 말뚝
**	move	: 움직이는 포인터
*/

static void	bnd_ptr_val(t_point *ptr, t_special *jnc, \
						t_parsed *par, t_unit_env *env)
{
	ptr->flag = 0;
	ptr->prev = 0;
	ptr->pile = 0;
	ptr->move = 0;
	ptr->junction = jnc;
	ptr->parsed = par;
	ptr->env = env;
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
	t_unit_env	*env;

	ptr = NULL;
	junction = NULL;
	parsed = NULL;
	env = NULL;
	ptr = malloc_point(ptr);
	junction = malloc_junction(junction);
	parsed = malloc_parsed(parsed);
	env = malloc_env(env);
	bnd_ptr_val(ptr, junction, parsed, env);
	ptr->junction = junction;
	ptr->parsed = parsed;
	ptr->env = env;
	return (ptr);
}
