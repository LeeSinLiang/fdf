# include "controls.h"
# include "fdf.h"
int handle_mouse_scroll(int button, int x, int y, void *param)
{
	t_fdf *fdf;

	(void)x;
	(void)y;
	fdf = (t_fdf *)param;
	
	if (button == 5)
	{
		if (fdf->scale > 2)
			fdf->scale = fdf->scale / 1.5;
	}
	if (button == 4)
		fdf->scale = fdf->scale * 1.5;
	draw(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
	return (0);
}

// int handle_mouse_move(int x, int y, t_fdf *fdf)
// {
// 	if (g_mouse->prev_x == -1)
// 		g_mouse->prev_x = x;
// 	if (g_mouse->prev_y == -1)
// 		g_mouse->prev_y = y;

// 	fdf->offset_x += x - g_mouse->prev_x;
// 	fdf->offset_y += y - g_mouse->prev_y;

// 	g_mouse->prev_x = x;
// 	g_mouse->prev_y = y;

// 	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
// 	draw_lines(fdf);
// 	return (0);
// }

// int handle_mouse_release(int button, int x, int y, t_fdf *fdf)
// {
// 	(void)button;
// 	(void)x;
// 	(void)y;
// 	g_mouse->prev_x = -1;
// 	g_mouse->prev_y = -1;

// 	return (0);
// }

