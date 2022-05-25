/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_null.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 16:09:58 by mcha              #+#    #+#             */
/*   Updated: 2022/05/25 15:50:43 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	proc_null(t_point *pck, char **ret)
{
	// 링크드 리스트에 ret 연결시킨 뒤 초기화
	if (ft_strlen(*ret) > 0)
		link_new_node(pck->parsed, new_node("STR", *ret));
		// printf("\n	[RETN-NULLL]	: (s)%s(e)\n\n", *ret);
	*ret = "";
	// null을 만난 순간 flag도 0으로 초기화 해준다.
	pck->flag = 0;
}
