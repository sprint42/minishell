/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 17:37:27 by mcha              #+#    #+#             */
/*   Updated: 2022/05/28 18:09:45 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int	check_syntax_error(t_point *pck)
{
	if (check_is_redr_continuous(pck))
		return (1);
	else if (check_is_pipe_error(pck))
		return (1);
	return (0);
}
