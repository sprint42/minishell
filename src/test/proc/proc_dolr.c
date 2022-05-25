/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_dolr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:03:53 by mcha              #+#    #+#             */
/*   Updated: 2022/05/25 22:50:28 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

char	*dolr_handler(t_point *pck, char **s)
{
	char	*tmp;
	char	*ret;

	(*s)++;
	tmp = NULL;
	pck->pile = *s;
	while (**s && !find_dolr_trim(pck, **s))
		(*s)++;
	tmp = ft_substr(pck->pile, 0, *s - pck->pile);
	ret = ret_env_value(pck, tmp);
	free(tmp);
	return (ret);
}

void	proc_dolr(t_point *pck, char **s, char **ret)
{
	// *ret = ft_strjoin(*ret, dolr_handler(pck, s));
	// printf("1\n");
	*ret = ft_strjoin_leak(*ret, dolr_handler(pck, s));
	// printf("2\n");
	// printf("AFTER DOLLAR : %s, %s\n", pck->env->env_next->key, pck->env->env_next->value);
	// printf("3\n");
	// printf("[JOIN]	: (s)%s(e)\n", *ret);
}
