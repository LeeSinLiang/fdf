/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinlee <sinlee@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 10:09:08 by sinlee            #+#    #+#             */
/*   Updated: 2024/01/20 15:33:32 by sinlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(int *y, int *z, double alpha)
{
	int	prev_y;

	prev_y = *y;
	*y = prev_y * cos(alpha) + *z * sin(alpha);
	*z = -prev_y * sin(alpha) + *z * cos(alpha);
}

void	rotate_y(int *x, int *z, double beta)
{
	int	prev_x;

	prev_x = *x;
	*x = prev_x * cos(beta) + *z * sin(beta);
	*z = -prev_x * sin(beta) + *z * cos(beta);
}

void	rotate_z(int *x, int *y, double gamma)
{
	int	prev_x;
	int	prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = prev_x * cos(gamma) - prev_y * sin(gamma);
	*y = prev_x * sin(gamma) + prev_y * cos(gamma);
}

void	isometric(t_point *point, t_fdf *fdf)
{
	int	prev_x;
	int	prev_y;

	prev_x = point->x;
	prev_y = point->y;
	point->x = (point->x - point->y) * cos(fdf->camera.iso_angle);
	point->y = -point->z + (point->x + point->y) * sin(fdf->camera.iso_angle);
}

t_point	projection(int x, int y, t_fdf *fdf)
{
	t_point	point;

	calc_reposition(fdf, x, y, &point);
	point.z = fdf->map[y][x].z * (fdf->camera.scale / fdf->camera.z_division);
	rotate_x(&point.y, &point.z, fdf->camera.alpha);
	rotate_y(&point.x, &point.z, fdf->camera.beta);
	rotate_z(&point.x, &point.y, fdf->camera.gamma);
	if (fdf->is_iso == true)
		isometric(&point, fdf);
	point.x += (fdf->window->width - MENU_WIDTH) / 2 + fdf->camera.offset_x
		+ MENU_WIDTH;
	point.y += (fdf->window->height + fdf->height * fdf->camera.scale) / 2
		+ fdf->camera.offset_y;
	point.color = fdf->map[y][x].color;
	return (point);
}
