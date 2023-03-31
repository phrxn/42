/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:10:08 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/03/22 11:10:11 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/bonus/map_bonus.h"
#include "../../include/bonus/point_bonus.h"
#include "../../include/bonus/fdf_bonus.h"
#include "../../include/file_memory.h"
#include "../../include/errors.h"
#include "../../include/utils.h"
#include "../../libs/libft/libft.h"
#include <stdlib.h>
#include <math.h>

#ifdef TEST
# include "../../tests/map_load_test.h"
#endif

static void	die(t_fdf *fdf, char *msg_erro)
{
	free(fdf->file.data);
	fatal_error(msg_erro);
}

static char	*count_points_in_line(t_fdf *fdf, char *line_start, int *count)
{
	char	*line_end;

	*count = 0;
	line_end = 0;
	while (*line_start && *line_start != '\n')
	{
		while (*line_start == ' ')
			line_start++;
		line_end = line_start;
		while (*line_end && *line_end != ' ' && *line_end != '\n')
			line_end++;
		if (!(line_end - line_start))
			break ;
		if (!is_point_valid(line_start, line_end))
			die(fdf, "The file have a invalid point.");
		(*count)++;
		line_start = line_end;
	}
	if (!*count)
		die(fdf, "The file have a empty line.");
	if (*line_end == '\n')
		line_end++;
	return (line_end);
}

static void	count_points_in_file(t_fdf *fdf)
{
	char	*next_line;
	int		ele_amount;

	next_line = count_points_in_line(fdf, fdf->file.data, &fdf->map.size[X]);
	fdf->map.size[Y]++;
	while (next_line && *next_line != '\0')
	{
		next_line = count_points_in_line(fdf, next_line, &ele_amount);
		fdf->map.size[Y]++;
		if (ele_amount != fdf->map.size[X])
			die(fdf, "The number of elements between the lines are different.");
		if (*next_line == '\n')
			next_line++;
	}
	if (fdf->map.size[X] <= 1 || fdf->map.size[Y] <= 1)
		die(fdf, "The number of rows and/or columns must be greater than 1.");
	fdf->map.points_size = (fdf->map.size[Y] * fdf->map.size[X]);
}

static void	get_map_zvalues(t_fdf *fdf)
{
	int		count;
	t_point	point_tmp;

	count = fdf->map.points_size;
	fdf->map.size[Z] = 0;
	fdf->map.size[Z_MIN] = 0;
	while (count--)
	{
		point_tmp = fdf->map.points[count];
		if (point_tmp.coor[Z] > fdf->map.size[Z])
			fdf->map.size[Z] = point_tmp.coor[Z];
		if (point_tmp.coor[Z] < fdf->map.size[Z_MIN])
			fdf->map.size[Z_MIN] = point_tmp.coor[Z];
	}
}

void	map_load(t_fdf *fdf)
{
	fdf->file.data = load_file_in_memory(fdf->file.name);
	if (ft_strlen(fdf->file.data) == 0)
		die(fdf, "Empty file.");
	count_points_in_file(fdf);
	get_points_file(fdf);
	get_map_zvalues(fdf);
	get_long_and_lat(fdf);
	get_points_color_default(fdf);
	fdf->map.points_draw = malloc(\
			fdf->map.points_size * sizeof(*fdf->map.points));
	if (!fdf->map.points_draw)
	{
		free(fdf->map.points);
		die(fdf, "Malloc points_draw error.");
	}
	ft_memcpy(fdf->map.points_draw, fdf->map.points, \
			fdf->map.points_size * sizeof(*fdf->map.points));
	free(fdf->file.data);
	fdf->file.data = NULL;
}
