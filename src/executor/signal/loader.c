/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 19:54:01 by mcha              #+#    #+#             */
/*   Updated: 2022/06/01 23:37:47 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	loader(void *int_handler, void *quit_handler)
{
	signal(SIGINT, int_handler);
	signal(SIGQUIT, quit_handler);
}
