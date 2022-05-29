/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 20:36:44 by mcha              #+#    #+#             */
/*   Updated: 2022/05/29 17:16:18 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	link_environ(t_unit_head **head, t_point *pck)
{
	if (pck->idx == 0)
	{
		printf("	LINKED\n");
		(*head)->env_next = pck->env->env_next;
	}
}

t_unit_head	*test(t_unit_head **head, char *target, int idx)
{
	char	*ret;
	char	*tmp_target;
	t_point	*pck;

	pck = init_struct(idx);
	init_special(pck);
	link_environ(head, pck);
	ret = NULL;
	target = ft_strtrim(target, (char const *)pck->junction->space_trim_set);
	if (ft_strlen(target) > 0)
	{
		tmp_target = target;
		while (*tmp_target)
			judge_special(pck, &tmp_target, &ret);
		manufact(pck);
		if (!check_syntax_error(pck))
		{
			link_and_free(&pck, head, &target);
			return (*head);
		}
		else
			link_and_free(&pck, head, &target);
	}
	return (NULL);
}
