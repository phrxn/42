/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 22:00:47 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/03/21 22:00:48 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_MAP_H
# define DRAW_MAP_H
# include "fdf.h"

# define SCALE 1.5
# define SCALE_MAX 570.6650390625

# define X_MIN 0
# define Y_MIN 1
# define X_MAX 2
# define Y_MAX 3

# define TOP 0
# define BOT 1
# define LEF 2
# define RIG 3

void	map_draw_screen(t_fdf *fdf);

void	map_draw_create(t_map *map);

void	map_draw_fit(t_fdf *fdf);

#endif
