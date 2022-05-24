/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 00:14:47 by mcha              #+#    #+#             */
/*   Updated: 2021/11/18 20:24:31 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*new_dst;
	unsigned char	*new_src;
	size_t			i;

	if (dst != src && n)
	{
		i = 0;
		new_dst = (unsigned char *)dst;
		new_src = (unsigned char *)src;
		while (i < n)
		{
			*new_dst = *new_src;
			new_dst++;
			new_src++;
			i++;
		}
	}
	return (dst);
}
