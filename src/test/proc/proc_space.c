/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_space.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 15:22:28 by mcha              #+#    #+#             */
/*   Updated: 2022/05/28 21:20:03 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

/*
**	스페이스 처리 프로세스
**	스페이스를 만나면 스페이스바를 만나지 않을 때까지 포인터를 이동시킨다.
*/

void	proc_space(t_point *pck, char **s, char **ret)
{
	// if (ft_strlen(*ret) > 0)
	link_new_node(pck->parsed, new_node("STR", *ret));
	free(*ret);
	*ret = NULL;
	(*s)++;
	while (**s && find_wspace(pck, **s))
		(*s)++;
}
