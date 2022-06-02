/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 16:21:18 by mcha              #+#    #+#             */
/*   Updated: 2022/05/26 13:54:13 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	proc_pipe(t_point *pck, char **s, char **ret)
{
	if (ft_strlen(*ret) > 0)
		link_new_node(pck->parsed, new_node("STR", *ret));
	free(*ret);
	*ret = ft_substr(*s, 0, 1);
	if (ft_strlen(*ret) > 0)
		link_new_node(pck->parsed, new_node("PIPE", *ret));
	free(*ret);
	*ret = NULL;
	(*s)++;
	while (**s && find_pipe(pck, **s))
		(*s)++;
}
