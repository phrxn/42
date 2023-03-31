/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 22:05:24 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/03/31 08:38:16 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_BONUS_H
# define WINDOW_BONUS_H
# include "fdf_bonus.h"

# define WIN_WID 1500
# define WIN_HEI 800
# define WIN_TIT "FdF - dmanoel-"

enum	e_events
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

void	create_window(t_fdf *fdf);

void	start_event_handlers(t_fdf *fdf);

#endif
