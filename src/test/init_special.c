/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_special.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 15:45:28 by mcha              #+#    #+#             */
/*   Updated: 2022/05/24 11:59:57 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

char	*init_special_space(void)
{
	char	*space;

	space = (char *)malloc(sizeof(char) * 7);
	space[0] = ' ';
	space[1] = '\t';
	space[2] = '\n';
	space[3] = '\v';
	space[4] = '\f';
	space[5] = '\r';
	space[6] = 0;
	return (space);
}

char	*init_special_trim(void)
{
	char	*trm;

	trm = (char *)malloc(sizeof(char) * 11);
	trm[0] = ' ';
	trm[1] = '\t';
	trm[2] = '\n';
	trm[3] = '\v';
	trm[4] = '\f';
	trm[5] = '\r';
	trm[6] = '<';
	trm[7] = '>';
	trm[8] = '|';
	trm[9] = '$';
	trm[10] = 0;
	return (trm);
}

char	*init_squote_trim(void)
{
	char	*trm;

	trm = (char *)malloc(sizeof(char) * 7);
	trm[0] = '|';
	trm[1] = '>';
	trm[2] = '<';
	trm[3] = '\"';
	trm[4] = '\'';
	trm[5] = '$';
	trm[6] = 0;
	return (trm);
}

char	*init_dquote_trim(void)
{
	char	*trm;

	trm = (char *)malloc(sizeof(char) * 13);
	trm[0] = ' ';
	trm[1] = '\t';
	trm[2] = '\n';
	trm[3] = '\v';
	trm[4] = '\f';
	trm[5] = '\r';
	trm[6] = '|';
	trm[7] = '>';
	trm[8] = '<';
	trm[9] = '\"';
	trm[10] = '\'';
	trm[11] = '$';
	trm[12] = 0;
	return (trm);
}

char	*init_between_trim(void)
{
	char	*trm;

	trm = (char *)malloc(sizeof(char) * 13);
	trm[0] = ' ';
	trm[1] = '\t';
	trm[2] = '\n';
	trm[3] = '\v';
	trm[4] = '\f';
	trm[5] = '\r';
	trm[6] = '<';
	trm[7] = '>';
	trm[8] = '|';
	trm[9] = '$';
	trm[10] = '\'';
	trm[11] = '\"';
	trm[12] = 0;
	return (trm);
}

char	*init_dollar_trim(void)
{
	char	*trm;

	trm = (char *)malloc(sizeof(char) * 13);
	trm[0] = ' ';
	trm[1] = '\t';
	trm[2] = '\n';
	trm[3] = '\v';
	trm[4] = '\f';
	trm[5] = '\r';
	trm[6] = '<';
	trm[7] = '>';
	trm[8] = '|';
	trm[9] = '$';
	trm[10] = '\'';
	trm[11] = '\"';
	trm[12] = 0;
	return (trm);
}

void	init_special(t_point *ptr)
{
	ptr->junction->space = init_special_space();
	ptr->junction->trm = init_special_trim();
	ptr->junction->squote_trm = init_squote_trim();
	ptr->junction->dquote_trm = init_dquote_trim();
	ptr->junction->between_trm = init_between_trim();
	ptr->junction->dollar_trm = init_dollar_trim();
}
