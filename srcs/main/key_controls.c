/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_controls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinlee <sinlee@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 14:58:14 by sinlee            #+#    #+#             */
/*   Updated: 2024/01/20 14:58:15 by sinlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	handle_iso_key(t_fdf *fdf)
{
	fdf->is_iso = true;
	setup_camera(fdf);
}

void	handle_zoom_key(t_fdf *fdf, int keycode)
{
	if ((keycode == PL_KEY || keycode == 0x00003d)
		&& fdf->camera.z_division > 0.1)
		fdf->camera.z_division -= 0.1;
	if (keycode == MN_KEY && fdf->camera.z_division)
		fdf->camera.z_division += 0.1;
}

void	handle_rotation_key(t_fdf *fdf, int keycode)
{
	if (keycode == K1_KEY)
		fdf->camera.alpha += 0.05;
	else if (keycode == K2_KEY)
		fdf->camera.alpha -= 0.05;
	else if (keycode == K3_KEY)
		fdf->camera.beta += 0.05;
	else if (keycode == K4_KEY)
		fdf->camera.beta -= 0.05;
	else if (keycode == K5_KEY)
		fdf->camera.gamma += 0.05;
	else if (keycode == K6_KEY)
		fdf->camera.gamma -= 0.05;
	else if (keycode == K7_KEY)
		fdf->camera.iso_angle += 0.05;
	else if (keycode == K8_KEY)
		fdf->camera.iso_angle -= 0.05;
}

void	handle_t_key(t_fdf *fdf)
{
	fdf->is_iso = false;
	draw(fdf, true);
}

int	handle_key(int keycode, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (keycode == I_KEY)
		handle_iso_key(fdf);
	else if (keycode == ESC_KEY)
		free_fdf(fdf);
	else if (keycode == R_KEY)
		setup_camera(fdf);
	else if (keycode == T_KEY)
		handle_t_key(fdf);
	else
		handle_rotation_key(fdf, keycode);
	handle_zoom_key(fdf, keycode);
	draw(fdf, true);
	return (0);
}
