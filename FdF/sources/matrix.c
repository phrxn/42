/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 10:38:27 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/03/22 10:38:29 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/matrix.h"
#include <math.h>

/*
         [1     0      0]
   X     [0  cos0  -sin0]
         [0  sin0   cos0]
*/
void	x_rotation(t_point *points, int size, double ang)
{
	double	tmp_y;
	double	pcos;
	double	psin;
	double	nsin;
	double	rad;

	rad = ang * M_PI / 180;
	pcos = cos(rad);
	psin = sin(rad);
	nsin = -sin(rad);
	while (size--)
	{
		tmp_y = points[size].coor[Y];
		points[size].coor[Y] = pcos * tmp_y + nsin * points[size].coor[Z];
		points[size].coor[Z] = psin * tmp_y + pcos * points[size].coor[Z];
	}
}

/*
         [cos0  0   sin0]
   Y     [0     1      0]
         [-sin0 0   cos0]
*/
void	y_rotation(t_point *points, int size, double ang)
{
	double	tmp_x;
	double	pcos;
	double	psin;
	double	nsin;
	double	rad;

	rad = ang * M_PI / 180;
	pcos = cos(rad);
	psin = sin(rad);
	nsin = -sin(rad);
	while (size--)
	{
		tmp_x = points[size].coor[X];
		points[size].coor[X] = pcos * tmp_x + psin * points[size].coor[Z];
		points[size].coor[Z] = nsin * tmp_x + pcos * points[size].coor[Z];
	}
}

/*
         [cos0  -sin0  0]
   Z     [sin0   cos0  0]
         [0     0      1]
*/
void	z_rotation(t_point *points, int size, double ang)
{
	double	tmp_x;
	double	pcos;
	double	psin;
	double	nsin;
	double	rad;

	rad = ang * M_PI / 180;
	pcos = cos(rad);
	psin = sin(rad);
	nsin = -sin(rad);
	while (size--)
	{
		tmp_x = points[size].coor[X];
		points[size].coor[X] = pcos * tmp_x + nsin * points[size].coor[Y];
		points[size].coor[Y] = psin * tmp_x + pcos * points[size].coor[Y];
	}
}

/*
         [Sx  0   0   0]
         [0   Sy  0   0]
         [0   0   Sz  0]
         [0   0   0   1]
*/
void	scale(t_point *points, int size, int scale)
{
	while (size--)
	{
		points[size].coor[X] *= scale;
		points[size].coor[Y] *= scale;
		points[size].coor[Z] *= scale;
	}
}

/*
         [1   0   0  Tx]
         [0   1   0  Ty]
         [0   0   1  Tz]
         [0   0   0   1]
*/
void	translation(t_point *points, int size, const t_point *new_coor)
{
	while (size--)
	{
		points[size].coor[X] = new_coor->coor[X] + points[size].coor[X];
		points[size].coor[Y] = new_coor->coor[Y] + points[size].coor[Y];
	}
}
