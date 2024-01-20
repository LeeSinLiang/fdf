/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinlee <sinlee@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:53:31 by sinlee            #+#    #+#             */
/*   Updated: 2023/05/31 10:10:15 by sinlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

char				*ft_strjoin_gnl(char *s1, char *s2);
int					ft_strchr_gnl(char *s, char c);
size_t				gnl_strlen(const char *str);
int					ft_find_newline_pos(char *str);
char				*get_next_line(int fd);
void				print_debug(char *str);

#endif