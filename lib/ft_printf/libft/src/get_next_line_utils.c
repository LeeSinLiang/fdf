/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinlee <sinlee@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:49:18 by sinlee            #+#    #+#             */
/*   Updated: 2024/01/12 17:03:26 by sinlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t	gnl_strlen(const char *str)
{
	size_t	len;

	len = 0;
	if (str == 0)
		return (0);
	while (*str++)
		len++;
	return (len);
}

int	ft_strchr_gnl(char *s, char c)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*str;
	int		i;

	i = -1;
	str = malloc(sizeof(char) * (gnl_strlen(s1) + gnl_strlen(s2) + 1));
	if (!str)
		return (0);
	if (s1)
	{
		while (s1[++i])
			str[i] = s1[i];
		i = -1;
	}
	if (s2)
	{
		while (s2[++i])
			str[gnl_strlen(s1) + i] = s2[i];
	}
	free(s2);
	str[gnl_strlen(s1) + i] = '\0';
	free(s1);
	return (str);
}