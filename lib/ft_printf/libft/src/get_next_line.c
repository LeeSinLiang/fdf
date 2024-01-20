/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinlee <sinlee@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:58:36 by sinlee            #+#    #+#             */
/*   Updated: 2024/01/20 14:45:30 by sinlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;

	src_len = gnl_strlen(src);
	if (size == 0)
		return (src_len);
	i = 0;
	while (i < size - 1 && src[i])
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = '\0';
	return (src_len);
}


static char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*substr;

	if (start > gnl_strlen(s))
	{
		substr = malloc(sizeof(char) * 1);
		substr[0] = '\0';
	}
	else
	{
		if (len > gnl_strlen(s + start))
			len = gnl_strlen(s + start);
		if (len == 0)
			return (NULL);
		substr = malloc(sizeof(char) * (len + 1));
		if (substr == 0)
			return (NULL);
		else
			ft_strlcpy(substr, s + start, len + 1);
	}
	return (substr);
}

char	*extract_and_ret(char *str, int mode, char *remain_str)
{
	int		index;
	char	*extract;

	index = ft_strchr_gnl(str, '\n');
	if (index != -1 && index != BUFFER_SIZE - 1)
	{
		if (mode == 1 || mode == 2)
		{
			extract = ft_substr(str, index + 1, gnl_strlen(str) + 1);
			if (remain_str != NULL && gnl_strlen(remain_str) > 0 && mode == 1)
				extract = ft_strjoin_gnl(remain_str, extract);
			free(remain_str);
			return (extract);
		}
		else
			return (ft_substr(str, 0, index + 1));
	}
	else if (gnl_strlen(str) > 0 && mode == 0)
		return (ft_substr(str, 0, gnl_strlen(str) + 1));
	else
	{
		if (mode == 2)
			free(str);
		return (NULL);
	}
}

char	*get_next_line(int fd)
{
	int			read_size;
	char		*buffer;
	static char	*remain[1024];
	char		*buff_all;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_size = 1;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	buff_all = extract_and_ret(remain[fd], 0, remain[fd]);
	remain[fd] = extract_and_ret(remain[fd], 2, remain[fd]);
	while (ft_strchr_gnl(buff_all, '\n') == -1 && read_size != 0)
	{
		read_size = read(fd, buffer, BUFFER_SIZE);
		if (read_size <= 0)
			break ;
		buffer[read_size] = '\0';
		buff_all = ft_strjoin_gnl(buff_all, extract_and_ret(buffer, 0,
					remain[fd]));
		remain[fd] = extract_and_ret(buffer, 1, remain[fd]);
	}
	free(buffer);
	return (buff_all);
}
