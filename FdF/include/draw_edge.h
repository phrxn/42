/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_edge.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 22:00:36 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/03/21 22:00:38 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_EDGE_H
# define DRAW_EDGE_H
# ifndef BONUS
#  include "fdf.h"
# endif
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

void	create_edge(t_window *window, t_point point1, t_point point2);

#endif
