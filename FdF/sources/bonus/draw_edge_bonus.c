/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_edge_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:04:27 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/03/22 16:15:40 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/bonus/draw_edge_bonus.h"
#include "../../include/bonus/draw_pixel_bonus.h"
#include "../../include/bonus/window_bonus.h"
#include "../../include/colors.h"
#include "../../libs/minilibx-linux/mlx.h"
#include <math.h>

static int	sign(int final, int start)
{
	if ((final - start) < 0)
		return (-1);
	else
		return (1);
}

/**
 * is_invalid_edge - checks if edge is valid (see below)
 * @point1:		point 1 that forms the edge
 * @point1:		point 2 that forms the edge
 *
 * is invalid edge if:
 *   -- is edge outside screen
 *
 * Return:
 *     1 if invalid
 *     0 otherwise
 */
static int	is_invalid_edge(t_point point1, t_point point2)
{
	if ((point1.coor[X] < 0 && point2.coor[X] < 0)
		|| (point1.coor[X] > WIN_WID && point2.coor[X] > WIN_WID)
		|| (point1.coor[Y] < 0 && point2.coor[Y] < 0)
		|| (point1.coor[Y] > WIN_HEI && point2.coor[Y] > WIN_HEI))
		return (1);
	return (0);
}

/**
 * start_brese - starts a brese struct
 * @point1:		the struct with info about point1
 * @point2:		the struct with info about point1
 */
static void	start_brese(t_brese *brese, t_point point1, t_point point2)
{
	brese->deltax = fabs(point2.coor[X] - point1.coor[X]);
	brese->deltay = fabs(point2.coor[Y] - point1.coor[Y]);
	brese->signalx = sign(point2.coor[X], point1.coor[X]);
	brese->signaly = sign(point2.coor[Y], point1.coor[Y]);
	brese->interchange = FALSE;
	if (brese->deltay > brese->deltax)
	{
		brese->deltax ^= brese->deltay;
		brese->deltay ^= brese->deltax;
		brese->deltax ^= brese->deltay;
		brese->interchange = TRUE;
	}
	brese->error = 2 * brese->deltay - brese->deltax;
}

/**
 * apply - applies Bresenham's algorithm
 * @fdf:	fdf with map
 * @brese:	bresenham infos
 * @point1:	infos about first point
 * @argb:	argb increment values (the values can be positive or negative).
 */
static void	apply(t_fdf *fdf, t_brese *brese, t_point point1, double argb[4])
{
	int	count;
	int	color_start;

	count = 0;
	color_start = point1.color;
	while (count <= brese->deltax)
	{
		point1.color = get_gradient_color(color_start, count, argb);
		if (point1.coor[Z] > 0 || fdf->map.is_show_negative_z)
			draw_pixel(&fdf->window, point1);
		while (brese->error >= 0)
		{
			if (brese->interchange)
				point1.coor[X] = point1.coor[X] + brese->signalx;
			else
				point1.coor[Y] = point1.coor[Y] + brese->signaly;
			brese->error = brese->error - 2 * brese->deltax;
		}
		if (brese->interchange)
			point1.coor[Y] = point1.coor[Y] + brese->signaly;
		else
			point1.coor[X] = point1.coor[X] + brese->signalx;
		brese->error = brese->error + 2 * brese->deltay;
		count++;
	}
}

/**
 * create_edge - create a line (or "dot") using the bresenham algorithm
 * @fdf:	fdf to get mlx infos in window.
 * @point1:	the starting point of the line.
 * @point2:	the end point of the line.
 */
void	create_edge(t_fdf *fdf, t_point point1, t_point point2)
{
	t_brese	brese;
	double	increment_argb[4];

	if (is_invalid_edge(point1, point2))
		return ;
	start_brese(&brese, point1, point2);
	get_increment(point1.color, point2.color, brese.deltax, increment_argb);
	if (brese.deltax == 0 && brese.deltay == 0)
	{
		if (point1.coor[Z] > 0 || fdf->map.is_show_negative_z)
			draw_pixel(&fdf->window, point1);
		return ;
	}
	apply(fdf, &brese, point1, increment_argb);
}
