/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:36:53 by dmanoel-          #+#    #+#             */
/*   Updated: 2022/10/24 13:57:48 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_text(const char *str, char spec)
{
	size_t	str_size;
	size_t	written;

	str_size = 0;
	written = 0;
	if (spec == 'c')
		return (write(1, str, 1));
	if (spec == 's' && !str)
		return (write(1, "(null)", 6));
	if (str)
		while (str[str_size])
			str_size++;
	if (spec == 'p' && str_size == 1 && str[0] == '0')
		return (write(1, "(nil)", 5));
	if (spec == 'p')
		written += write(1, "0x", 2);
	written += write(1, str, str_size);
	return (written);
}

static int	print_number(long num, char spec)
{
	t_itoa_vars	var;

	var.pointer = var.str + INT_DIGITS_BUFFER_SIZE;
	*--(var.pointer) = 0;
	var.number = num;
	var.base = 10;
	var.isnegative = ((spec == 'd' || spec == 'i') && num < 0);
	if (var.isnegative)
		var.number *= -1;
	if (spec == 'x' || spec == 'X' || spec == 'p')
		var.base = 16;
	while (1)
	{
		*--(var.pointer) = (var.number % var.base) + '0';
		if (*var.pointer > '9' && (spec == 'x' || spec == 'p'))
			*var.pointer = (*var.pointer - ':') + 'a';
		else if (*var.pointer > '9' && spec == 'X')
			*var.pointer = (*var.pointer - ':') + 'A';
		var.number /= var.base;
		if (!var.number)
			break ;
	}
	if (var.isnegative)
		*--(var.pointer) = '-';
	return (print_text(var.pointer, spec));
}

static void	do_printf(char spec, va_list args, int *returnz)
{
	int	temp;

	if (spec == '%')
		*returnz += print_text("%", 's');
	else if (spec == 's')
		*returnz += print_text(va_arg(args, char *), spec);
	else if (spec == 'c')
	{
		temp = va_arg(args, int);
		*returnz += print_text((char *)&temp, spec);
	}
	else if (spec == 'p')
		*returnz += print_number((long) va_arg(args, void *), spec);
	else if (spec == 'd' || spec == 'i')
		*returnz += print_number(va_arg(args, int), spec);
	else if (spec == 'u' || spec == 'x' || spec == 'X')
		*returnz += print_number((unsigned int)va_arg(args, int), spec);
	else
	{
		*returnz += print_text("%", spec);
		*returnz += print_text(&spec, 'c');
	}
}

int	ft_printf(const char *format, ...)
{
	int		returnz;
	va_list	args;

	if (!format)
		return (-1);
	returnz = 0;
	va_start(args, format);
	while (*format++)
	{
		if (format[-1] != '%')
			returnz += print_text(format - 1, 'c');
		else if (!*format)
			returnz = -1;
		else
			do_printf(*format++, args, &returnz);
	}
	va_end(args);
	return (returnz);
}
