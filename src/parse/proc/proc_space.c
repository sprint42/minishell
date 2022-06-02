/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_space.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 15:22:28 by mcha              #+#    #+#             */
/*   Updated: 2022/05/30 14:24:20 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	proc_space(t_point *pck, char **s, char **ret)
{
	if (*ret)
		link_new_node(pck->parsed, new_node("STR", *ret));
	free(*ret);
	*ret = NULL;
	(*s)++;
	while (**s && find_wspace(pck, **s))
		(*s)++;
}
