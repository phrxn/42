/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_edge.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 09:20:46 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/03/22 10:02:13 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/draw_edge.h"
#include "../include/colors.h"
#include "../include/draw_pixel.h"
#include "../libs/minilibx-linux/mlx.h"
#include <math.h>

/**
 * sign - returns a increment or decrement value
 */
static int	sign(int final, int start)
{
	if ((final - start) < 0)
		return (-1);
	else
		return (1);
}

/**
 * start_brese - starts a brese struct
 * @point1:		the struct with info about point1
 * @point2:		the struct with info about point1
 */
static void	start_brese(t_brese *brese, t_point point1, t_point point2)
{
	int	tmp;

	brese->deltax = fabs(point2.coor[X] - point1.coor[X]);
	brese->deltay = fabs(point2.coor[Y] - point1.coor[Y]);
	brese->signalx = sign(point2.coor[X], point1.coor[X]);
	brese->signaly = sign(point2.coor[Y], point1.coor[Y]);
	brese->interchange = FALSE;
	if (brese->deltay > brese->deltax)
	{
		tmp = brese->deltax;
		brese->deltax = brese->deltay;
		brese->deltay = tmp;
		brese->interchange = TRUE;
	}
	brese->error = 2 * brese->deltay - brese->deltax;
}

/**
 * apply - applies Bresenham's algorithm
 * @win:	mlx infos
 * @brese:	bresenham infos
 * @point1:	infos about first point
 * @argb:	argb increment values (the values can be positive or negative).
 */
static void	apply(t_window *win, t_brese *brese, t_point point1, double argb[4])
{
	int	count;
	int	color_start;

	count = 0;
	color_start = point1.color;
	while (count <= brese->deltax)
	{
		point1.color = get_gradient_color(color_start, count, argb);
		draw_pixel(win, point1);
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
 * @window:	mlx infos
 * @point1:	the starting point of the line.
 * @point2:	the end point of the line.
 */
void	create_edge(t_window *window, t_point point1, t_point point2)
{
	t_brese	brese;
	double	increment_argb[4];

	start_brese(&brese, point1, point2);
	get_increment(point1.color, point2.color, brese.deltax, increment_argb);
	if (brese.deltax == 0 && brese.deltay == 0)
	{
		draw_pixel(window, point1);
		return ;
	}
	apply(window, &brese, point1, increment_argb);
}
