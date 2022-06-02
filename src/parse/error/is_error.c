/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 20:26:42 by mcha              #+#    #+#             */
/*   Updated: 2022/05/31 20:06:46 by mcha             ###   ########.fr       */
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
	if (check_is_only_wspace(head, buf))
		return (1);
	return (0);
}
