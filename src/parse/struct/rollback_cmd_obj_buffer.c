/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rollback_cmd_obj_buffer.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 16:32:02 by mcha              #+#    #+#             */
/*   Updated: 2022/05/30 16:40:47 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	rollback_cmd_obj_buffer(t_unit_head **cmd_lst, char *buf)
{
	(*cmd_lst)->cmd_cnt = 0;
	(*cmd_lst)->error_flag = 0;
	free(buf);
}
