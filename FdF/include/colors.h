/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 22:00:31 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/03/21 22:00:32 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

# define ALP 0
# define RED 1
# define GRN 2
# define BLU 3

# define ZCOLORMAX 0x00ff0f00
# define ZCOLORZER 0x00ffd712
# define ZCOLORMIN 0x002026eb

# define BACKGROUND 0x00555555

int	get_increment(int color_a, int color_b, int distance, double increment[4]);

int	get_gradient_color(int color_i, int position, double increment[4]);

#endif
