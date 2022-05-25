/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distinguish.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 15:21:15 by mcha              #+#    #+#             */
/*   Updated: 2022/05/25 23:01:14 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

/*
**	스페셜 문자를 구분한다.
**	만약 스페셜 문자가 아니면 포인터를 증가시킨다.
*/

void	judge_special(t_point *pck, char **s, char **ret)
{
	// static int a = 0;
	t_unit_env	*ptr;

	ptr = pck->env;
	// printf("[BEFOR_JUDGE] %dth %s, %s\n", a++, ptr->env_next->key, ptr->env_next->value);
	if (is_space(pck, **s))
	{
		// printf("S_SPACE\n");
		proc_space(pck, s, ret);
		// printf("E_SPACE\n");
	}
	else if (is_pipe(pck, **s))
	{
		proc_pipe(pck, s, ret);
		// printf("2\n");
	}
	else if (is_redr(pck, **s))
	{
		// printf("S_REDR\n");
		proc_redr(pck, s, ret, **s);
		// printf("E_REDR\n");
	}
	else if (is_dolr(pck, **s))
	{
		// printf("S_DOLR\n");
		proc_dolr(pck, s, ret);
		// printf("E_DOLR\n");
	}
	else if (is_quot(pck, **s))
	{
		// printf("S_QUOT\n");
		proc_quot(pck, s, ret, **s);
		// printf("E_QUOT\n");
	}
	else
	{
		// printf(">> 1	: %s, %s\n", pck->env->env_next->key, pck->env->env_next->value);
		// printf(">> 2	: %s, %s\n", pck->env->env_next->key, pck->env->env_next->value);
		*ret = ft_strjoin_leak(*ret, ft_substr(*s, 0, 1));
		// printf(">> 3	: %s, %s\n", pck->env->env_next->key, pck->env->env_next->value);
		// printf(">> 4	: %s, %s\n", pck->env->env_next->key, pck->env->env_next->value);
		(*s)++;
		// printf(">> 5	: %s, %s\n", pck->env->env_next->key, pck->env->env_next->value);
		// printf("6\n");
	}
	if (is_null(**s))
	{
		proc_null(pck, ret);
	}

	ptr = pck->env;
	// printf("[AFTER_JUDGE] %s, %s\n", ptr->env_next->key, ptr->env_next->value);
}
