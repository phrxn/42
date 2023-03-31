/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_edge_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 22:02:33 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/03/21 22:02:34 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_EDGE_BONUS_H
# define DRAW_EDGE_BONUS_H
# include "fdf_bonus.h"

# define FALSE 0
# define TRUE 1

typedef struct s_brese
{
	int	deltax;
	int	deltay;
	int	signalx;
	int	signaly;
	int	interchange;
	int	error;
}	t_brese;

void	create_edge(t_fdf *fdf, t_point point1, t_point point2);

#endif
