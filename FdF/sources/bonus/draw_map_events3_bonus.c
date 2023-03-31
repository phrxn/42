/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_events3_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:05:25 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/03/22 11:05:27 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/bonus/draw_map_events_bonus.h"
#include "../../include/bonus/draw_map_bonus.h"
#include "../../include/bonus/fdf_bonus.h"
#include "../../include/bonus/frame_bonus.h"
#include "../../include/bonus/projection_bonus.h"
#include <math.h>

/**
 * apply_z_proportion - try to resize Z value to fit in screen
 *
 * @fdf:	a pointer to fdf struct with map struct
 */
void	apply_z_fit(t_fdf *fdf)
{
	int	count;
	int	zmax;

	if (fdf->map.zscale != 0)
		apply_z_default(fdf);
	while (1)
	{
		count = fdf->map.points_size;
		zmax = 0;
		while (count--)
			if (fabs(fdf->map.points[count].coor[Z]) > zmax)
				zmax = fabs(fdf->map.points[count].coor[Z]);
		if (zmax <= 10 || fdf->map.zscale <= -20)
			break ;
		count = fdf->map.points_size;
		while (count--)
			fdf->map.points[count].coor[Z] /= Z_SCALE_DIV;
		fdf->map.zscale--;
	}
	draw_frame(fdf);
}

void	apply_z_default(t_fdf *fdf)
{
	double	tmp;
	int		count;

	count = fdf->map.points_size;
	tmp = 0;
	if (fdf->map.zscale == 0)
		return ;
	if (fdf->map.zscale < 0)
		tmp = pow(Z_SCALE_DIV, fabs(fdf->map.zscale));
	if (fdf->map.zscale > 0)
		tmp = (1 / pow(Z_SCALE_DIV, fdf->map.zscale));
	while (count--)
		fdf->map.points[count].coor[Z] *= tmp;
	fdf->map.zscale = 0;
	draw_frame(fdf);
}

void	apply_z_inc(t_fdf *fdf)
{
	int	count;

	count = fdf->map.points_size;
	if (fdf->map.zscale == Z_SCALE_MAX)
		return ;
	fdf->map.zscale++;
	while (count--)
		fdf->map.points[count].coor[Z] *= Z_SCALE_DIV ;
	draw_frame(fdf);
}

void	apply_z_dec(t_fdf *fdf)
{
	int	count;

	count = fdf->map.points_size;
	if (fdf->map.zscale == Z_SCALE_MIN)
		return ;
	fdf->map.zscale--;
	while (count--)
		fdf->map.points[count].coor[Z] /= Z_SCALE_DIV ;
	draw_frame(fdf);
}
