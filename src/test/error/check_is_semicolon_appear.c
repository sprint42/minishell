/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is_semicolon_appear.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 21:00:52 by mcha              #+#    #+#             */
/*   Updated: 2022/05/27 22:00:03 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

static int	is_real_semicolon(int bit)
{
	if (!(bit & DBQT) && !(bit & SNQT))
		return (1);
	return (0);
}

static int	error_is_semicolon(int bit, char c)
{
	if (c == ';' && is_real_semicolon(bit))
		return (1);
	return (0);
}

static void	control_semicolon(int *bit)
{
	if (!(*bit & DBQT) && !(*bit & SNQT))
		*bit |= SEMC;
}

int	check_is_semicolon_appear(char *buf)
{
	char	*ptr;
	int		bit;

	ptr = buf;
	bit = 0;
	while (*ptr)
	{
		if (error_is_quot(bit, *ptr))
			control_quote(&bit, *ptr);
		if (error_is_semicolon(bit, *ptr))
			control_semicolon(&bit);
		ptr++;
	}
	if (bit & SEMC)
		return (1);
	return (0);
}
