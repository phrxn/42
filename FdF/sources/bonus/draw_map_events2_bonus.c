/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_events2_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:05:11 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/03/22 13:02:47 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/bonus/draw_map_events_bonus.h"
#include "../../include/bonus/draw_map_bonus.h"
#include "../../include/bonus/fdf_bonus.h"
#include "../../include/bonus/frame_bonus.h"
#include "../../include/bonus/projection_bonus.h"
#include <math.h>

void	apply_ang(t_fdf *fdf, int axis, int ang_value)
{
	double	*actual_angle;

	if (ang_value >= 360 || ang_value <= -360)
		ang_value = (ang_value % 360);
	if (axis == X)
		actual_angle = &fdf->map.ang[X];
	if (axis == Y)
		actual_angle = &fdf->map.ang[Y];
	if (axis == Z)
		actual_angle = &fdf->map.ang[Z];
	*actual_angle += ang_value;
	if (*actual_angle >= 360)
			*actual_angle -= 360;
	if (*actual_angle < 0)
			*actual_angle += 360;
	draw_frame(fdf);
}

/**
 * apply_translation - add or sub center map values.
 *
 * @new_x:	new value to add or sub from center x
 * @new_y:	new value to add or sub from center y
 */
void	apply_translation(t_fdf *fdf, int new_x, int new_y)
{
	fdf->map.center_win[X] += new_x;
	fdf->map.center_win[Y] += new_y;
	draw_frame(fdf);
}

void	apply_projection(t_fdf *fdf, int projection)
{
	fdf->map.projection = projection;
	fdf->map.is_show_negative_z = 1;
	if (fdf->map.projection == PROJ_ISO)
	{
		fdf->map.ang[X] = 30;
		fdf->map.ang[Y] = -30;
		fdf->map.ang[Z] = 35;
	}
	if (fdf->map.projection == PROJ_SPH)
	{
		fdf->map.ang[X] = -90;
		fdf->map.ang[Y] = 0;
		fdf->map.ang[Z] = 0;
		fdf->map.is_show_negative_z = 0;
	}
	if (fdf->map.projection == PROJ_TOP)
	{
		fdf->map.ang[X] = 0;
		fdf->map.ang[Y] = 0;
		fdf->map.ang[Z] = 0;
	}
	draw_frame(fdf);
}

void	apply_menu_alpha(t_fdf *fdf)
{
	fdf->menu_alpha = -fdf->menu_alpha;
	draw_frame(fdf);
}
