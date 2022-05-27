/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_quote.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 20:46:48 by mcha              #+#    #+#             */
/*   Updated: 2022/05/27 20:52:31 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	control_quote(int *bit, char quot)
{
	if (quot == '\"' && !(*bit & SNQT))
	{
		if (*bit & DBQT)
			*bit -= DBQT;
		else
			*bit |= DBQT;
	}
	else if (quot == '\'' && !(*bit & DBQT))
	{
		if (*bit & SNQT)
			*bit -= SNQT;
		else
			*bit |= SNQT;
	}
}
