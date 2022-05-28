/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_quot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:36:53 by mcha              #+#    #+#             */
/*   Updated: 2022/05/28 21:20:57 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

static void	control_quote_switch(t_point *pck, char **s, char quot)
{
	if (quot == '\"' && !(pck->flag & SNQT))
	{
		if (pck->flag & DBQT)
			pck->flag -= DBQT;
		else
			pck->flag |= DBQT;
	}
	else if (quot == '\'' && !(pck->flag & DBQT))
	{
		if (pck->flag & SNQT)
			pck->flag -= SNQT;
		else
			pck->flag |= SNQT;
	}
	(*s)++;
}

static char	*proc_squot(t_point *pck, char **s)
{
	char	*ret;

	pck->pile = *s;
	while (**s && **s != '\'')
		(*s)++;
	ret = ft_substr(pck->pile, 0, *s - pck->pile);
	if (ft_strlen(ret) == 0)
	{
		free(ret);
		return (ft_strdup(""));
	}
	return (ret);
}

void	proc_quot(t_point *pck, char **s, char **ret, char quot)
{
	control_quote_switch(pck, s, quot);
	if (quot == '\"' && (pck->flag & DBQT))
		;
	else if (quot == '\'' && (pck->flag & SNQT))
	{
		*ret = ft_strjoin_leak(*ret, proc_squot(pck, s));
	}
}
