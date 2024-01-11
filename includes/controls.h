/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinlee <sinlee@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:41:45 by sinlee            #+#    #+#             */
/*   Updated: 2024/01/11 17:55:37 by sinlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROLS_H
# define CONTROLS_H

# define SCALE_FACTOR_MIN 1   // Minimum scale factor
# define SCALE_FACTOR_MAX 100 // Maximum scale factor

typedef struct s_mouse
{
	int	prev_x;
	int	prev_y;
}		t_mouse;

extern t_mouse	*g_mouse;

#endif // CONTROLS_H
