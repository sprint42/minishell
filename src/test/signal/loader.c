/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 19:54:01 by mcha              #+#    #+#             */
/*   Updated: 2022/05/31 13:47:13 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	loader(void *handler)
{
	extern int	rl_catch_signals;
	rl_catch_signals = 0;
	signal(SIGINT, handler);
	signal(SIGQUIT, handler);
}
