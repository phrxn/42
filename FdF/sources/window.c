/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 10:41:21 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/03/22 10:41:22 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/window.h"
#include "../include/event_keyboard.h"
#include "../include/event_window.h"
#include "../include/errors.h"
#include "../include/fdf.h"
#include "../include/map.h"
#include "../libs/minilibx-linux/mlx.h"
#include <stdlib.h>

static void	die(t_fdf *fdf, char *msg_erro)
{
	map_close(fdf);
	fatal_error(msg_erro);
}

void	start_event_handlers(t_fdf *fdf)
{
	mlx_hook(fdf->window.window, ON_KEYDOWN, (1L << 0), key_pressed, fdf);
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
