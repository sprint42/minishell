/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is_pipe_error.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 17:48:54 by mcha              #+#    #+#             */
/*   Updated: 2022/05/28 18:09:21 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int	check_is_pipe_error(t_point *pck)
{
	t_parsed	*ptr;
	size_t		len;

	len = 0;
	ptr = pck->parsed->next;
	while (ptr)
	{
		len = ft_strlen(ptr->type);
		if (ft_strncmp(ptr->type, "PIPE", len) == 0)
		{
			if (!ptr->next || \
				ft_strncmp(ptr->next->type, "PIPE", len) == 0 || \
				ft_strncmp(ptr->next->type, "PIPE", len) == 0 || \
				ft_strlen(ptr->str) > 1)
			{
				print_error(ERROR_PIPE);
				return (1);
			}
		}
		ptr = ptr->next;
	}
	return (0);	
}
