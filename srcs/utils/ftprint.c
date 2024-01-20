/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinlee <sinlee@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:34:00 by sinlee            #+#    #+#             */
/*   Updated: 2024/01/20 15:43:26 by sinlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"
#include "fdf.h"
#include "utils.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

void	perror_TEXT(char *str)
{
	char	msg[1024];

	ft_snprintf(msg, sizeof(msg), "%s%s%s", RED_TEXT, str, CYAN_TEXT);
	perror(msg);
	ft_printf("%s", RESET_COLOR_TEXT);
}

void	error_exit(char *str, bool is_perror)
{
	char	*msg;

	msg = malloc(1024);
	ft_snprintf(msg, 1024, "%s%s%s", RED_TEXT, str, RESET_COLOR_TEXT);
	if (is_perror)
		perror(msg);
	else
		ft_printf("%s", msg);
	free(msg);
	exit(errno);
}

void	exit_success(void)
{
	ft_printf("%sOui Oui Exit%s\n", BLUE_BOLD_TEXT, RESET_COLOR_TEXT);
	exit(EXIT_SUCCESS);
}

void	print_exit(char *str, t_fdf *fdf)
{
	printf("%s\n", str);
	free_fdf(fdf);
	exit(EXIT_FAILURE);
}
