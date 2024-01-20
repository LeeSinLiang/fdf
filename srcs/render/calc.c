#include "fdf.h"

// Center and scale the coordinates
void calc_reposition(t_fdf *fdf, int x, int y, t_point *point)
{
    point->x = x;
    point->y = y;
    point->z = fdf->map[y][x].z;
    point->color = fdf->map[y][x].color;
    point->x *= fdf->camera.scale;
    point->y *= fdf->camera.scale;
    point->x = (point->x - (fdf->camera.scale * fdf->width / 2));
    point->y = (point->y - (fdf->camera.scale * fdf->height / 2));
}
