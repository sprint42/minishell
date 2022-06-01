/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manufact.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:39:35 by mcha              #+#    #+#             */
/*   Updated: 2022/06/01 21:16:07 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	manufact(t_point *ptr)
{
	t_parsed	*tmp;

	tmp = ptr->parsed->next;
	ptr->flag &= 0;
	while (tmp)
	{
		manufact_type(&tmp, ptr);
		// printf("[AFTERR] %s : %s\n", tmp->type, tmp->str);
		tmp = tmp->next;
	}
}
