/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 00:32:39 by mcha              #+#    #+#             */
/*   Updated: 2022/05/25 22:49:20 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	// printf("s : %s\n", s);
	// printf("start : %u\n", start);
	// printf("len : %zu\n", len);
	char	*ret;
	size_t	str_len;
	size_t	end;

	str_len = ft_strlen(s);
	if (str_len < start + len)
		end = str_len;
	else
		end = start + len;
	if (end < start)
		end = start;
	ret = malloc(sizeof(char) * (end - start + 1));
	if (ret == NULL)
		return (NULL);
	ft_memcpy(ret, s + start, end - start);
	ret[end - start] = '\0';
	return (ret);
}
