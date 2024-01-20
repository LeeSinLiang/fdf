/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinlee <sinlee@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 15:14:03 by sinlee            #+#    #+#             */
/*   Updated: 2024/01/20 15:14:04 by sinlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_map(t_fdf *fdf, bool print_coords)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	printf("==========GRID==========\n");
	while (y < fdf->height)
	{
		x = 0;
		while (x < fdf->width)
		{
			if (print_coords)
				printf("(%d, %d, %d, %06X) ", fdf->map[y][x].x,
					fdf->map[y][x].y, fdf->map[y][x].z, fdf->map[y][x].color);
			else
				printf("%d ", fdf->map[y][x].z);
			x++;
		}
		printf("\n");
		y++;
	}
	printf("==========GRID==========\n");
}
