/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is_backslash_appear.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 21:00:52 by mcha              #+#    #+#             */
/*   Updated: 2022/05/27 21:31:43 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int	check_is_backslash_appear(char *buf)
{
	char	*ptr;

	ptr = buf;
	while (*ptr)
	{
		if (*ptr == '\\')
		{
			print_error(ERROR_BSLA);
			return (1);
		}
		ptr++;
	}
	return (0);
}