/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manufact_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 15:00:06 by mcha              #+#    #+#             */
/*   Updated: 2022/05/24 15:08:18 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	str_handler(t_parsed **tmp, t_point *ptr)
{
	if (!(*tmp)->prev->type)
	{
		(*tmp)->type = "COMM";
		ptr->flag |= COMM;
	}
	else if (!ft_strncmp((*tmp)->prev->type, "SNIN", 4) || !ft_strncmp((*tmp)->prev->type, "SNOU", 4) || \
		!ft_strncmp((*tmp)->prev->type, "DBIN", 4) || !ft_strncmp((*tmp)->prev->type, "DBOU", 4))
		(*tmp)->type = "FILE";
	else if (!(ptr->flag & COMM))
	{
		(*tmp)->type = "COMM";
		ptr->flag |= COMM;
	}
	else if (ptr->flag & COMM)
		(*tmp)->type = "ARGS";
}

void	pipe_handler(t_parsed **tmp, t_point *ptr)
{
	(void)tmp;
	ptr->flag = 0;
}

void	dbquote_handler(t_parsed **tmp, t_point *ptr)
{
	str_handler(tmp, ptr);
}

void	snquote_handler(t_parsed **tmp, t_point *ptr)
{
	(void)ptr;
	char	*cut_fst_pile;
	char	*cut_fst_move;
	char	*cut_scd_pile;
	char	*cut_scd_move;
	
	cut_fst_pile = (*tmp)->str;
	cut_fst_move = (*tmp)->str;
	while (*cut_fst_move != '\'')
		cut_fst_move++;
	cut_scd_pile = cut_fst_move + 1;
	cut_scd_move = cut_scd_pile;
	while (*cut_scd_move != '\'')
		cut_scd_move++;
	(*tmp)->str = ft_strjoin(ft_substr(cut_fst_pile, 0, cut_fst_move - cut_fst_pile), ft_substr(cut_scd_pile, 0, cut_scd_move - cut_scd_pile));
}

void	manufact_type(t_parsed **tmp, t_point *ptr)
{
	if (!ft_strncmp((*tmp)->type, "STR", 3))
		str_handler(tmp, ptr);
	else if (!ft_strncmp((*tmp)->type, "PIPE", 4))
		pipe_handler(tmp, ptr);
	else if (!ft_strncmp((*tmp)->type, "DQUOTE", 6))
		dbquote_handler(tmp, ptr);
	else if (!ft_strncmp((*tmp)->type, "SQUOTE", 6))
		snquote_handler(tmp, ptr);
}
