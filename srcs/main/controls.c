/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinlee <sinlee@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:32:15 by sinlee            #+#    #+#             */
/*   Updated: 2024/01/20 14:57:54 by sinlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "controls.h"
#include "fdf.h"

static int	handle_mouse_scroll(int button, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (button == 5)
	{
		if (fdf->camera.scale > 2)
			fdf->camera.scale = fdf->camera.scale / 1.5;
	}
	if (button == 4)
		fdf->camera.scale = fdf->camera.scale * 1.5;
	draw(fdf, true);
	return (0);
}

// Add this function to handle mouse button press events
int	handle_mouse(int button, int x, int y, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (button == MOUSE_RIGHT_CLICK)
	{
		fdf->mouse->state = !fdf->mouse->state;
		fdf->mouse->x = x;
		fdf->mouse->y = y;
	}
	else if (button == MOUSE_SCROLL_UP || button == MOUSE_SCROLL_DOWN)
		handle_mouse_scroll(button, param);
	else if (button == MOUSE_LEFT_CLICK)
	{
		fdf->camera.offset_x = x - (fdf->window->width - MENU_WIDTH) / 2;
		fdf->camera.offset_y = y - fdf->window->height / 2;
		draw(fdf, true);
	}
	else
		fdf->mouse->state = 0;
	return (0);
}

// Add this function to handle mouse motion events
int	handle_mouse_motion(int x, int y, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (fdf->mouse->state == 1)
	{
		fdf->camera.alpha += (y - fdf->mouse->y) * 0.01;
		fdf->camera.gamma -= (x - fdf->mouse->x) * 0.01;
		fdf->mouse->x = x;
		fdf->mouse->y = y;
		draw(fdf, true);
	}
	return (0);
}
