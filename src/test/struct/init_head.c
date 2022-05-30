/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_head.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 14:03:32 by mcha              #+#    #+#             */
/*   Updated: 2022/05/30 16:36:52 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	init_head(t_unit_head *ptr, t_child_info child)
{
	ptr->idx = 0;
	ptr->error_flag = 0;
	ptr->cmd_cnt = 0;
	ptr->pp_next = NULL;
	ptr->env_next = NULL;
	ptr->child = child;
}
