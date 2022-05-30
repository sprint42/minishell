/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 20:26:42 by mcha              #+#    #+#             */
/*   Updated: 2022/05/30 15:36:39 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int	is_error(t_unit_head *head, char *buf)
{
	if (check_quote_not_closed(head, buf))
		return (1);
	if (check_is_backslash_appear(head, buf))
		return (1);
	if (check_is_semicolon_appear(head, buf))
		return (1);
	return (0);
}
