/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinlee <sinlee@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:00:23 by sinlee            #+#    #+#             */
/*   Updated: 2024/01/11 20:51:01 by sinlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "controls.h"
#include "libft.h"
#include <fcntl.h>
#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

# define WIDTH 1200
# define HEIGHT 1200

typedef struct s_point
{
	int		x;
	int		y;
	int		z;
	int		color;
}			t_point;

typedef struct s_image {
	void	*img;
	char	*buffer;
	int		bpp;
	int		size_line;
	int		endian;
}	t_image;

typedef struct s_vars {
	void	*mlx;
	void	*win;
}	t_vars;

typedef struct	s_vector
{
	double		x;
	double		y;
	double		z;
	int			c;
}				t_vector;

typedef struct s_fdf
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*buffer;
	int		bpp;
	int		lines;
	int		endian;
	t_point	**map;
	int		width;
	int		height;

	int		scale;
	int		start_x;
	int		start_y;
	int		offset_x;
	int		offset_y;

	int		steep;
	double		slope;

	int		row;
	int		col;
	t_vector	**vector;
}			t_fdf;

void draw(t_fdf *fdf);


void	set_color(char *buffer, int endian, int color, int alpha);
bool set_background(t_fdf *fdf, int color);


int handle_mouse_scroll(int button, int x, int y, void *param);
int 	handle_mouse_move(int x, int y, t_fdf *fdf);
int 	handle_mouse_release(int button, int x, int y, t_fdf *fdf);

#endif