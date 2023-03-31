/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 22:02:52 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/03/21 22:02:53 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_PIXEL_BONUS_H
# define DRAW_PIXEL_BONUS_H
# include "fdf_bonus.h"

// defines a margin for the points on the screen
# define POINT_LIMIT 0

int	draw_pixel(t_window *window, t_point point);

int	are_pixels_in_screen(const t_map *map);

#endif
