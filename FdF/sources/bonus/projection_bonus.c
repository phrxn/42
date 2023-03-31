/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:12:11 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/03/22 11:12:13 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/bonus/fdf_bonus.h"
#include <math.h>

void	sphere(t_map *map)
{
	double	radius;
	int		count;
	t_point	*point_tmp;

	radius = map->size[X] / 2;
	count = map->points_size;
	while (count--)
	{
		point_tmp = &map->points_draw[count];
		point_tmp->coor[X] = (radius + point_tmp->coor[Z])
			* cos(point_tmp->geo[LAT]) * cos(point_tmp->geo[LON]);
		point_tmp->coor[Y] = (radius + point_tmp->coor[Z])
			* cos(point_tmp->geo[LAT]) * sin(point_tmp->geo[LON]);
		point_tmp->coor[Z] = (radius + point_tmp->coor[Z])
			* sin(point_tmp->geo[LAT]);
	}
}
