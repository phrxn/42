/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 22:04:28 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/03/21 22:04:31 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H

# define X 0
# define Y 1
# define Z 2
# define Z_MIN 3

# define LON 0
# define LAT 1

# define PROJ_ISO 0
# define PROJ_SPH 1
# define PROJ_TOP 2

typedef struct s_point
{
	double	coor[3];
	double	geo[2];
	int		color;
	char	has_color;
}	t_point;

typedef struct s_window
{
	void	*mlx;
	void	*window;
	void	*image;
	char	*addr;
	int		line_length;
	int		bits_per_pixel;
	int		endian;
}	t_window;

typedef struct s_mouse
{
	int	is_btn_1_pressed;
	int	is_btn_2_pressed;
	int	last_coor[2];
}	t_mouse;

typedef struct s_map
{
	t_point	*points;
	t_point	*points_draw;
	int		points_size;
	int		size[4];	
	double	ang[3];
	int		center_win[2];
	int		projection;
	int		is_show_negative_z;
	double	scale;
	double	zscale;
}	t_map;

typedef struct s_file
{
	char	*name;
	char	*data;
}	t_file;

typedef struct s_fdf
{
	t_window	window;
	t_mouse		mouse;
	t_map		map;
	t_file		file;
	int			menu_alpha;
}	t_fdf;

void	start(int argc, char *argv[]);

int		terminate(t_fdf *fdf);

#endif
