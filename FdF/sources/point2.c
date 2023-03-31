/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 10:39:22 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/03/22 10:39:24 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/point.h"
#include "../include/errors.h"
#include "../include/utils.h"
#include "../libs/libft/libft.h"
#include <stdlib.h>

static void	die(t_fdf *fdf, char *msg_erro)
{
	free(fdf->file.data);
	fatal_error(msg_erro);
}

/**
 * get_point_color_file - get a point color (if exist) from str
 * @point:	pointer to set the color
 * @str:	str to try extract the color
 *
 * Return:
 *     On success:
 *         0
 *     On failure:
 *         1
 */
int	get_point_color_file(t_point *point, char *str)
{
	char	color_separator;
	char	**elements;

	color_separator = ',';
	if (ft_strchr(str, color_separator))
	{
		elements = ft_split(str, color_separator);
		if (!elements)
			return (1);
		point->color = get_hex_value(elements[1]);
		point->has_color = 1;
		free_split(elements);
	}
	else
	{
		point->color = 0;
		point->has_color = 0;
	}
	return (0);
}

/**
 * get_points_line - create points with xyz coordinates and color (if
 * exist) from line
 * @fdf:		fdf pointer to put the points
 * @line:		string with points info
 * @line_num:	line number to create Y coordinate in the pointers
 *
 * Return:
 *     On success:
 *         0
 *     On failure:
 *         1
 */
int	get_points_line(t_fdf *fdf, char *line, int line_num)
{
	char	**points;
	int		x_pos;
	int		point_pos;

	points = ft_split(line, ' ');
	if (!points)
		return (1);
	x_pos = 0;
	point_pos = (line_num * fdf->map.size[X]);
	while (points[x_pos])
	{
		fdf->map.points[point_pos].coor[X] = x_pos - (fdf->map.size[X] / 2);
		fdf->map.points[point_pos].coor[Y] = line_num - (fdf->map.size[Y] / 2);
		fdf->map.points[point_pos].coor[Z] = ft_atoi(points[x_pos]);
		if (get_point_color_file(&fdf->map.points[point_pos], points[x_pos]))
		{
			free_split(points);
			return (1);
		}
		x_pos++;
		point_pos++;
	}
	free_split(points);
	return (0);
}

void	get_points_file(t_fdf *fdf)
{
	int		line_num;
	char	**lines;

	fdf->map.points = ft_calloc(fdf->map.points_size, sizeof(*fdf->map.points));
	if (!fdf->map.points)
		die(fdf, "Malloc map points error.");
	lines = ft_split(fdf->file.data, '\n');
	if (!lines)
	{
		free(fdf->map.points);
		die(fdf, "Split lines malloc error.");
	}
	line_num = 0;
	while (lines[line_num])
	{
		if (get_points_line(fdf, lines[line_num], line_num))
		{
			free(fdf->map.points);
			free_split(lines);
			die(fdf, "Split lines malloc error.");
		}
		line_num++;
	}
	free_split(lines);
}
