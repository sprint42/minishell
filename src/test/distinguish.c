/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distinguish.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 15:21:15 by mcha              #+#    #+#             */
/*   Updated: 2022/05/26 13:50:46 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

/*
**	스페셜 문자를 구분한다.
**	만약 스페셜 문자가 아니면 포인터를 증가시킨다.
*/

void	judge_special(t_point *pck, char **s, char **ret)
{
	if (is_space(pck, **s))
	{
		proc_space(pck, s, ret);
	}
	else if (is_pipe(pck, **s))
	{
		proc_pipe(pck, s, ret);
	}
	else if (is_redr(pck, **s))
	{
		proc_redr(pck, s, ret, **s);
	}
	else if (is_dolr(pck, **s))
	{
		proc_dolr(pck, s, ret);
	}
	else if (is_quot(pck, **s))
	{	
		proc_quot(pck, s, ret, **s);
	}
	else
	{
		*ret = ft_strjoin_leak(*ret, ft_substr(*s, 0, 1));
		(*s)++;
	}
	if (is_null(**s))
	{
		proc_null(pck, ret);
	}
}
