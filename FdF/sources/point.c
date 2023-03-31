/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 10:39:53 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/03/22 10:39:56 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/point.h"
#include "../include/utils.h"
#include "../libs/libft/libft.h"

static const char	*is_valid_number(const char *start, const char *end)
{
	if (((end - start) == 1) && ft_isdigit(*start))
		return (++start);
	if (*start != '-' && *start != '+' && !ft_isdigit(*start))
		return (0);
	if (*start == '-' || *start == '+')
		start++;
	while (ft_isdigit(*start))
		start++;
	return (start);
}

static int	is_valid_hexcolor(const char *start, const char *end)
{
	size_t	size_hex;

	size_hex = end - start;
	if ((size_hex != 4) && (size_hex != 6) && (size_hex != 8))
		return (0);
	if (*start++ != '0')
		return (0);
	if (*start != 'x' && *start != 'X')
		return (0);
	start++;
	while (is_hex_digit(*start) != -1)
		start++;
	return (!(end - start));
}

/**
 * is_point_valid - checks if a string or part of it is a valid point
 * @start: string start
 * @end:   end or part of the string (as far as to check)
 *
 * This method checks if a string is a valid point.
 * A valid point:
 * has a number starting (or not) with + or - sign.
 * It can have a hexdecimal value separated by a comma saying
 * the point's color.
 * This hexdecimal value starts with 0x or 0X and has a 
 * 6 hex digits [0-9][a-f][A-F] mixed in between them (or not)
 * e.g:
 * 		0x00ffAb
 * 		0xFa09CD
 * 		0xaa00f3
 * 		0XFABB03
 *
 * Return: 1 if the string is a valid point, 0 otherwise.
 */
int	is_point_valid(const char *start, const char *end)
{
	if (!(end - start))
		return (0);
	start = is_valid_number(start, end);
	if (!start)
		return (0);
	if ((end - start) == 0)
		return (1);
	if (*start++ != ',')
		return (0);
	return (is_valid_hexcolor(start, end));
}
