/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 15:56:33 by mcha              #+#    #+#             */
/*   Updated: 2022/05/29 17:28:44 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

t_point	*malloc_point(void)
{
	t_point *ptr;
	
	ptr = (t_point *)malloc(sizeof(t_point));
	if (!ptr)
		exit(EXIT_FAILURE);
	return (ptr);
}

t_special	*malloc_junction(void)
{
	t_special	*ptr;

	ptr = (t_special *)malloc(sizeof(t_special));
	if (!ptr)
		exit(EXIT_FAILURE);
	return (ptr);
}

t_parsed	*malloc_parsed(void)
{
	t_parsed	*ptr;
	
	ptr = (t_parsed *)malloc(sizeof(t_parsed));
	if (!ptr)
		exit(EXIT_FAILURE);
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
		exit(EXIT_FAILURE);
	ptr->env_next = NULL;
	ptr->key = NULL;
	ptr->value = NULL;
	return (ptr);
}

// t_unit_head	*malloc_head(t_point *pck)
t_unit_head	*malloc_head(void)
{
	t_unit_head		*ptr;
	t_child_info	*child;

	ptr = (t_unit_head *)malloc(sizeof(t_unit_head));
	if (!ptr)
		exit(EXIT_FAILURE);
	child = (t_child_info *)malloc(sizeof(t_child_info));
	if (!child)
		exit(EXIT_FAILURE);
	child->pid = NULL;
	child->status = NULL;
	ptr->cmd_cnt = 0;
	ptr->pp_next = NULL;
	// if (pck->idx == 0)
	// 	ptr->env_next = pck->env->env_next;
	ptr->env_next = NULL;
	ptr->child = *child;
	return (ptr);
}
