/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 10:03:36 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/03/22 10:10:52 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/draw_map.h"
#include "../include/fdf.h"
#include "../include/matrix.h"
#include "../include/window.h"
#include "../include/draw_edge.h"
#include "../include/draw_pixel.h"
#include "../libs/libft/libft.h"

/**
 * get_max_min_x_y - get max and min value of the X and Y inside the map.
 * @map: 	map to get the values
 * @values: array the the will filled with values.
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
	map->center_win[X] += ((diff[RIG] - diff[LEF]) / 2);
	map->center_win[Y] += (diff[BOT] - diff[TOP]) / 2;
}

/**
 * map_draw_screen: paints a map on the screen
 * @fdf:	a pointer to an X structure with the map and
 * 			information for drawing the map.
 */
void	map_draw_screen(t_fdf *fdf)
{
	int			count;
	int			map_x_size;
	t_point		point[2];

	map_x_size = fdf->map.size[X];
	count = 0;
	while (count < (fdf->map.points_size - 1))
	{
		point[0] = fdf->map.points_draw[count];
		point[1] = fdf->map.points_draw[count + 1];
		if (!((count % map_x_size) == map_x_size - 1))
			create_edge(&fdf->window, point[0], point[1]);
		count++;
	}
	count = 0;
	while (count < (fdf->map.points_size - map_x_size))
	{
		point[0] = fdf->map.points_draw[count];
		point[1] = fdf->map.points_draw[count + map_x_size];
		create_edge(&fdf->window, point[0], point[1]);
		count++;
	}
}

/**
 * map_draw_create - creates a map for the drawing by applying: 
 * 					  rotation, scale and translate
 * @map:	a pointer to map with informations.
 */
void	map_draw_create(t_map *map)
{
	t_point	point_translate;

	point_translate.coor[X] = map->center_win[X];
	point_translate.coor[Y] = map->center_win[Y];
	point_translate.coor[Z] = 0;
	ft_memcpy(map->points_draw, map->points,
		map->points_size * sizeof(*map->points_draw));
	x_rotation(map->points_draw, map->points_size, map->ang[X]);
	y_rotation(map->points_draw, map->points_size, map->ang[Y]);
	z_rotation(map->points_draw, map->points_size, map->ang[Z]);
	scale(map->points_draw, map->points_size, map->scale);
	translation(map->points_draw, map->points_size, &point_translate);
}

/**
 * map_draw_fit - resizes the map to fit the screen.
 * @fdf:	fdf struct with the map.
 */
void	map_draw_fit(t_fdf *fdf)
{
	t_point	center;
	t_map	*map;

	map = &fdf->map;
	fdf->map.scale = SCALE;
	fdf->map.center_win[X] = (WIN_WID / 2);
	fdf->map.center_win[Y] = (WIN_HEI / 2);
	map_draw_create(map);
	center_map(map);
	while (are_pixels_in_screen(map))
	{
		map->scale += SCALE;
		map_draw_create(map);
		center_map(map);
	}
	if (fdf->map.scale != SCALE)
		map->scale -= SCALE;
	map_draw_create(map);
	center_map(map);
}
