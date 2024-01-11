#include "fdf.h"

void	set_color(char *buffer, int endian, int color, int alpha)
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

bool set_background(t_fdf *fdf, int color)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < HEIGHT) // TODO: optimize this, get x pos
	{
		x = 0;
		while (x < WIDTH)
		{
			set_color(fdf->buffer + (y * fdf->lines) + (x * 4),
				fdf->endian, color, 0);
			x++;
		}
		y++;
	}
	return (true);
}