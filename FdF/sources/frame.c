/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 10:27:08 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/03/22 10:27:13 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/frame.h"
#include "../include/fdf.h"
#include "../include/window.h"
#include "../include/colors.h"
#include "../include/draw_map.h"
#include "../include/draw_pixel.h"
#include "../libs/minilibx-linux/mlx.h"

static void	draw_background(t_fdf *fdf)
{
	t_point	point;
	int		x;
	int		y;

	point.color = BACKGROUND;
	x = 0;
	y = 0;
	while (y < WIN_HEI)
	{
		while (x < WIN_WID)
		{
			point.coor[X] = x;
			point.coor[Y] = y;
			draw_pixel(&fdf->window, point);
			x++;
		}
		x = 0;
		y++;
	}
}

void	draw_frame(t_fdf *fdf)
{
	draw_background(fdf);
	map_draw_create(&fdf->map);
	map_draw_screen(fdf);
	mlx_put_image_to_window(fdf->window.mlx, fdf->window.window,
		fdf->window.image, 0, 0);
}
