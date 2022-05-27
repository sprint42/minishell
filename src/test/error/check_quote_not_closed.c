/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quote_not_closed.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 20:35:59 by mcha              #+#    #+#             */
/*   Updated: 2022/05/27 20:52:02 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int	check_quote_not_closed(char *buf)
{
	char	*ptr;
	int		bit;

	ptr = buf;
	bit = 0;
	while (*ptr)
	{
		if (error_is_quot(bit, *ptr))
			control_quote(&bit, *ptr);
		ptr++;
	}
	if (judge_is_quote_error(bit))
	{
		printf("Yes it is quote error\n");
		return (1);
	}
	printf("No it is not quote error\n");
	return (0);
}
