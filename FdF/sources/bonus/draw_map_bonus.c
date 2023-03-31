/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:04:55 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/03/22 16:17:59 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/bonus/draw_map_bonus.h"
#include "../../include/bonus/draw_map_events_bonus.h"
#include "../../include/bonus/fdf_bonus.h"
#include "../../include/bonus/map_bonus.h"
#include "../../include/bonus/window_bonus.h"
#include "../../include/bonus/matrix_bonus.h"
#include "../../include/bonus/draw_edge_bonus.h"
#include "../../include/bonus/draw_pixel_bonus.h"
#include "../../include/bonus/projection_bonus.h"
#include "../../libs/libft/libft.h"
#include <stdio.h>

/**
 * map_draw_screen: paints a map on the screen. Drawing rows and after cols.
 * @fdf:	a pointer to an fdf structure with the map and
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
			create_edge(fdf, point[0], point[1]);
		count++;
	}
	count = 0;
	while (count < (fdf->map.points_size - map_x_size))
	{
		point[0] = fdf->map.points_draw[count];
		point[1] = fdf->map.points_draw[count + map_x_size];
		create_edge(fdf, point[0], point[1]);
		count++;
	}
}

/**
 * map_draw_create - creates a map for the drawing by applying: 
 * 					  projection, rotation, scale and translate
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
	if (map->projection == PROJ_SPH)
		sphere(map);
	x_rotation(map->points_draw, map->points_size, map->ang[X]);
	y_rotation(map->points_draw, map->points_size, map->ang[Y]);
	z_rotation(map->points_draw, map->points_size, map->ang[Z]);
	scale(map->points_draw, map->points_size, map->scale);
	translation(map->points_draw, map->points_size, &point_translate);
}
