/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:09:58 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/03/22 11:10:00 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/bonus/map_bonus.h"
#include "../../include/bonus/fdf_bonus.h"
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
