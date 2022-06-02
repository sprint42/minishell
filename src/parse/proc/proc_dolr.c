/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_dolr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:03:53 by mcha              #+#    #+#             */
/*   Updated: 2022/06/02 22:29:02 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

char	*dolr_handler(t_unit_head *head, t_point *pck, char **s)
{
	char	*tmp;
	char	*ret;

	(*s)++;
	tmp = NULL;
	pck->pile = *s;
	while (**s && !find_dolr_trim(pck, **s))
	{
		if (**s == '?')
		{
			(*s)++;
			break ;
		}
		(*s)++;
	}
	tmp = ft_substr(pck->pile, 0, *s - pck->pile);
	ret = ret_env_value(head, tmp);
	free(tmp);
	return (ret);
}

void	proc_dolr(t_unit_head *head, t_point *pck, char **s, char **ret)
{
	*ret = ft_strjoin_leak(*ret, dolr_handler(head, pck, s));
}
