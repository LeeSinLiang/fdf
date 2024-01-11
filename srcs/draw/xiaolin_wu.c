#include "fdf.h"

void swap(double *a, double *b)
{
    double tmp = *a;
    *a = *b;
    *b = tmp;
}

void	fill_img(t_fdf *fdf, int x, int y, double a)
{
	char	*color;
	int		alpha;
	int		red;
	int		green;
	int		blue;

	if (a == 0)
		return ;
	if ((y * WIDTH + x) * 4 - 1 < 0 ||
		(y * WIDTH + x) * 4 - 1 > HEIGHT * WIDTH * 4)
		return ;
	color = fdf->buffer[(y * WIDTH + x) * 4 - 1];
	alpha = 255 * a;
	red = 255;
	green = 255;
	blue = 255;
	*color++ = alpha;
	*color++ = red;
	*color++ = green;
	*color = blue;
}

double frc_part(double nbr)
{
    return (ceil(nbr) - nbr);
}

void	swap(double *a, double *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

double	frc_part(double nbr)
{
	return (ceil(nbr) - nbr);
}

void	draw_w_slope(t_fdf *fdf, double x, double y)
{
	if (fdf->slope >= 0)
	{
		fill_img(fdf, floor(x), y, 1 - frc_part(y));
		fill_img(fdf, floor(x) + 1, y, frc_part(y));
	}
	else if (fdf->slope < 0)
	{
		fill_img(fdf, floor(x), y, 1 - frc_part(y));
		fill_img(fdf, floor(x) - 1, y, frc_part(y));
	}
}

void	draw_btw_dots(t_fdf *fdf, t_vector p1, t_vector p2)
{
	while (p1.x <= p2.x)
	{
		if (fdf->steep)
			draw_w_slope(fdf, p1.y, p1.x);
		else
			draw_w_slope(fdf, p1.x, p1.y);
		p1.y += fdf->slope;
		p1.x++;
	}
}

void	draw_line(t_fdf *fdf, t_vector p1, t_vector p2)
{
	double	dx;
	double	dy;

	fdf->steep = fabs(p1.y - p2.y) > fabs(p1.x - p2.x) ? 1 : 0;
	if (fdf->steep)
	{
		swap(&p1.x, &p1.y);
		swap(&p2.x, &p2.y);
	}
	if (p2.x < p1.x)
	{
		swap(&p1.x, &p2.x);
		swap(&p1.y, &p2.y);
	}
	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	fdf->slope = dx == 0 ? 1 : dy / dx;
	draw_btw_dots(fdf, p1, p2);
}

void	draw(t_fdf *fdf)
{
	int	i;
	int	j;

	i = 0;
	while (i < fdf->row)
	{
		j = 0;
		while (j < fdf->col)
		{
			if (i < fdf->row - 1)
				draw_line(fdf, fdf->vector[i][j], fdf->vector[i + 1][j]);
			if (j < fdf->col - 1)
				draw_line(fdf, fdf->vector[i][j], fdf->vector[i][j + 1]);
			j++;
		}
		i++;
	}
}