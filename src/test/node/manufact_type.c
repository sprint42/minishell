/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manufact_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 15:00:06 by mcha              #+#    #+#             */
/*   Updated: 2022/05/24 19:19:57 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	str_handler(t_parsed **tmp, t_point *ptr)
{
	if (!(*tmp)->prev->type)
	{
		(*tmp)->type = "COMM";
		ptr->flag |= COMM;
	}
	else if (!ft_strncmp((*tmp)->prev->type, "REDR", 4))
		(*tmp)->type = "FILE";
	else if (!(ptr->flag & COMM))
	{
		(*tmp)->type = "COMM";
		ptr->flag |= COMM;
	}
	else if (ptr->flag & COMM)
		(*tmp)->type = "ARGS";
}

void	pipe_handler(t_parsed **tmp, t_point *ptr)
{
	(void)tmp;
	ptr->flag = 0;
}

void	manufact_type(t_parsed **tmp, t_point *ptr)
{
	if (!ft_strncmp((*tmp)->type, "STR", 3))
		str_handler(tmp, ptr);
	else if (!ft_strncmp((*tmp)->type, "PIPE", 4))
		pipe_handler(tmp, ptr);
}
