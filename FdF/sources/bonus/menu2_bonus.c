/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu2_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:10:33 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/03/22 11:10:35 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/bonus/menu_bonus.h"
#include "../../include/bonus/draw_pixel_bonus.h"
#include "../../include/bonus/fdf_bonus.h"
#include "../../include/bonus/window_bonus.h"

void	menu_draw_background(t_fdf *fdf)
{
	t_point	point;
	int		x;
	int		y;

	point.color = BACKGROUND_MENU;
	x = 0;
	y = 0;
	while (y < WIN_HEI)
	{
		while (x < MENU_WIDTH)
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
