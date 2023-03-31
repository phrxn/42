/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 22:01:58 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/03/21 22:01:59 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
# define POINT_H
# include "fdf.h"

int		is_point_valid(const char *start, const char *end);

int		get_points_color_default(t_fdf *fdf);

int		get_point_color_file(t_point *point, char *str);

int		get_points_line(t_fdf *fdf, char *line, int line_num);

void	get_points_file(t_fdf *fdf);

void	get_long_and_lat(t_fdf *fdf);

#endif
