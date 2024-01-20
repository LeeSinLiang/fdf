/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinlee <sinlee@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:37:55 by sinlee            #+#    #+#             */
/*   Updated: 2024/01/13 17:07:29 by sinlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"
#include "fdf.h"

void	print_menu(t_fdf *fdf)
{
	int		y;
	void	*mlx;
	void	*win;

	y = 0;
	mlx = fdf->mlx;
	win = fdf->win;
	set_background(fdf, MENU_BACKGROUND, (int [2]){0, MENU_WIDTH},
		(int [2]){0, fdf->window->height});
	mlx_string_put(mlx, win, 65, y += 20, TEXT_COLOR_WHITE, "How to Use");
	mlx_string_put(mlx, win, 15, y += 35, TEXT_COLOR_WHITE,
		"Zoom: Scroll");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR_WHITE, "Move: Arrows");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR_WHITE, "Altitude: +/-");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR_WHITE,
		"Rotate: Press & Move");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR_WHITE, "Projection");
	mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR_WHITE, "ISO: I Key");
	mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR_WHITE, "Parallel: P Key");
}