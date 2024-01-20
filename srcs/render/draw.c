#include "colors.h"
#include "fdf.h"

// e_point => end_point
// s_point => start_point
void	draw_line(t_fdf *fdf, t_point s_point, t_point e_point, int color)
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;
	int	intensity;
	int	pixel_color;

	dx = abs(e_point.x - s_point.x);
	dy = abs(e_point.y - s_point.y);
	sx = (s_point.x < e_point.x) ? 1 : -1;
	sy = (s_point.y < e_point.y) ? 1 : -1;
	err = dx - dy;
	// just x and y
	// printf("s_point.x = %d, s_point.y = %d\n", s_point.x, s_point.y);
	// printf("e_point.x = %d, e_point.y = %d\n", e_point.x, e_point.y);
	if (fdf->vars->save)
	{
		fdf->prev_map[fdf->vars->index].s_point = s_point;
		fdf->prev_map[fdf->vars->index].e_point = e_point;
		fdf->vars->index++;
	}
	while (1)
	{
		if (s_point.x >= MENU_WIDTH && s_point.x < fdf->window->width && s_point.y >= 0
			&& s_point.y < fdf->window->height)
		{
			// intensity = 255 * (err / (float)dx);
			// pixel_color = color + (intensity << 24);
			*(int *)(fdf->buffer + (s_point.y * fdf->window->width + s_point.x) * (fdf->bpp
						/ 8)) = color;
		}
		if (s_point.x == e_point.x && s_point.y == e_point.y)
			break ;
		e2 = 2 * err;
		if (e2 > -dy)
		{
			err -= dy;
			s_point.x += sx;
		}
		if (e2 < dx)
		{
			err += dx;
			s_point.y += sy;
		}
	}
}

void	calculation(t_fdf *fdf, int custom_color, bool isometric)
{
	fdf->vars->cur_y = 0;
	fdf->vars->save = true;
	fdf->vars->index = 0;
	while (fdf->vars->cur_y < fdf->height)
	{
		fdf->vars->cur_x = 0;
		while (fdf->vars->cur_x < fdf->width)
		{
			if (fdf->vars->cur_x < fdf->width - 1)
				draw_line(fdf, projection(fdf->vars->cur_x, fdf->vars->cur_y, fdf),
					projection(fdf->vars->cur_x + 1, fdf->vars->cur_y, fdf),
					fdf->map[fdf->vars->cur_y][fdf->vars->cur_x].color);
			if (fdf->vars->cur_y < fdf->height - 1)
				draw_line(fdf, projection(fdf->vars->cur_x, fdf->vars->cur_y, fdf),
					projection(fdf->vars->cur_x, fdf->vars->cur_y + 1, fdf),
					fdf->map[fdf->vars->cur_y][fdf->vars->cur_x].color);
			fdf->vars->cur_x++;
		}
		fdf->vars->cur_y++;
	}
}

// #FIX_NORMINETTE
void	draw(t_fdf *fdf, bool clear)
{
	clear_object(fdf, BACKGROUND);
	fdf->is_iso = true;
	calculation(fdf, 1, false);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
	print_menu(fdf);
}
