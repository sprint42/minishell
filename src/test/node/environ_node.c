/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 13:50:03 by mcha              #+#    #+#             */
/*   Updated: 2022/05/25 17:03:24 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

t_unit_env	*new_env_node(char *key, char *value)
{
	t_unit_env	*node;

	node = (t_unit_env *)malloc(sizeof(t_unit_env));
	if (!node)
		exit(EXIT_FAILURE);
	node->key = ft_strdup(key);
	node->value = ft_strdup(value);
	node->env_next = NULL;
	return (node);
}

char	*ret_env_value(t_point *pck, char *key)
{
	t_unit_env	*tmp;

	tmp = pck->env->env_next;
	while (tmp)
	{
		if (!ft_strncmp(tmp->key, key, ft_strlen(tmp->key)))
		{
			printf("tmpvalue : %s\n", tmp->value);
			return (tmp->value);
		}
		tmp = tmp->env_next;
	}
	return ("");
}

void	link_new_env_node(t_unit_env *og, t_unit_env *new)
{
	t_unit_env	*ptr;

	ptr = og;
	while (ptr->env_next)
		ptr = ptr->env_next;
	ptr->env_next = new;
}
