/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_set_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 14:09:03 by mcha              #+#    #+#             */
/*   Updated: 2022/05/28 20:30:03 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	free_env_storage(char **storage)
{
	free(storage[0]);
	free(storage[1]);
	free(storage);
}

static void	free_junction(t_point **pck)
{
	free((*pck)->junction->space_trim_set);
	free((*pck)->junction->dolr_trim_set);
	free((*pck)->junction);
}

static void	free_environ(t_point **pck)
{
	free((*pck)->env);
}

static void	free_parsed(t_point **pck)
{
	t_parsed	*tmp;
	t_parsed	*ptr;

	ptr = (*pck)->parsed;
	tmp = ptr->next;
	free(ptr);
	ptr = tmp;
	while (ptr)
	{
		if (ptr->type)
			free(ptr->type);
		if (ptr->str)
			free(ptr->str);
		tmp = ptr->next;
		free(ptr);
		ptr = tmp;
	}
}

void	free_package(t_point **pck)
{
	free_junction(pck);
	free_environ(pck);
	free_parsed(pck);
	free(*pck);
}
