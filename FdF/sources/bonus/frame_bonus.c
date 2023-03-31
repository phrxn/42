/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:09:34 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/03/22 11:09:36 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/bonus/frame_bonus.h"
#include "../../include/bonus/fdf_bonus.h"
#include "../../include/bonus/menu_bonus.h"
#include "../../include/bonus/window_bonus.h"
#include "../../include/bonus/draw_map_bonus.h"
#include "../../include/bonus/draw_pixel_bonus.h"
#include "../../include/colors.h"
#include "../../libs/minilibx-linux/mlx.h"

static void	frame_draw_background(t_fdf *fdf)
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
	frame_draw_background(fdf);
	if (fdf->menu_alpha > 0)
		menu_draw_background(fdf);
	map_draw_create(&fdf->map);
	map_draw_screen(fdf);
	mlx_put_image_to_window(fdf->window.mlx, fdf->window.window,
		fdf->window.image, 0, 0);
	if (fdf->menu_alpha < 0)
		menu_draw_background(fdf);
	menu_show_info(fdf);
}
