/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_redr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 16:41:33 by mcha              #+#    #+#             */
/*   Updated: 2022/05/26 13:54:29 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	proc_redr(t_point *pck, char **s, char **ret, char redr)
{
	if (ft_strlen(*ret) > 0)
		link_new_node(pck->parsed, new_node("STR", *ret));
	free(*ret);
	pck->pile = *s;
	while (**s && find_redr(pck, **s, redr))
		(*s)++;
	*ret = ft_substr(pck->pile, 0, *s - pck->pile);
	if (ft_strlen(*ret) > 0)
		link_new_node(pck->parsed, new_node("REDR", *ret));
	free(*ret);
	*ret = NULL;
}
