/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 17:47:55 by mcha              #+#    #+#             */
/*   Updated: 2022/05/24 11:22:40 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

/*
**	공백을 만났을 때
*/
void	is_space(t_point *pck, char **s)
{
	char	*tmp;

	tmp = pck->junction->space;
	if (!(pck->flag & SPCE) && !(pck->flag & SNQT) && !(pck->flag & DBQT))
	{
		while (*tmp)
		{
			// printf("	spc: %c\n", *tmp);
			if (**s == *tmp)
			{
				proc_space(pck, s);
				break;
			}
			tmp++;
		}	
	}
}

void	is_dollar(t_point *pck, char **s)
{
	if (**s == '$')
		proc_dollar(pck, s);
}

void	is_null(t_point *pck, char **s)
{
	if (!**s || !pck->move)
		proc_null(pck, s);
}

int	is_quote(t_point *pck, char **s)
{
	// if (**s == '\'')
	// 	proc_squote(pck, s);
	// else if (**s == '\"')
	// 	proc_dquote(pck, s);
	if ((**s) == '\'' || (**s) == '\"')
	{
		proc_quote(pck, s);
		return (1);
	}
	return (0);
}

void	is_pipe(t_point *pck, char **s)
{
	if (**s == '|')
	{
		// printf("yes\n");
		proc_pipe(pck, s);
	}
}

void	is_redir(t_point *pck, char **s)
{
	if (**s == '<')
	{
		proc_inred(pck, s);
	}
	else if (**s == '>')
	{
		proc_oured(pck, s);
	}
}