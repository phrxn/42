/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:10:47 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/03/22 11:11:06 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/bonus/menu_bonus.h"
#include "../../include/bonus/draw_pixel_bonus.h"
#include "../../include/bonus/fdf_bonus.h"
#include "../../include/bonus/window_bonus.h"
#include "../../libs/minilibx-linux/mlx.h"

static void	put_str(t_fdf *fdf, char *str, int x, int y)
{
	mlx_string_put(fdf->window.mlx, fdf->window.window, x, y, 0x00FFFFFF, str);
}

static void	put_str_c(t_fdf *fdf, char *str, int x, int y)
{
	mlx_string_put(fdf->window.mlx, fdf->window.window, x, y, 0x0000A8FF, str);
}

void	menu_show_info3(t_fdf *fdf)
{
	put_str_c(fdf, "t", 164, 297);
	put_str(fdf, "]", 170, 297);
	put_str(fdf, "        Menu alpha:", 0, 317);
	put_str(fdf, "Keys: [", 2, 329);
	put_str_c(fdf, "m", 44, 329);
	put_str(fdf, "]", 50, 329);
}

void	menu_show_info2(t_fdf *fdf)
{
	put_str(fdf, "Keys: [", 2, 165);
	put_str_c(fdf, ",", 44, 165);
	put_str(fdf, "][", 50, 165);
	put_str_c(fdf, ".", 62, 165);
	put_str(fdf, "]", 68, 165);
	put_str(fdf, "         Resize and center:", 0, 185);
	put_str(fdf, "Keys: [", 2, 197);
	put_str_c(fdf, "r", 44, 197);
	put_str(fdf, "]", 50, 197);
	put_str(fdf, "Mouse: ", 2, 209);
	put_str_c(fdf, "button 3", 44, 209);
	put_str(fdf, "           Move:", 0, 229);
	put_str(fdf, "Keys: ", 2, 241);
	put_str_c(fdf, "arrows", 44, 241);
	put_str(fdf, "Mouse: ", 2, 253);
	put_str_c(fdf, "button 1", 44, 253);
	put_str(fdf, "(click, hold, drag", 98, 253);
	put_str(fdf, "and drop.)", 104, 265);
	put_str(fdf, "           Projections:", 0, 285);
	put_str(fdf, "Keys: ISO[", 2, 297);
	put_str_c(fdf, "i", 62, 297);
	put_str(fdf, "] SPHERE[", 68, 297);
	put_str_c(fdf, "g", 122, 297);
	put_str(fdf, "] TOP[", 128, 297);
	menu_show_info3(fdf);
}

void	menu_show_info(t_fdf *fdf)
{
	put_str(fdf, "           /// MENU ///", 0, 15);
	put_str(fdf, "              Exit:", 0, 35);
	put_str(fdf, "Key:  [", 2, 45);
	put_str_c(fdf, "ESC", 44, 45);
	put_str(fdf, "]", 62, 45);
	put_str(fdf, "Window: ", 2, 57);
	put_str_c(fdf, "close button", 54, 57);
	put_str(fdf, "            Rotation:", 0, 77);
	put_str(fdf, "Keys: X:[", 2, 89);
	put_str_c(fdf, "w s", 56, 89);
	put_str(fdf, "] Y:[", 74, 89);
	put_str_c(fdf, "q c", 104, 89);
	put_str(fdf, "] Z:[", 122, 89);
	put_str_c(fdf, "a d", 152, 89);
	put_str(fdf, "]", 170, 89);
	put_str(fdf, "              Zoom:", 0, 109);
	put_str(fdf, "Keys: [", 2, 121);
	put_str_c(fdf, "-", 44, 121);
	put_str(fdf, "][", 50, 121);
	put_str_c(fdf, "+", 62, 121);
	put_str(fdf, "]", 68, 121);
	put_str(fdf, "Mouse: ", 2, 133);
	put_str_c(fdf, "scroll", 44, 133);
	put_str(fdf, "         Z incre/decre:", 0, 153);
	menu_show_info2(fdf);
}
