/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_if_cmd_null.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 16:29:38 by mcha              #+#    #+#             */
/*   Updated: 2022/05/30 16:30:44 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	malloc_if_cmd_null(t_unit_head **cmd_lst)
{
	if (!(*cmd_lst))
		*cmd_lst = malloc_head();
}
