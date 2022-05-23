/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 13:44:46 by mcha              #+#    #+#             */
/*   Updated: 2022/05/23 14:21:46 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include "../libft/libft.h"

static void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*arr;
	unsigned char	src;
	size_t			i;

	arr = b;
	src = c;
	i = 0;
	while (i < len)
	{
		arr[i] = src;
		i++;
	}
	return (b);
}

static int	ft_newline_chk(char *target)
{
	int	idx;

	idx = 0;
	while (target[idx])
	{
		if (target[idx] == '\n')
			return (idx);
		idx++;
	}
	return (-1);
}

static char	*ft_do_split(char **ptr, char **buf, int idx)
{
	char	*tmp;
	char	*line;

	ft_free_ptr((void **)buf);
	line = ft_strdup(*ptr);
	line[idx + 1] = '\0';
	tmp = *ptr;
	*ptr = ft_strdup(*ptr + idx + 1);
	free(tmp);
	return (line);
}

static char	*return_all(char **ptr, char **buf, int sz)
{
	char	*tmp;
	char	*line;

	if (!(*ptr))
	{
		ft_free_ptr((void **)buf);
		return (NULL);
	}
	else if (**ptr && sz < 1)
	{
		if (ft_newline_chk(*ptr) >= 0)
			return (ft_do_split(ptr, buf, ft_newline_chk(*ptr)));
		ft_free_ptr((void **)buf);
		line = ft_strdup(*ptr);
		tmp = *ptr;
		*ptr = ft_strdup(*ptr + ft_strlen(*ptr));
		free(tmp);
		return (line);
	}
	else if (!(**ptr) && sz < 1)
		ft_free_ptr((void **)ptr);
	ft_free_ptr((void **)buf);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*ptr[200000];
	int			r_size;
	char		*buf;
	int			cut_idx;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	while (TRUE)
	{
		buf = ft_memset(buf, 0, BUFFER_SIZE + 1);
		r_size = read(fd, buf, BUFFER_SIZE);
		if (r_size < 1)
			break ;
		ptr[fd] = ft_strjoin(ptr[fd], buf);
		cut_idx = ft_newline_chk(ptr[fd]);
		if (cut_idx >= 0)
			return (ft_do_split((&ptr[fd]), &buf, cut_idx));
	}
	return (return_all(&ptr[fd], &buf, r_size));
}
