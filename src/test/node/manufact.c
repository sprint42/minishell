/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manufact.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:39:35 by mcha              #+#    #+#             */
/*   Updated: 2022/05/24 19:18:46 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	print_inner_node_lst(t_parsed *tmp)
{
	printf("===================================== INNER ================================\n");
	while (tmp)
	{
		printf("INNER NODE TYPE : %s\n", tmp->type);
		printf("INNER NODE DATA : %s\n", tmp->str);
		printf("\n");
		tmp = tmp->next;
	}
}

void	manufact(t_point *ptr)
{
	t_parsed	*tmp;

	tmp = ptr->parsed->next;
	ptr->flag &= 0;
	// print_inner_node_lst(tmp);
	while (tmp)
	{
		printf("[BEFORE] TYPE : %s	DATA : %s\n", tmp->type, tmp->str);
		/******************************************************************** 가공 단계 ***********************************/
		manufact_type(&tmp, ptr);
		/******************************************************************** 가공 종료 ***********************************/
		printf("[AFTERR] TYPE : %s	DATA : %s\n", tmp->type, tmp->str);
		tmp = tmp->next;
		printf("\n");
	}
}
