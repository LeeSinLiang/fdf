/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinlee <sinlee@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:35:30 by sinlee            #+#    #+#             */
/*   Updated: 2024/01/12 16:27:11 by sinlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stddef.h>
# include <unistd.h>
# include <stdbool.h>
// Your code here
int		ft_snprintf(char *str, size_t size, const char *format, ...);
void	perror_color(char *str);
void	error_exit(char *str, bool is_perror);
void	exit_success(void);

#endif // UTILS_H
