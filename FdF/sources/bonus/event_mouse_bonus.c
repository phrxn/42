/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_mouse_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:08:19 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/03/22 15:12:34 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/bonus/event_mouse_bonus.h"
#include "../../include/bonus/draw_map_bonus.h"
#include "../../include/bonus/frame_bonus.h"
#include "../../include/bonus/fdf_bonus.h"
#include "../../include/bonus/matrix_bonus.h"
#include "../../include/bonus/draw_map_events_bonus.h"
#include <stdio.h>

int	mouse_pressed(int button, int x, int y, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (button == MOU_BTN_1 && !fdf->mouse.is_btn_2_pressed)
		fdf->mouse.is_btn_1_pressed = 1;
	else if (button == MOU_BTN_2 && !fdf->mouse.is_btn_1_pressed)
		fdf->mouse.is_btn_2_pressed = 1;
	else
		return (0);
	fdf->mouse.last_coor[X] = x;
	fdf->mouse.last_coor[Y] = y;
	return (0);
}

int	mouse_released(int button, int x, int y, void *param)
{
	t_fdf	*fdf;
	t_point	point;

	fdf = (t_fdf *)param;
	if (button == MOU_SCRL_UP)
		zoom_in(fdf);
	else if (button == MOU_SCRL_DW)
		zoom_out(fdf);
	else if (button == MOU_BTN_M)
		zoom_default(fdf);
	else if (button == MOU_BTN_1 && fdf->mouse.is_btn_1_pressed)
	{
		fdf->mouse.is_btn_1_pressed = 0;
		point.coor[X] = x - fdf->mouse.last_coor[X];
		point.coor[Y] = y - fdf->mouse.last_coor[Y];
		apply_translation(fdf, point.coor[X], point.coor[Y]);
	}
	else if (button == MOU_BTN_2 && fdf->mouse.is_btn_2_pressed)
		fdf->mouse.is_btn_2_pressed = 0;
	return (0);
}
