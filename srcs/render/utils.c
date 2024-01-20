/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinlee <sinlee@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 14:58:59 by sinlee            #+#    #+#             */
/*   Updated: 2024/01/20 15:21:09 by sinlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	set_color(char *buffer, int endian, int color, int alpha)
{
	if (endian == 1)
	{
		buffer[0] = (color >> 24);
		buffer[1] = (color >> 16) & 0xFF;
		buffer[2] = (color >> 8) & 0xFF;
		buffer[3] = (color) & 0xFF;
	}
	else
	{
		buffer[0] = (color) & 0xFF;
		buffer[1] = (color >> 8) & 0xFF;
		buffer[2] = (color >> 16) & 0xFF;
		buffer[3] = alpha;
	}
}

bool	clear_object(t_fdf *fdf, int color)
{
	int	x;

	x = 0;
	fdf->vars->save = false;
	while (x < fdf->vars->index)
	{
		draw_line(fdf, fdf->prev_map[x].s_point, fdf->prev_map[x].e_point,
			color);
		x++;
	}
}

bool	set_background(t_fdf *fdf, int color, int range_x[2], int range_y[2])
{
	int	x;
	int	y;

	y = range_y[0];
	while (y < range_y[1])
	{
		x = range_x[0];
		while (x < range_x[1])
		{
			set_color(fdf->buffer + (y * fdf->lines) + (x * 4), fdf->endian,
				color, 0);
			x++;
		}
		y++;
	}
	return (true);
}
