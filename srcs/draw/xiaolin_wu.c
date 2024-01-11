#include "fdf.h"

void draw_line(t_fdf *fdf, int x0, int y0, int x1, int y1, int color)
{
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;
    int err = dx - dy;
    int e2;
    int x = x0;
    int y = y0;

    while (1)
    {
        int intensity = 255 * (err / (float)dx);
        int pixel_color = color + (intensity << 24);

		// Write color value byte-by-byte into the pixel array
		*(int *)(fdf->buffer + (y * WIDTH + x) * (fdf->bpp / 8)) = pixel_color;

        if (x == x1 && y == y1)
            break;

        e2 = 2 * err;
        if (e2 > -dy)
        {
            err -= dy;
            x += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            y += sy;
        }
    }
}

void calculation(t_fdf *fdf, int custom_color)
{
    int x, y;
    int center_x = fdf->start_x;
    int center_y = fdf->start_y;

    y = 0;
    printf("Draw scale: %d\n", fdf->scale);
    set_background(fdf, 0x000000);
    while (y < fdf->height)
    {
        x = 0;
        while (x < fdf->width)
        {
            if (custom_color != 0)
                custom_color = fdf->map[y][x].color;
            // Center and scale the coordinates
            int x0 = center_x + (x - fdf->width / 2) * fdf->scale;
            int y0 = center_y + (y - fdf->height / 2) * fdf->scale;

            if (x < fdf->width - 1)
            {
                int x1 = center_x + (x + 1 - fdf->width / 2) * fdf->scale;
                int y1 = center_y + (y - fdf->height / 2) * fdf->scale;
                draw_line(fdf, x0, y0, x1, y1, custom_color);
            }
            if (y < fdf->height - 1)
            {
                int x2 = center_x + (x - fdf->width / 2) * fdf->scale;
                int y2 = center_y + (y + 1 - fdf->height / 2) * fdf->scale;
                draw_line(fdf, x0, y0, x2, y2, custom_color);
            }
            x++;
        }
        y++;
    }
    printf("MLX: %p WIN: %p, img: %p\n", fdf->mlx, fdf->win, fdf->img);
    mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
}

void draw(t_fdf *fdf)
{
    calculation(fdf, 1);
}