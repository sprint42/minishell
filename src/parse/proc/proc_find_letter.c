/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_find_letter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 15:08:49 by mcha              #+#    #+#             */
/*   Updated: 2022/05/26 13:53:53 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int	find_wspace(t_point *pck, char c)
{
	char	*tmp;

	tmp = pck->junction->space_trim_set;
	while (*tmp)
	{
		if (*tmp == c)
			return (1);
		tmp++;
	}
	if (!(*tmp) && *tmp == c)
		return (1);
	return (0);
}

int	find_pipe(t_point *pck, char c)
{
	(void)pck;
	if (c == '|')
		return (1);
	return (0);
}

int	find_redr(t_point *pck, char c, char redr)
{
	(void)pck;
	if (c == redr)
		return (1);
	return (0);
}

int	find_dolr_trim(t_point *pck, char c)
{
	char	*tmp;

	tmp = pck->junction->dolr_trim_set;
	while (*tmp)
	{
		if (*tmp == c)
		{
			return (1);
		}
		tmp++;
	}
	if (!(*tmp) && *tmp == c)
		return (1);
	return (0);
}
