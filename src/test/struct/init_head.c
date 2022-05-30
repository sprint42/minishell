/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_head.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 14:03:32 by mcha              #+#    #+#             */
/*   Updated: 2022/05/30 14:05:22 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	init_head(t_unit_head *ptr, t_child_info child)
{
	ptr->cmd_cnt = 0;
	ptr->pp_next = NULL;
	ptr->env_next = NULL;
	ptr->child = child;
}
