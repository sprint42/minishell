/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 00:15:41 by mcha              #+#    #+#             */
/*   Updated: 2022/05/27 19:55:45 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*buf;
	int		idx;

	idx = 0;
	buf = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	while (s1[idx])
	{
		buf[idx] = s1[idx];
		idx++;
	}
	buf[idx] = '\0';
	return (buf);
}
