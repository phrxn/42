/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point3_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:11:23 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/03/22 11:11:25 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/bonus/point_bonus.h"
#include "../../include/bonus/fdf_bonus.h"
#include "../../include/colors.h"
#include <math.h>

static void	apply_default_color(t_fdf *fdf, double bottom[4], double top[4])
{
	int		count;
	t_point	*point_tmp;

	count = 0;
	while (count < fdf->map.points_size)
	{
		point_tmp = &fdf->map.points[count];
		if (!point_tmp->has_color)
		{
			if (point_tmp->coor[Z] == 0)
				point_tmp->color = ZCOLORZER;
			else if (point_tmp->coor[Z] < 0)
				point_tmp->color = \
				get_gradient_color(ZCOLORZER, fabs(point_tmp->coor[Z]), bottom);
			else if (point_tmp->coor[Z] > 0)
				point_tmp->color = \
				get_gradient_color(ZCOLORZER, point_tmp->coor[Z], top);
		}
		count++;
	}
}

int	get_points_color_default(t_fdf *fdf)
{
	double	increments[2][4];
	int		distances[2];

	distances[0] = fabs((double) fdf->map.size[Z_MIN]);
	distances[1] = fdf->map.size[Z];
	if (get_increment(ZCOLORZER, ZCOLORMIN, distances[0], increments[0]))
		return (1);
	if (get_increment(ZCOLORZER, ZCOLORMAX, distances[1], increments[1]))
		return (1);
	apply_default_color(fdf, increments[0], increments[1]);
	return (0);
}

void	get_long_and_lat(t_fdf *fdf)
{	
	t_point	*point_tmp;
	double	increments[2];
	int		count;

	increments[LON] = (M_PI * 2) / (fdf->map.size[X] -1);
	increments[LAT] = (M_PI) / (fdf->map.size[Y]);
	count = 0;
	while (count < fdf->map.points_size)
	{
		point_tmp = &fdf->map.points[count];
		point_tmp->geo[LON] = point_tmp->coor[X] * increments[LON];
		point_tmp->geo[LAT] = point_tmp->coor[Y] * increments[LAT];
		count++;
	}
}
