/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinlee <sinlee@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:30:59 by sinlee            #+#    #+#             */
/*   Updated: 2024/01/20 16:35:47 by sinlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

bool	initialize(t_fdf *fdf)
{
	setup_mlx(fdf);
	setup_camera(fdf);
	setup_mouse(fdf);
	fdf->vars = malloc(sizeof(t_vars));
	setup_hooks(fdf);
	return (true);
}

void	setup_mlx(t_fdf *fdf)
{
	fdf->window = malloc(sizeof(t_window));
	fdf->mlx = mlx_init();
	// mlx_get_screen_size(fdf->mlx, &fdf->window->width, &fdf->window->height);
	fdf->window->width = WIDTH;
	fdf->window->height = HEIGHT;
	ft_printf("Screen size: %d x %d\n", fdf->window->width,
		fdf->window->height);
	fdf->win = mlx_new_window(fdf->mlx, fdf->window->width, fdf->window->height,
			"FDF");
	fdf->img = mlx_new_image(fdf->mlx, fdf->window->width, fdf->window->height);
	fdf->buffer = mlx_get_data_addr(fdf->img, &fdf->bpp, &fdf->lines,
			&fdf->endian);
	fdf->map = NULL;
}

void	setup_camera(t_fdf *fdf)
{
	fdf->camera.scale = 1;
	fdf->camera.offset_x = 0;
	fdf->camera.offset_y = 0;
	fdf->center_x = ((fdf->window->width - MENU_WIDTH) / 2) + MENU_WIDTH;
	fdf->center_y = fdf->window->height / 2;
	fdf->camera.alpha = 0;
	fdf->camera.beta = 0;
	fdf->camera.gamma = 0;
	fdf->camera.z_division = 1;
	fdf->camera.iso_angle = ISO_ANGLE;
}

void	setup_mouse(t_fdf *fdf)
{
	fdf->mouse = malloc(sizeof(t_mouse));
	fdf->mouse->x = 0;
	fdf->mouse->y = 0;
	fdf->mouse->state = 0;
	fdf->is_iso = false;
}

void	setup_hooks(t_fdf *fdf)
{
	mlx_hook(fdf->win, 4, 1L << 2, handle_mouse, fdf);
	mlx_hook(fdf->win, 6, 1L << 6, handle_mouse_motion, fdf);
}
