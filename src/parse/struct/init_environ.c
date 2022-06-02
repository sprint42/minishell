/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_environ.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 13:47:48 by mcha              #+#    #+#             */
/*   Updated: 2022/05/30 14:26:35 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	init_environ(t_point *pck)
{
	char		**storage;
	char		**ptr;
	extern char	**environ;

	ptr = environ;
	while (*ptr)
	{
		storage = ft_split(*ptr, '=');
		link_new_env_node(pck->env, new_env_node(storage[0], storage[1]));
		free_env_storage(storage);
		ptr++;
	}
}
