/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_keyboard_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:07:49 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/03/22 11:07:51 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/bonus/event_keyboard_bonus.h"
#include "../../include/bonus/fdf_bonus.h"
#include "../../include/bonus/draw_map_events_bonus.h"

static void	key_pressed2(int key, t_fdf *fdf)
{
	if (key == VK_PERIOD)
		apply_z_inc(fdf);
	else if (key == VK_COMMA)
		apply_z_dec(fdf);
	else if (key == VK_PLUS)
		zoom_in(fdf);
	else if (key == VK_MINUS)
		zoom_out(fdf);
	else if (key == VK_R)
		zoom_default(fdf);
	else if (key == VK_LEFT)
		apply_translation(fdf, -10, 0);
	else if (key == VK_UP)
		apply_translation(fdf, 0, -10);
	else if (key == VK_RIGHT)
		apply_translation(fdf, 10, 0);
	else if (key == VK_DOWN)
		apply_translation(fdf, 0, 10);
	else if (key == VK_M)
		apply_menu_alpha(fdf);
	else if (key == VK_ESC)
		terminate(fdf);
}

int	key_pressed(int key, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (key == VK_W)
		apply_ang(fdf, X, 10);
	else if (key == VK_S)
		apply_ang(fdf, X, -10);
	else if (key == VK_A)
		apply_ang(fdf, Y, -10);
	else if (key == VK_D)
		apply_ang(fdf, Y, 10);
	else if (key == VK_C)
		apply_ang(fdf, Z, 10);
	else if (key == VK_Q)
		apply_ang(fdf, Z, -10);
	else if (key == VK_G)
		apply_projection(fdf, PROJ_SPH);
	else if (key == VK_I)
		apply_projection(fdf, PROJ_ISO);
	else if (key == VK_T)
		apply_projection(fdf, PROJ_TOP);
	else
		key_pressed2(key, fdf);
	return (0);
}
