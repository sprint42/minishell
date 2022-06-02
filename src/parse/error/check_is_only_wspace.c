/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is_only_wspace.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 20:06:56 by mcha              #+#    #+#             */
/*   Updated: 2022/05/31 20:13:55 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

static char	*get_space(void)
{
	char	*space;

	space = (char *)malloc(sizeof(char) * 7);
	space[0] = ' ';
	space[1] = '\t';
	space[2] = '\n';
	space[3] = '\v';
	space[4] = '\f';
	space[5] = '\r';
	space[6] = 0;
	return (space);
}

int	check_is_only_wspace(t_unit_head *head, char *buf)
{
	char	*ptr;
	char	*spc;

	spc = get_space();
	ptr = ft_strtrim(buf, spc);
	if (ptr && ft_strlen(ptr) > 0)
	{
		free(spc);
		free(ptr);
		return (0);
	}
	head->error_flag = 1;
	free(spc);
	free(ptr);
	return (1);
}
