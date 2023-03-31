/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 22:04:49 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/03/21 22:04:51 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_BONUS_H
# define MATRIX_BONUS_H
# include "fdf_bonus.h"

void	x_rotation(t_point *points, int size, double ang);

void	y_rotation(t_point *points, int size, double ang);

void	z_rotation(t_point *points, int size, double ang);

void	scale(t_point *points, int size, int scale);

void	translation(t_point *points, int size, const t_point *new_coor);

#endif
