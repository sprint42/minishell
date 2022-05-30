/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 13:50:03 by mcha              #+#    #+#             */
/*   Updated: 2022/05/30 14:22:12 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

t_unit_env	*new_env_node(char *key, char *value)
{
	t_unit_env	*node;

	node = (t_unit_env *)malloc(sizeof(t_unit_env));
	if (!node)
	{
		print_malloc_error(ERROR_MALL);
		exit(EXIT_FAILURE);
	}
	node->key = ft_strdup(key);
	node->value = ft_strdup(value);
	node->env_next = NULL;
	return (node);
}

char	*ret_env_value(t_point *pck, char *key)
{
	t_unit_env	*tmp;
	char		*ret;

	ret = NULL;
	tmp = pck->env->env_next;
	if (!ft_strncmp(key, "?", ft_strlen(key)))
	{
		ret = proc_question_mark();
		return (ret);
	}
	while (tmp)
	{
		if (!ft_strncmp(tmp->key, key, ft_strlen(tmp->key)))
		{
			ret = ft_calloc(ft_strlen(tmp->value) + 1, sizeof(char));
			ft_strlcpy(ret, tmp->value, ft_strlen(tmp->value) + 1);
			return (ret);
		}
		tmp = tmp->env_next;
	}
	return (ft_strdup(""));
}

void	link_new_env_node(t_unit_env *og, t_unit_env *new)
{
	t_unit_env	*ptr;

	ptr = og;
	while (ptr->env_next)
		ptr = ptr->env_next;
	ptr->env_next = new;
}
