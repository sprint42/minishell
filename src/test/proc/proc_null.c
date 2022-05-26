/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_null.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 16:09:58 by mcha              #+#    #+#             */
/*   Updated: 2022/05/26 13:54:05 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	proc_null(t_point *pck, char **ret)
{
	if (ft_strlen(*ret) > 0)
		link_new_node(pck->parsed, new_node("STR", *ret));
	free(*ret);
	*ret = NULL;
	pck->flag = 0;
}
