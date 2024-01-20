/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinlee <sinlee@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:00:23 by sinlee            #+#    #+#             */
/*   Updated: 2024/01/20 15:44:00 by sinlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "controls.h"
# include "ft_printf.h"
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define PI 3.14159265359
# define ISO_ANGLE 0.523599
# define WIDTH 1200
# define HEIGHT 1200
# define MENU_WIDTH 250

typedef struct s_point
{
	int			x;
	int			y;
	int			z;
	int			color;
}				t_point;

typedef struct s_fpoint
{
	float		x;
	float		y;
	float		z;
}				t_fpoint;

typedef struct s_image
{
	void		*img;
	char		*buffer;
	int			bpp;
	int			size_line;
	int			endian;
}				t_image;

typedef struct s_camera
{
	int			zoom;
	double		alpha;
	double		beta;
	double		gamma;
	int			offset_x;
	int			offset_y;
	int			offset_z;
	int			scale;
	float		z_division;
	double		iso_angle;
}				t_camera;

typedef struct s_vars
{
	int			cur_x;
	int			cur_y;
	bool		save;
	int			index;
}				t_vars;

typedef struct s_mouse
{
	int			x;
	int			y;
	int			state;
}				t_mouse;

typedef struct s_line
{
	t_point		s_point;
	t_point		e_point;
}				t_line;

typedef struct s_window
{
	void		*mlx;
	void		*win;
	int			height;
	int			width;
}				t_window;

typedef struct s_malloced
{
	char		**lines;
}				t_malloced;

typedef struct s_fdf
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*buffer;
	int			bpp;
	int			lines;
	int			endian;
	int			center_x;
	int			center_y;
	t_window	*window;
	t_point		**map;
	t_line		*prev_map;
	t_malloced	malloced;
	int			width;
	int			height;
	t_camera	camera;
	t_mouse		*mouse;
	t_vars		*vars;
	bool		is_iso;
}				t_fdf;

void			parse_fdf(char *file_path, t_fdf *fdf);
void			free_fdf(t_fdf *fdf);
void			draw(t_fdf *fdf, bool clear);
void			draw_line(t_fdf *fdf, t_point s_point, t_point e_point,
					int color);
void			calc_reposition(t_fdf *fdf, int x, int y, t_point *point);
t_point			projection(int x, int y, t_fdf *fdf);

void			print_menu(t_fdf *fdf);
void			print_map(t_fdf *fdf, bool print_coords);
void			print_prev_map(t_fdf *fdf);
void			print_buffer(t_fdf *fdf);

bool			initialize(t_fdf *fdf);
bool			initialize(t_fdf *fdf);
void			setup_mlx(t_fdf *fdf);
void			setup_camera(t_fdf *fdf);
void			setup_mouse(t_fdf *fdf);
void			setup_vars(t_fdf *fdf);
void			setup_hooks(t_fdf *fdf);

bool			clear_object(t_fdf *fdf, int color);
bool			set_background(t_fdf *fdf, int color, int range_x[2],
					int range_y[2]);

int				handle_mouse(int button, int x, int y, void *param);
int				handle_mouse_motion(int x, int y, void *param);
int				handle_key(int keycode, void *param);

long int		ft_strtol(const char *str, char **endptr, int base);

int				ft_min(int a, int b);
void			print_exit(char *str, t_fdf *fdf);

#endif
