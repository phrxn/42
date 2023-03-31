/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:09:22 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/03/22 20:30:13 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/bonus/fdf_bonus.h"
#include "../../include/bonus/map_bonus.h"
#include "../../include/bonus/frame_bonus.h"
#include "../../include/bonus/projection_bonus.h"
#include "../../include/bonus/draw_map_events_bonus.h"
#include "../../include/bonus/event_window_bonus.h"
#include "../../include/bonus/window_bonus.h"
#include "../../include/errors.h"
#include "../../libs/libft/libft.h"

static void	check_parameters(t_fdf *fdf, int argc, char *argv[])
{
	char	*file_name;
	char	*extension;
	char	*dot;
	int		file_name_size;

	if (argc != 2)
		fatal_error("The parameters numbers are different to 1.");
	file_name = argv[1];
	file_name_size = ft_strlen(file_name);
	if (file_name_size < 5)
		fatal_error("The file name isn't valid.");
	dot = ft_strrchr(file_name, '.');
	if (!dot)
		fatal_error("The file name don't have a extension.");
	extension = ft_strnstr(dot, ".fdf", file_name_size);
	if (!extension || (((file_name + file_name_size) - extension) != 4))
		fatal_error("The file name don't have a fdf extension.");
	fdf->file.name = file_name;
}

static void	start_fdf2(t_fdf *fdf)
{
	fdf->map.points = 0;
	fdf->map.points_draw = 0;
	fdf->map.points_size = 0;
	fdf->map.size[X] = 0;
	fdf->map.size[Y] = 0;
	fdf->map.size[Z] = 0;
	fdf->map.size[Z_MIN] = 0;
	fdf->map.ang[X] = 0;
	fdf->map.ang[Y] = 0;
	fdf->map.ang[Z] = 0;
	fdf->map.center_win[X] = 0;
	fdf->map.center_win[Y] = 0;
	fdf->map.projection = 0;
	fdf->map.is_show_negative_z = 1;
	fdf->map.scale = 0;
	fdf->map.zscale = 0;
	fdf->file.name = 0;
	fdf->file.data = 0;
	fdf->menu_alpha = 1;
}

static void	start_fdf(t_fdf *fdf)
{
	fdf->window.mlx = 0;
	fdf->window.window = 0;
	fdf->window.image = 0;
	fdf->window.addr = 0;
	fdf->window.line_length = 0;
	fdf->window.bits_per_pixel = 0;
	fdf->window.endian = 0;
	fdf->mouse.is_btn_1_pressed = 0;
	fdf->mouse.is_btn_2_pressed = 0;
	fdf->mouse.last_coor[X] = 0;
	fdf->mouse.last_coor[Y] = 0;
	start_fdf2(fdf);
}

void	start(int argc, char *argv[])
{
	t_fdf	fdf;

	start_fdf(&fdf);
	check_parameters(&fdf, argc, argv);
	map_load(&fdf);
	create_window(&fdf);
	fdf.map.projection = PROJ_ISO;
	zoom_default(&fdf);
	start_event_handlers(&fdf);
}

int	terminate(t_fdf *fdf)
{
	map_close(fdf);
	window_destroy(fdf);
	exit(0);
}
