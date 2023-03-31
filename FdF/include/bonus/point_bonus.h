/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 22:05:14 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/03/21 22:05:15 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_BONUS_H
# define POINT_BONUS_H
# include "fdf_bonus.h"

int		is_point_valid(const char *start, const char *end);

int		get_points_color_default(t_fdf *fdf);

int		get_point_color_file(t_point *point, char *str);

int		get_points_line(t_fdf *fdf, char *line, int line_num);

void	get_points_file(t_fdf *fdf);

void	get_long_and_lat(t_fdf *fdf);

#endif
