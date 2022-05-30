/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 15:56:33 by mcha              #+#    #+#             */
/*   Updated: 2022/05/30 19:12:25 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

t_point	*malloc_point(void)
{
	t_point	*ptr;

	ptr = (t_point *)malloc(sizeof(t_point));
	if (!ptr)
	{
		print_malloc_error(ERROR_MALL);
		exit(EXIT_FAILURE);
	}
	return (ptr);
}

t_special	*malloc_junction(void)
{
	t_special	*ptr;

	ptr = (t_special *)malloc(sizeof(t_special));
	if (!ptr)
	{
		print_malloc_error(ERROR_MALL);
		exit(EXIT_FAILURE);
	}
	return (ptr);
}

t_parsed	*malloc_parsed(void)
{
	t_parsed	*ptr;

	ptr = (t_parsed *)malloc(sizeof(t_parsed));
	if (!ptr)
	{
		print_malloc_error(ERROR_MALL);
		exit(EXIT_FAILURE);
	}
	ptr->str = NULL;
	ptr->type = NULL;
	ptr->next = NULL;
	ptr->prev = NULL;
	return (ptr);
}

t_unit_env	*malloc_env(void)
{
	t_unit_env	*ptr;

	ptr = (t_unit_env *)malloc(sizeof(t_unit_env));
	if (!ptr)
	{
		print_malloc_error(ERROR_MALL);
		exit(EXIT_FAILURE);
	}
	ptr->env_next = NULL;
	ptr->key = NULL;
	ptr->value = NULL;
	return (ptr);
}

t_unit_head	*malloc_head(void)
{
	t_unit_head		*ptr;

	ptr = (t_unit_head *)malloc(sizeof(t_unit_head));
	if (!ptr)
	{
		print_malloc_error(ERROR_MALL);
		exit(EXIT_FAILURE);
	}
	ptr->child.pid = NULL;
	ptr->child.status = NULL;
	init_head(ptr);
	return (ptr);
}
