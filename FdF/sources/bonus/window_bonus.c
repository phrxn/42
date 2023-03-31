/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:12:48 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/03/22 11:12:57 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/bonus/window_bonus.h"
#include "../../include/bonus/fdf_bonus.h"
#include "../../include/bonus/event_keyboard_bonus.h"
#include "../../include/bonus/event_mouse_bonus.h"
#include "../../include/bonus/event_window_bonus.h"
#include "../../include/errors.h"
#include "../../include/bonus/map_bonus.h"
#include "../../libs/minilibx-linux/mlx.h"
#include <stdlib.h>

static void	die(t_fdf *fdf, char *msg_erro)
{
	map_close(fdf);
	fatal_error(msg_erro);
}

void	start_event_handlers(t_fdf *fdf)
{
	mlx_hook(fdf->window.window, ON_KEYDOWN, (1L << 0), key_pressed, fdf);
	mlx_hook(fdf->window.window, ON_MOUSEDOWN, (1L << 2), mouse_pressed, fdf);
	mlx_hook(fdf->window.window, ON_MOUSEUP, (1L << 3), mouse_released, fdf);
	mlx_hook(fdf->window.window, ON_DESTROY, (0), terminate, fdf);
	mlx_hook(fdf->window.window, ON_EXPOSE, (1L << 15), window_expose, fdf);
	mlx_loop(fdf->window.mlx);
}

void	create_window(t_fdf *fdf)
{
	t_window	*window;

	window = &fdf->window;
	window->mlx = mlx_init();
	if (!window->mlx)
		die(fdf, "Mlx_init error.");
	window->window = mlx_new_window(window->mlx, WIN_WID, WIN_HEI, WIN_TIT);
	if (!window->window)
	{
		free(window->mlx);
		die(fdf, "Window mlx malloc error.");
	}
	window->image = mlx_new_image(window->mlx, WIN_WID, WIN_HEI);
	if (!window->image)
	{
		free(window->mlx);
		free(window->window);
		die(fdf, "Window image malloc error.");
	}
	window->addr = mlx_get_data_addr(window->image, &window->bits_per_pixel,
			&window->line_length, &window->endian);
}
