/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 10:21:19 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/03/22 10:21:43 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/event_window.h"
#include "../include/frame.h"
#include "../include/fdf.h"
#include "../libs/minilibx-linux/mlx.h"
#include <stdlib.h>
#include <stdio.h>

int	window_destroy(void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (!fdf->window.mlx)
		return (0);
	mlx_loop_end(fdf->window.mlx);
	mlx_destroy_image(fdf->window.mlx, fdf->window.image);
	mlx_destroy_window(fdf->window.mlx, fdf->window.window);
	mlx_destroy_display(fdf->window.mlx);
	free(fdf->window.mlx);
	fdf->window.image = NULL;
	fdf->window.window = NULL;
	fdf->window.mlx = NULL;
	return (0);
}

int	window_expose(void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	draw_frame(fdf);
	return (0);
}
