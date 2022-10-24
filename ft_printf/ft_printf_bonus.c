/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 10:56:42 by dmanoel-          #+#    #+#             */
/*   Updated: 2022/10/24 13:55:14 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	print_invalid_spec(int *wrt, t_printf *p_args, t_printf tmp_p_args);

static void	width_and_precision(const char **format, t_printf *p_args);

static void	flags_handler(const char **format, t_printf *p_args);

static void	do_printf(int *wrt, t_printf *p_args, va_list args);

static void	print_invalid_spec(int *wrt, t_printf *p_args, t_printf tmp_p_args)
{	
	tmp_p_args.width = 0;
	tmp_p_args.precision = 0;
	tmp_p_args.flags = 0;
	tmp_p_args.spec = 'd';
	ft_fill(wrt, '%', 1);
	if (p_args->flags & FLAGS_HASHTAG)
		ft_fill(wrt, '#', 1);
	if (p_args->flags & FLAGS_SPACE && !(p_args->flags & FLAGS_PLUS))
		ft_fill(wrt, ' ', 1);
	if (p_args->flags & FLAGS_PLUS)
		ft_fill(wrt, '+', 1);
	if (p_args->flags & FLAGS_MINUS)
		ft_fill(wrt, '-', 1);
	if (p_args->flags & FLAGS_ZEROPAD && !(p_args->flags & FLAGS_MINUS))
		ft_fill(wrt, '0', 1);
	if (p_args->width > 0)
		itoa(wrt, &tmp_p_args, p_args->width, 0);
	if (p_args->flags & FLAGS_PRECISION)
	{
		ft_fill(wrt, '.', 1);
		itoa(wrt, &tmp_p_args, p_args->precision, 0);
	}
	ft_fill(wrt, p_args->spec, 1);
}

static void	width_and_precision(const char **format, t_printf *p_args)
{
	p_args->width = 0;
	p_args->precision = 0;
	while (**format >= '0' && **format <= '9')
		p_args->width = p_args->width * 10 + (*((*format)++) - '0');
	if (**format == '.')
	{
		(*format)++;
		while (**format >= '0' && **format <= '9')
			p_args->precision = p_args->precision * 10 + (*((*format)++) - '0');
		p_args->flags |= FLAGS_PRECISION;
	}
	if (**format)
		p_args->spec = *((*format)++);
	else
		p_args->spec = 0;
}

static void	flags_handler(const char **format, t_printf *p_args)
{
	p_args->flags = 0;
	while (**format)
	{
		if (**format != ' ' && **format != '0' && **format != '#' && \
			**format != '-' && **format != '+')
			break ;
		else if (**format == '#')
			p_args->flags |= FLAGS_HASHTAG;
		else if (**format == ' ')
			p_args->flags |= FLAGS_SPACE;
		else if (**format == '+')
			p_args->flags |= FLAGS_PLUS;
		else if (**format == '-')
			p_args->flags |= FLAGS_MINUS;
		else if (**format == '0')
			p_args->flags |= FLAGS_ZEROPAD;
		(*format)++;
	}
	width_and_precision(format, p_args);
}

static void	do_printf(int *wrt, t_printf *p_args, va_list args)
{
	long	decimal;

	if (p_args->spec == '%')
		ft_fill(wrt, '%', 1);
	else if (p_args->spec == 's')
		print_string(wrt, p_args, va_arg(args, char *));
	else if (p_args->spec == 'c')
		print_char(wrt, p_args, (char) va_arg(args, int));
	else if (p_args->spec == 'p')
		itoa(wrt, p_args, (long) va_arg(args, void *), 0);
	else if (p_args->spec == 'x' || p_args->spec == 'X' || p_args->spec == 'u')
		itoa(wrt, p_args, (unsigned int) va_arg(args, int), 0);
	else if (p_args->spec == 'd' || p_args->spec == 'i')
	{
		decimal = va_arg(args, int);
		if (decimal < 0)
			itoa(wrt, p_args, (decimal * -1), 1);
		else
			itoa(wrt, p_args, decimal, 0);
	}
	else if (p_args->spec)
		print_invalid_spec(wrt, p_args, *p_args);
	else
		*wrt = -1;
}

int	ft_printf(const char *format, ...)
{
	int			returnz;
	va_list		args;
	t_printf	p_args;

	if (!format)
		return (-1);
	returnz = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format != '%')
			ft_fill(&returnz, *format, 1);
		else if (format[1] == 0)
			returnz = -1;
		else
		{
			format++;
			flags_handler(&format, &p_args);
			do_printf(&returnz, &p_args, args);
			continue ;
		}
		format++;
	}
	va_end(args);
	return (returnz);
}
