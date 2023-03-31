/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 09:19:35 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/03/22 09:21:43 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/colors.h"
#include <math.h>

/**
 * get_increment - fills an array with incrementing RGB values
 * @color_a:	initial RGB color
 * @color_b:	final RGB color
 * @distance:	an int value >= 0 to calc the increment values
 * @increment:	the array 
 *
 * Return:
 *     On success:
 *        0
 *     On failure:
 *     	  1 if distance is a negative number. The increment isn't changed. 
 */
int	get_increment(int color_a, int color_b, int distance, double increment[4])
{
	double	colors[4];

	if (distance < 0)
		return (1);
	colors[ALP] = 0;
	colors[RED] = 0;
	colors[GRN] = 0;
	colors[BLU] = 0;
	if (distance > 0)
	{
		colors[ALP] = ((color_b >> 24 & 0xff) - (color_a >> 24 & 0xff));
		colors[RED] = ((color_b >> 16 & 0xff) - (color_a >> 16 & 0xff));
		colors[GRN] = ((color_b >> 8 & 0xff) - (color_a >> 8 & 0xff));
		colors[BLU] = ((color_b & 0xff) - (color_a >> 0 & 0xff));
	}
	if (distance == 0)
		distance++;
	increment[ALP] = (colors[ALP] / distance);
	increment[RED] = (colors[RED] / distance);
	increment[GRN] = (colors[GRN] / distance);
	increment[BLU] = (colors[BLU] / distance);
	return (0);
}

/**
 * get_gradient_color - return a gradient color
 * @color_i:	value the of initial color
 * @position:	value to make de gradient color;
 * @increment:	the increment ARGB to increment in the color_t
 *
 * Return: a gradient color
 */
int	get_gradient_color(int color_i, int position, double increment[4])
{
	unsigned char	argb[4];

	argb[ALP] = round(((color_i >> 24 & 0xff) + (position * increment[ALP])));
	argb[RED] = round(((color_i >> 16 & 0xff) + (position * increment[RED])));
	argb[GRN] = round(((color_i >> 8 & 0xff) + (position * increment[GRN])));
	argb[BLU] = round(((color_i & 0xff) + (position * increment[BLU])));
	return (argb[ALP] << 24 | argb[RED] << 16 | argb[GRN] << 8 | argb[BLU]);
}
