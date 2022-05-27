/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 21:29:51 by mcha              #+#    #+#             */
/*   Updated: 2022/05/27 22:14:47 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	print_error(int errorcode)
{
	if (errorcode == ERROR_QUOT)
		printf("\n[Error] quote is not closed :<\n\n");
	else if (errorcode == ERROR_BSLA)
		printf("[Error] backslash is appeared :<\n\n");
	else if (errorcode == ERROR_SEMC)
		printf("\n[Error] semicolon is appeared :<\n\n");
}
