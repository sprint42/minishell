/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_is_quot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 20:39:59 by mcha              #+#    #+#             */
/*   Updated: 2022/05/27 20:44:48 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

static int	is_real_squot(int bit)
{
	if (!(bit & DBQT))
		return (1);
	return (0);
}

static int	is_real_dquot(int bit)
{
	if (!(bit & SNQT))
		return (1);
	return (0);
}

int	error_is_quot(int bit, char c)
{
	if (c == '\'' && is_real_squot(bit))
		return (1);
	else if (c == '\"' && is_real_dquot(bit))
		return (1);
	return (0);
}
