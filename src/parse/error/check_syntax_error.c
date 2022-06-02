/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 17:37:27 by mcha              #+#    #+#             */
/*   Updated: 2022/05/30 16:26:57 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int	check_syntax_error(t_unit_head *head, t_point *pck)
{
	if (check_is_redr_continuous(head, pck))
		return (1);
	else if (check_is_pipe_error(head, pck))
		return (1);
	return (0);
}
