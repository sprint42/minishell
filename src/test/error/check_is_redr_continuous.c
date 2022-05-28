/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is_redr_continuous.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 17:38:54 by mcha              #+#    #+#             */
/*   Updated: 2022/05/28 18:05:29 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int	check_is_redr_continuous(t_point *pck)
{
	t_parsed	*ptr;
	size_t		len;

	len = 0;
	ptr = pck->parsed->next;
	while (ptr)
	{
		len = ft_strlen(ptr->type);
		if (ft_strncmp(ptr->type, "REDR", len) == 0)
		{
			if (!ptr->next || \
				ft_strncmp(ptr->next->type, "REDR", len) == 0 || \
				ft_strncmp(ptr->next->type, "PIPE", len) == 0 || \
				ft_strlen(ptr->str) > 2)
			{
				print_error(ERROR_REDR);
				return (1);
			}
		}
		ptr = ptr->next;
	}
	return (0);
}
