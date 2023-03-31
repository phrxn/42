/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 22:05:06 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/03/21 22:05:07 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MENU_BONUS_H
# define MENU_BONUS_H
# include "fdf_bonus.h"

# define LETTER_WIDTH 6
# define LETTER_HEIGHT 9

// 42 letters
# define MENU_WIDTH 210

# define BACKGROUND_MENU 0x00333333
# define BACKGROUND_KEY 0x00333333

void	menu_draw_background(t_fdf *fdf);

void	menu_show_info(t_fdf *fdf);

#endif
