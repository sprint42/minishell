/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_set_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 14:09:03 by mcha              #+#    #+#             */
/*   Updated: 2022/05/25 22:24:23 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	free_env_storage(char **storage)
{
	free(storage[0]);
	free(storage[1]);
	free(storage);
}

static void	free_junction(t_point *pck)
{
	free(pck->junction->space_trim_set);
	free(pck->junction->dolr_trim_set);
	free(pck->junction);
}

static void	free_environ(t_point *pck)
{
	t_unit_env	*tmp;
	t_unit_env	*ptr;

	tmp = pck->env->env_next;
	free(pck->env);
	ptr = tmp;
	while (ptr)
	{
		free(ptr->key);
		free(ptr->value);
		tmp = tmp->env_next;
		ptr->env_next = 0;
		free(ptr);
		ptr = tmp;
	}
}

static void	free_parsed(t_point *pck)
{
	t_parsed	*tmp;
	t_parsed	*ptr;

	ptr = pck->parsed;
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
		// pck->parsed->next = 0;
		// pck->parsed->prev = 0;
		free(ptr);
		ptr = tmp;
	}
}

void	free_package(t_point *pck)
{
	free_junction(pck);
	free_environ(pck);
	free_parsed(pck);
	free(pck);
}
