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
				printf("(%d, 0x%06X) ", fdf->map[y][x].z, fdf->map[y][x].color);
			x++;
		}
		printf("\n");
		y++;
	}
	printf("==========GRID==========\n");
}