/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 10:14:15 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/03/22 10:19:19 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/draw_pixel.h"
#include "../include/fdf.h"
#include "../include/matrix.h"
#include "../include/window.h"
#include "../libs/minilibx-linux/mlx.h"

static void	put_pixel(char *address, int color, int endian)
{
	if (endian == 1)
	{
		address[0] = (color >> 24) & 0xff;
		address[1] = (color >> 16) & 0xff;
		address[2] = (color >> 8) & 0xff;
		address[3] = (color) & 0xff;
	}
	else
	{
		address[3] = (color >> 24) & 0xff;
		address[2] = (color >> 16) & 0xff;
		address[1] = (color >> 8) & 0xff;
		address[0] = (color) & 0xff;
	}
}

/**
 * draw_pixel - paints a pixel on the screen if it is inside it.
 * @window:	window to paint the pixel
 * @point:	a point struct with informations about the pixel.
 * 
 * Return:
 *     0 On successful (pixel painted)
 *     1 On failure (pixel off screen)
 */
int	draw_pixel(t_window *window, t_point point)
{
	int		pixel_position;
	int		color;
	char	*address_image;

	address_image = (char *)window->addr;
	if ((point.coor[X] < 0 || point.coor[X] > WIN_WID)
		|| (point.coor[Y] < 0 || point.coor[Y] > WIN_HEI))
		return (1);
	pixel_position = ((int)point.coor[Y] * WIN_WID * 4)
		+ ((int)point.coor[X] * 4);
	if (window->bits_per_pixel != 32)
		point.color = mlx_get_color_value(window->mlx, point.color);
	put_pixel(&address_image[pixel_position], point.color, window->endian);
	return (0);
}

/**
 * are_pixels_in_screen - check if all map points are within the screen
 * @fdf:	a fdf struct with map.
 *
 * Return:
 *     1 if all points are inside the map
 *     0 otherwise
 */
int	are_pixels_in_screen(const t_map *map)
{
	int		count;
	int		min_screen;
	int		x_max_screen;
	int		y_max_screen;
	t_point	point_tmp;

	count = 0;
	min_screen = POINT_LIMIT;
	x_max_screen = (WIN_WID - POINT_LIMIT);
	y_max_screen = (WIN_HEI - POINT_LIMIT);
	while (count < map->points_size)
	{
		point_tmp = map->points_draw[count];
		if (point_tmp.coor[X] < min_screen || point_tmp.coor[X] > x_max_screen)
			return (0);
		if (point_tmp.coor[Y] < min_screen || point_tmp.coor[Y] > y_max_screen)
			return (0);
		count++;
	}
	return (1);
}
