/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 16:21:18 by mcha              #+#    #+#             */
/*   Updated: 2022/05/25 15:50:37 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	proc_pipe(t_point *pck, char **s, char **ret)
{
	if (ft_strlen(*ret) > 0)
		link_new_node(pck->parsed, new_node("STR", *ret));
		// printf("\n	[RETN-PIPEE]	: (s)%s(e)\n\n", *ret);
	*ret = ft_substr(*s, 0, *s + 1 - *s);
	// printf("[JOIN]	: (s)%s(e)\n", *ret);
	if (ft_strlen(*ret) > 0)
		link_new_node(pck->parsed, new_node("PIPE", *ret));
		// printf("\n	[RETN-PIPEE]	: (s)%s(e)\n\n", *ret);
	*ret = "";
	(*s)++;
	while (**s && find_pipe(pck, **s))
		(*s)++;
}