/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejikim <yejikim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 13:44:51 by mcha              #+#    #+#             */
/*   Updated: 2022/05/27 22:02:01 by yejikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_free_ptr(void **ptr)
{
	if (*ptr)
		free(*ptr);
	*ptr = NULL;
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*buf;
	int		len_s1;
	int		len_s2;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1 || !s2)
	{
		if (!s1)
			return (ft_strdup_gnl(s2));
		else
			return (ft_strdup_gnl(s1));
	}
	len_s1 = ft_strlen_gnl(s1);
	len_s2 = ft_strlen_gnl(s2);
	buf = (char *)malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	ft_strlcpy_gnl(buf, s1, len_s1 + 1);
	ft_free_ptr((void **)(&s1));
	ft_strlcpy_gnl(buf + len_s1, s2, len_s2 + 1);
	return (buf);
}

size_t	ft_strlen_gnl(const char *s)
{
	size_t	cnt;

	cnt = 0;
	while (*s)
	{
		cnt++;
		s++;
	}
	return (cnt);
}

size_t	ft_strlcpy_gnl(char *dst, const char *src, size_t dstsize)
{
	size_t	idx;

	idx = 0;
	if (dstsize != 0)
	{
		while (idx + 1 < dstsize && src[idx])
		{
			dst[idx] = src[idx];
			idx++;
		}
		dst[idx] = '\0';
	}
	return (ft_strlen_gnl(src));
}

char	*ft_strdup_gnl(char *s1)
{
	char	*buf;
	int		idx;

	idx = 0;
	buf = (char *)malloc((ft_strlen_gnl(s1) + 1) * sizeof(char));
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
