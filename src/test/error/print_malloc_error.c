/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_malloc_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:41:31 by mcha              #+#    #+#             */
/*   Updated: 2022/05/30 13:47:08 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	*print_malloc_error(int errorcode)
{
	if (errorcode == ERROR_MALL)
		printf("\n\n[Error] Memory allocation failed :<\n\n");
	g_exit_status = 2;
	return (NULL);
}
