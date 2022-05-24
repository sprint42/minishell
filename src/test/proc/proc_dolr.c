/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_dolr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:03:53 by mcha              #+#    #+#             */
/*   Updated: 2022/05/24 19:25:41 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

char	*dolr_handler(t_point *pck, char **s)
{
	char	*ret;

	pck->pile = *s;
	(*s)++;
	while (**s && !find_dolr_trim(pck, **s))
		(*s)++;
	ret = ft_substr(pck->pile, 0, *s - pck->pile);
	return ("[ENVP]");
}

void	proc_dolr(t_point *pck, char **s, char **ret)
{
	*ret = ft_strjoin(*ret, dolr_handler(pck, s));
	// printf("[JOIN]	: (s)%s(e)\n", *ret);
}
