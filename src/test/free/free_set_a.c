/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_set_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 14:09:03 by mcha              #+#    #+#             */
/*   Updated: 2022/05/25 16:22:10 by mcha             ###   ########.fr       */
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

	while (pck->env)
	{
		tmp = pck->env->env_next;
		free(pck->env->key);
		free(pck->env->value);
		pck->env->env_next = 0;
		free(pck->env);
		pck->env = tmp;
	}
}

static void	free_parsed(t_point *pck)
{
	t_parsed	*tmp;

	while (pck->parsed)
	{
		tmp = pck->parsed->next;
		pck->parsed->next = 0;
		pck->parsed->prev = 0;
		free(pck->parsed->type);
		free(pck->parsed->str);
		free(pck->parsed);
		pck->parsed = tmp;
	}
}

void	free_package(t_point *pck)
{
	free_junction(pck);
	free_environ(pck);
	free_parsed(pck);
	free(pck);
}
