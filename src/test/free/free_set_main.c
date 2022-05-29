/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_set_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 20:21:02 by mcha              #+#    #+#             */
/*   Updated: 2022/05/29 16:54:05 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	link_and_free(t_point **pck, t_unit_head **head, char **target)
{
	link_to_head(pck, head);
	free_package(pck);
	free(*target);
}
