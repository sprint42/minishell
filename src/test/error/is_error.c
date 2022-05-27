/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 20:26:42 by mcha              #+#    #+#             */
/*   Updated: 2022/05/27 21:34:54 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int	is_error(char *buf)
{
	printf("buf: [START]%s[END]\n", buf);
	if (check_quote_not_closed(buf))
		return (1);
	if (check_is_backslash_appear(buf))
		return (1);
	if (check_is_semicolon_appear(buf))
		return (1);
	return (0);
}
