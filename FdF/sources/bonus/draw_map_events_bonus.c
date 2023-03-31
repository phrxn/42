/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_events_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:05:48 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/03/22 11:05:49 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/bonus/draw_map_events_bonus.h"
#include "../../include/bonus/fdf_bonus.h"
#include "../../include/bonus/frame_bonus.h"
#include "../../include/bonus/draw_map_bonus.h"
#include "../../include/bonus/draw_pixel_bonus.h"
#include "../../include/bonus/menu_bonus.h"
#include "../../include/bonus/window_bonus.h"

/**
 * get_max_min_x_y - fill the values with XY min and max. 
 *
 * @map:		map to get XY values
 * @values:		array to fill with XY values	 
 *
 * goes through the points of the map to obtain the maximum and minimum
 * values of X and Y of the map.
 */
static void	get_max_min_x_y(const t_map *map, int values[4])
{
	int		count;
	t_point	point_tmp;

	count = map->points_size;
	values[X_MIN] = WIN_WID;
	values[Y_MIN] = WIN_HEI;
	values[X_MAX] = 0;
	values[Y_MAX] = 0;
	while (count--)
	{
		point_tmp = map->points_draw[count];
		if (point_tmp.coor[X] < values[X_MIN])
			values[X_MIN] = point_tmp.coor[X];
		if (point_tmp.coor[Y] < values[Y_MIN])
			values[Y_MIN] = point_tmp.coor[Y];
		if (point_tmp.coor[X] > values[X_MAX])
			values[X_MAX] = point_tmp.coor[X];
		if (point_tmp.coor[Y] > values[Y_MAX])
			values[Y_MAX] = point_tmp.coor[Y];
	}
}

/**
 * center_map - recalc map center
 * @map:	map to recalc center.
 */
static void	center_map(t_map *map)
{
	int		min_max_x_y[4];
	int		diff[4];

	get_max_min_x_y(map, min_max_x_y);
	diff[TOP] = min_max_x_y[Y_MIN];
	diff[BOT] = WIN_HEI - min_max_x_y[Y_MAX];
	diff[LEF] = min_max_x_y[X_MIN];
	diff[RIG] = WIN_WID - min_max_x_y[X_MAX];
	map->center_win[X] += ((diff[RIG] - diff[LEF]) / 2) + (MENU_WIDTH / 2);
	map->center_win[Y] += (diff[BOT] - diff[TOP]) / 2;
}

/**
 * zoom_default - resizes the map to fit the screen.
 * @fdf:	fdf struct with the map.
 */
void	zoom_default(t_fdf *fdf)
{
	fdf->map.scale = SCALE;
	fdf->map.center_win[X] = (WIN_WID / 2);
	fdf->map.center_win[Y] = (WIN_HEI / 2);
	apply_z_fit(fdf);
	map_draw_create(&fdf->map);
	center_map(&fdf->map);
	while (are_pixels_in_screen(&fdf->map) && fdf->map.scale < SCALE_MAX)
	{
		zoom_in(fdf);
		map_draw_create(&fdf->map);
		center_map(&fdf->map);
	}
	if (fdf->map.scale != SCALE)
		zoom_out(fdf);
	map_draw_create(&fdf->map);
	center_map(&fdf->map);
	draw_frame(fdf);
}

void	zoom_in(t_fdf *fdf)
{
	if (fdf->map.scale < SCALE_MAX)
		fdf->map.scale *= SCALE;
	draw_frame(fdf);
}

void	zoom_out(t_fdf *fdf)
{
	if (fdf->map.scale > SCALE)
		fdf->map.scale /= SCALE;
	draw_frame(fdf);
}
