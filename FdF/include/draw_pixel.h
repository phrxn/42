/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 22:00:54 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/03/21 22:00:55 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_PIXEL_H
# define DRAW_PIXEL_H
# ifndef BONUS
#  include "fdf.h"
# else
#  include "fdf_bonus.h"
# endif

# define POINT_LIMIT 20

int		draw_pixel(t_window *window, t_point point);

int		are_pixels_in_screen(const t_map *map);

#endif
