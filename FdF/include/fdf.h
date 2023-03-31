/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 22:01:26 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/03/21 22:01:27 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define X 0
# define Y 1
# define Z 2
# define Z_MIN 3

# define LON 0
# define LAT 1

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

typedef struct s_map
{
	t_point	*points;
	t_point	*points_draw;
	int		points_size;
	int		size[4];	
	double	ang[3];
	int		center_win[2];
	double	scale;
}	t_map;

typedef struct s_file
{
	char	*name;
	char	*data;
}	t_file;

typedef struct s_fdf
{
	t_window	window;
	t_map		map;
	t_file		file;
}	t_fdf;

void	start(int argc, char *argv[]);
int		terminate(t_fdf *fdf);

#endif
