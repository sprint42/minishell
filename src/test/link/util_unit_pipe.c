/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_unit_pipe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 15:56:32 by mcha              #+#    #+#             */
/*   Updated: 2022/05/27 19:58:45 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

unsigned int	cnt_cmd(t_parsed *parsed)
{
	t_parsed		*tmp;
	unsigned int	cnt;

	tmp = parsed;
	cnt = 0;
	while (tmp && !check_pipe(tmp->type))
	{
		if (check_type(tmp->type))
		{
			cnt++;
		}
		tmp = tmp->next;
	}
	return (cnt);
}

void	bind_rd_type(t_parsed *type, int *rd)
{
	if (!ft_strncmp(type->str, "<<", ft_strlen(type->str)))
		*rd = DBIN;
	if (!ft_strncmp(type->str, ">>", ft_strlen(type->str)))
		*rd = DBOU;
	if (!ft_strncmp(type->str, "<", ft_strlen(type->str)))
		*rd = SNIN;
	if (!ft_strncmp(type->str, ">", ft_strlen(type->str)))
		*rd = SNOU;
}

int		check_type(char	*type)
{
	return ((ft_strncmp(type, "PIPE", ft_strlen(type)) != 0) \
			&& (ft_strncmp(type, "REDR", ft_strlen(type)) != 0)
			&& (ft_strncmp(type, "FILE", ft_strlen(type)) != 0));
}

int		check_pipe(char *type)
{
	return (ft_strncmp(type, "PIPE", ft_strlen(type)) == 0);
}
