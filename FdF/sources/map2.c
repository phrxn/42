/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 10:37:34 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/03/22 10:37:49 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/map.h"
#include "../include/fdf.h"
#include <stdlib.h>

void	map_close(t_fdf *fdf)
{
	if (fdf->file.data)
		free(fdf->file.data);
	if (fdf->map.points)
		free(fdf->map.points);
	if (fdf->map.points_draw)
		free(fdf->map.points_draw);
	fdf->file.data = NULL;
	fdf->map.points = NULL;
	fdf->map.points_draw = NULL;
}
