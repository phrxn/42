/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 22:02:39 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/03/21 22:02:40 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_MAP_BONUS_H
# define DRAW_MAP_BONUS_H
# include "fdf_bonus.h"

void	map_draw_screen(t_fdf *fdf);

void	map_draw_create(t_map *map);

void	map_draw_fit(t_map *map);

#endif
