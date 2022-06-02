/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_null.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 16:09:58 by mcha              #+#    #+#             */
/*   Updated: 2022/06/02 13:31:12 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	proc_null(t_point *pck, char **ret)
{
	if (*ret)
		link_new_node(pck->parsed, new_node("STR", *ret));
	free(*ret);
	*ret = NULL;
	pck->flag = 0;
}
