/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 10:40:53 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/03/22 10:40:56 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/projection.h"
#include "../include/frame.h"
#include "../include/fdf.h"
#include "../include/draw_map.h"

void	isometric(t_fdf	*fdf)
{
	fdf->map.ang[X] = 30;
	fdf->map.ang[Y] = -30;
	fdf->map.ang[Z] = 35;
	map_draw_fit(fdf);
	draw_frame(fdf);
}
