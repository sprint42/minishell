/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is_backslash_appear.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 21:00:52 by mcha              #+#    #+#             */
/*   Updated: 2022/05/30 15:36:31 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

static int	is_real_backslash(int bit)
{
	if (!(bit & DBQT) && !(bit & SNQT))
		return (1);
	return (0);
}

static int	error_is_backslash(int bit, char c)
{
	if (c == '\\' && is_real_backslash(bit))
		return (1);
	return (0);
}

static void	control_backslash(int *bit)
{
	if (!(*bit & DBQT) && !(*bit & SNQT))
		*bit |= BSLA;
}

int	check_is_backslash_appear(t_unit_head *head, char *buf)
{
	char	*ptr;
	int		bit;

	ptr = buf;
	bit = 0;
	while (*ptr)
	{
		if (error_is_quot(bit, *ptr))
			control_quote(&bit, *ptr);
		if (error_is_backslash(bit, *ptr))
			control_backslash(&bit);
		ptr++;
	}
	if (bit & BSLA)
	{
		print_error(head, ERROR_BSLA);
		return (1);
	}
	return (0);
}
