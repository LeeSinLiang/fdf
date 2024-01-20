/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinlee <sinlee@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:32:07 by sinlee            #+#    #+#             */
/*   Updated: 2024/01/20 15:19:28 by sinlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"
#include "fdf.h"
#include <stdio.h>

void	free_fdf(t_fdf *fdf)
{
	int	y;

	y = 0;
	while (y < fdf->height)
	{
		free(fdf->map[y]);
		y++;
	}
	free(fdf->map);
	free(fdf->window);
	free(fdf->vars);
	exit(EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_fdf	fdf;

	if (argc != 2)
	{
		ft_printf("Usage: %s <fdf_file>\n", argv[0]);
		return (EXIT_FAILURE);
	}
	initialize(&fdf);
	ft_printf("Parsing file...\n");
	parse_fdf(argv[1], &fdf);
	if (fdf.width < 2 || fdf.height < 2)
	{
		ft_printf("Error: Invalid map\n");
		free_fdf(&fdf);
	}
	fdf.camera.scale = ft_min((fdf.window->width - MENU_WIDTH) / fdf.width / 2, 
			fdf.window->height / fdf.height / 2);
	fdf.prev_map = ft_calloc((fdf.window->width * fdf.window->height),
			sizeof(t_line));
	set_background(&fdf, BACKGROUND, (int [2]){MENU_WIDTH, fdf.window->width},
		(int [2]){0, fdf.window->height});
	draw(&fdf, false);
	mlx_key_hook(fdf.win, handle_key, &fdf);
	mlx_loop(fdf.mlx);
	free_fdf(&fdf);
	return (EXIT_SUCCESS);
}
