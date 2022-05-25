/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_environ.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 13:47:48 by mcha              #+#    #+#             */
/*   Updated: 2022/05/25 16:24:24 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

/*
**	System의 environment를 가져오는 변수
**	이 것은 전역 변수에 해당하지 않나?
*/
extern char	**environ;

void	print_env_node(t_unit_env *og)
{
	t_unit_env	*tmp;

	tmp = og->env_next;
	while (tmp)
	{
		printf("NODE	key: %s\n", tmp->key);
		printf("NODE	val: %s\n", tmp->value);
		printf("\n");
		tmp = tmp->env_next;
	}
}

void	init_environ(t_point *pck)
{
	(void)pck;
	char	**storage;
	(void)storage;
	while (*environ)
	{
		// storage = ft_split(*environ, '=');
		// link_new_env_node(pck->env, new_env_node(storage[0], storage[1]));
		// free_env_storage(storage);
		environ++;
	}
	// print_env_node(pck->env);
}