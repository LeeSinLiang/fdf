#include "fdf.h"

void	parse_line(char *line, t_fdf *fdf, int y)
{
	int		x;
	char	**values;
	t_point	point;
	char	*comma_position;

	x = 0;
	values = ft_split(line, ' ');
	while (*values)
	{
		if (**values == '\n')
			break ;
		point.x = x;
		point.y = y;
		point.color = 0xABCDEF;
		comma_position = strchr(*values, ',');
		if (comma_position != NULL)
		{
			*comma_position = '\0'; // Separate z-coordinate and color
			point.z = atoi(*values);
			point.color = strtol(comma_position + 1, NULL, 0);
		}
		else
			point.z = atoi(*values);
		fdf->map[y][x] = point;
		values++;
		x++;
	}
	// free(values);
}

void	parse_fdf(char *file_path, t_fdf *fdf)
{
	int		fd;
	char	*line;
	int		y;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
	{
		fprintf(stderr, "Error opening file: %s\n", file_path);
		exit(EXIT_FAILURE);
	}
	y = 0;
	line = get_next_line(fd);
	while (line)
	{
		// Resize the map to accommodate a new row
		fdf->map = realloc(fdf->map, (y + 1) * sizeof(t_point *));
		if (fdf->map == NULL)
		{
			fprintf(stderr, "Memory allocation error\n");
			exit(EXIT_FAILURE);
		}
		// Allocate memory for the current row
		if (ft_strchr(line, '\n'))
			fdf->width = count_strings(line, ' ') - 1;
		else
			fdf->width = count_strings(line, ' ');
		fdf->map[y] = malloc(fdf->width * sizeof(t_point));
		if (fdf->map[y] == NULL)
		{
			fprintf(stderr, "Memory allocation error\n");
			exit(EXIT_FAILURE);
		}
		// Parse the line and fill the map data
		printf("line: %s\n", line);
		parse_line(line, fdf, y);
		free(line);
		y++;
		line = get_next_line(fd);
	}
	fdf->height = y;
	close(fd);
}

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
}

bool initialize(t_fdf *fdf)
{
	fdf->img = NULL;
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "FDF");

    fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	fdf->buffer = mlx_get_data_addr(fdf->img, &fdf->bpp, &fdf->lines, &fdf->endian);
	if (fdf->win == NULL)
		return (false);
	fdf->map = NULL;
	fdf->scale = 20;
	fdf->offset_x = 0;
	fdf->offset_y = 0;
	fdf->start_x = WIDTH / 2;
	fdf->start_y = HEIGHT / 2;
	mlx_hook(fdf->win, 4, 1L<<2, handle_mouse_scroll, fdf);
	return (true);
}

int	main(int argc, char **argv)
{
	t_fdf	fdf;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <fdf_file>\n", argv[0]);
		return (EXIT_FAILURE);
	}
	initialize(&fdf);

	parse_fdf(argv[1], &fdf);
	// draw_top_down_view(&fdf);
	draw(&fdf);
	printf("endian: %d\n", fdf.endian);
	mlx_loop(fdf.mlx);
	free_fdf(&fdf);
	return (EXIT_SUCCESS);
}
