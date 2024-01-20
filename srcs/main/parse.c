/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinlee <sinlee@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 15:14:35 by sinlee            #+#    #+#             */
/*   Updated: 2024/01/20 15:40:53 by sinlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "printf.h"

int	count_lines(char *file_path)
{
	int		fd;
	char	*line;
	int		lines;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
	{
		fprintf(stderr, "Error opening file: %s\n", file_path);
		exit(EXIT_FAILURE);
	}
	lines = 0;
	line = get_next_line(fd);
	while (line)
	{
		lines++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (lines);
}

void	parse_line(char *line, t_fdf *fdf, int y)
{
	int		x;
	char	**values;
	t_point	point;
	char	*comma_position;

	x = 0;
	values = ft_split(line, ' ');
	fdf->malloced.lines = values;
	while (*values)
	{
		if (**values == '\n')
			break ;
		point.x = x;
		point.y = y;
		point.color = 0xABCDEF;
		comma_position = ft_strchr(*values, ',');
		if (comma_position != NULL)
		{
			*comma_position = '\0';
			point.z = ft_atoi(*values);
			point.color = ft_strtol(comma_position + 1, NULL, 0);
		}
		else
			point.z = ft_atoi(*values);
		fdf->map[y][x] = point;
		values++;
		x++;
	}
	x = -1;
	while (fdf->malloced.lines[++x] != NULL)
		free(fdf->malloced.lines[x]);
	free(fdf->malloced.lines);
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
	fdf->height = count_lines(file_path);
	fdf->map = malloc(fdf->height * sizeof(t_point *));
	line = get_next_line(fd);
	while (line)
	{
		if (line[ft_strlen(line) - 2] == ' ')
			fdf->width = count_strings(line, ' ') - 1;
		else
			fdf->width = count_strings(line, ' ');
		fdf->map[y] = malloc(fdf->width * sizeof(t_point));
		if (fdf->map[y] == NULL)
		{
			fprintf(stderr, "Memory allocation error\n");
			exit(EXIT_FAILURE);
		}
		parse_line(line, fdf, y);
		free(line);
		y++;
		line = get_next_line(fd);
	}
	close(fd);
}
