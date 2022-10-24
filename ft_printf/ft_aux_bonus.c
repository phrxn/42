/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:05:42 by dmanoel-          #+#    #+#             */
/*   Updated: 2022/10/21 00:08:20 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_strlen(char *str)
{
	size_t	size;

	size = 0;
	if (!str)
		return (size);
	while (str[size])
		size++;
	return (size);
}

/**
 * ft_output - write a string in default output
 *
 * @wrt:     pointer to int that hold how many chars was written 
 * @str:     string to write in the stdout
 */
void	ft_output(int *wrt, char *str, size_t size)
{
	*wrt += write(1, str, size);
}

/**
 * ft_fill - write in the default output a char N times.  
 *
 * @wrt:     pointer to int that hold how many chars was written 
 * @c:       char that will be written
 * @number:  how many times this X will be written
 */
void	ft_fill(int *wrt, char c, int number)
{
	while (number-- > 0)
		ft_output(wrt, &c, 1);
}

void	itoa(int *wrt, t_printf *p_args, unsigned long number, int is_neg)
{
	t_itoa_args	var;

	var.pointer = var.str + INT_DIGITS_BUFFER_SIZE;
	*--(var.pointer) = 0;
	var.base = 10;
	if (p_args->spec == 'x' || p_args->spec == 'X' || p_args->spec == 'p')
		var.base = 16;
	while (1)
	{
		*--(var.pointer) = (number % var.base) + '0';
		if (*var.pointer > '9' && (p_args->spec == 'x' || p_args->spec == 'p'))
			*var.pointer = (*var.pointer - ':') + 'a';
		else if (*var.pointer > '9' && p_args->spec == 'X')
			*var.pointer = (*var.pointer - ':') + 'A';
		number /= var.base;
		if (!number)
			break ;
	}
	if (p_args->flags & FLAGS_PRECISION)
		if (var.pointer[0] == '0' && p_args->precision == 0)
			(var.pointer)++;
	if (var.base == 16)
		print_hexdecimal(wrt, p_args, var.pointer);
	else
		print_decimal(wrt, p_args, var.pointer, is_neg);
}

void	print_char(int *wrt, t_printf *p_args, char c)
{
	if (!(p_args->flags & FLAGS_MINUS))
		ft_fill(wrt, ' ', p_args->width - 1);
	ft_fill(wrt, c, 1);
	if (p_args->flags & FLAGS_MINUS)
		ft_fill(wrt, ' ', p_args->width - 1);
}
