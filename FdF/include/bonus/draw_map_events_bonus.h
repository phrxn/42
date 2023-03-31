/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_events_bonus.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 22:02:46 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/03/21 22:02:47 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_MAP_EVENTS_BONUS_H
# define DRAW_MAP_EVENTS_BONUS_H
# include "../../include/bonus/fdf_bonus.h"

# define SCALE 1.44913767462
# define SCALE_MAX 570.6650390625

# define X_MIN 0
# define Y_MIN 1
# define X_MAX 2
# define Y_MAX 3

# define TOP 0
# define BOT 1
# define LEF 2
# define RIG 3

# define Z_SCALE_MIN -20
# define Z_SCALE_MAX 20
# define Z_SCALE_DIV 1.5

void	zoom_in(t_fdf *fdf);

void	zoom_out(t_fdf *fdf);

void	zoom_default(t_fdf *fdf);

void	apply_ang(t_fdf *fdf, int axis, int ang_value);

void	apply_translation(t_fdf *fdf, int new_x, int new_y);

void	apply_projection(t_fdf *fdf, int projection);

void	apply_z_fit(t_fdf *fdf);

void	apply_z_default(t_fdf *fdf);

void	apply_z_inc(t_fdf *fdf);

void	apply_z_dec(t_fdf *fdf);

void	apply_menu_alpha(t_fdf *fdf);
#endif
