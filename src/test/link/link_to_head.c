/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_to_head.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 15:46:34 by mcha              #+#    #+#             */
/*   Updated: 2022/05/28 12:18:58 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

static void	create_commands(t_parsed *parsed, t_unit_pipe *unit, unsigned int cnt)
{
	t_parsed		*tmp;
	unsigned int	idx;

	idx = 0;
	tmp = parsed;
	unit->commands = (char **)malloc(sizeof(char *) * (cnt + 1));
	unit->commands[cnt] = NULL;
	while (idx < cnt && tmp && !check_pipe(tmp->type))
	{
		if (check_type(tmp->type))
		{
			unit->commands[idx] = ft_strdup(tmp->str);
			idx++;
		}
		tmp = tmp->next;
	}
}

static void create_redirection(t_parsed *parsed, t_unit_pipe *unit)
{
	int			rd_type;
	t_parsed	*tmp;

	rd_type = -1;
	tmp = parsed;
	while (tmp && (ft_strncmp(tmp->type, "PIPE", ft_strlen(tmp->type)) != 0))
	{
		if (!ft_strncmp(tmp->type, "REDR", ft_strlen(tmp->type)))
			bind_rd_type(tmp, &rd_type);
		if (!ft_strncmp(tmp->type, "FILE", ft_strlen(tmp->type)))
			link_new_rd_node(unit, new_rd_node(rd_type, tmp->str));
		tmp = tmp->next;
	}
}

static t_unit_pipe	*create_unit_pipe(t_parsed *parsed)
{
	unsigned int	cnt;
	t_unit_pipe		*unit;

	unit = (t_unit_pipe *)malloc(sizeof(t_unit_pipe));
	if (!unit)
		exit(EXIT_FAILURE);
	unit->commands = NULL;
	unit->rd = NULL;
	unit->pp_next = NULL;
	// printf("parsed str : %s\n", parsed->str);
	cnt = cnt_cmd(parsed);
	if (cnt)
		create_commands(parsed, unit, cnt);
	create_redirection(parsed, unit);
	unit->pp_next = NULL;
	return (unit);
}

static void	move_to_forward(t_parsed **tmp)
{
	while (*tmp && !check_pipe((*tmp)->type))
		(*tmp) = (*tmp)->next;
	if ((*tmp) && check_pipe((*tmp)->type))
		(*tmp) = (*tmp)->next;
}

void	link_to_head(t_point *pck, t_unit_head *head)
{
	t_parsed	*tmp;

	tmp = pck->parsed->next;
	while (tmp)
	{
		link_new_pipe_node(head, create_unit_pipe(tmp));
		move_to_forward(&tmp);
		(head->cmd_cnt)++;
	}
}
