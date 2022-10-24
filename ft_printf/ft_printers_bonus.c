/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printers_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 10:56:12 by dmanoel-          #+#    #+#             */
/*   Updated: 2022/10/18 15:19:45 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	print_address(int *wrt, t_printf *p_args, char *number)
{
	if (!(*number && *number != '0'))
		return (print_address_nil(wrt, p_args, number));
	else if (p_args->precision >= ft_strlen(number))
		p_args->width -= p_args->precision;
	else
		p_args->width -= ft_strlen(number);
	if ((p_args->flags & FLAGS_PLUS || p_args->flags & FLAGS_SPACE))
		p_args->width--;
	p_args->precision = p_args->precision - ft_strlen(number);
	if (!(p_args->flags & FLAGS_MINUS) && !(p_args->flags & FLAGS_ZEROPAD))
		ft_fill(wrt, ' ', p_args->width - 2);
	if ((p_args->flags & FLAGS_PLUS))
		ft_fill(wrt, '+', 1);
	else if ((p_args->flags & FLAGS_SPACE))
		ft_fill(wrt, ' ', 1);
	ft_output(wrt, "0x", ft_strlen("0x"));
	if (p_args->flags & FLAGS_ZEROPAD)
		ft_fill(wrt, '0', p_args->width - 2);
	ft_fill(wrt, '0', p_args->precision);
	ft_output(wrt, number, ft_strlen(number));
	if (p_args->flags & FLAGS_MINUS)
		ft_fill(wrt, ' ', p_args->width -2);
}

void	print_address_nil(int *wrt, t_printf *p_args, char *number)
{
	p_args->width -= 5;
	p_args->precision = p_args->precision - ft_strlen(number);
	if (!(p_args->flags & FLAGS_MINUS) || p_args->flags & FLAGS_ZEROPAD)
		ft_fill(wrt, ' ', p_args->width);
	ft_output(wrt, "(nil)", ft_strlen("(nil)"));
	if (p_args->flags & FLAGS_MINUS)
		ft_fill(wrt, ' ', p_args->width);
}	

void	print_decimal(int *wrt, t_printf *p_args, char *number, int is_neg)
{
	if (p_args->spec == 'u')
		p_args->flags &= ~(FLAGS_PLUS | FLAGS_SPACE);
	if (p_args->flags & FLAGS_PRECISION || p_args->flags & FLAGS_MINUS)
		p_args->flags &= ~FLAGS_ZEROPAD;
	if (p_args->flags & FLAGS_PLUS || p_args->flags & FLAGS_SPACE || is_neg)
		p_args->width--;
	if (p_args->precision >= ft_strlen(number))
		p_args->width -= p_args->precision;
	else
		p_args->width -= ft_strlen(number);
	p_args->precision = p_args->precision - ft_strlen(number);
	if (!(p_args->flags & FLAGS_MINUS) && !(p_args->flags & FLAGS_ZEROPAD))
		ft_fill(wrt, ' ', p_args->width);
	if (is_neg)
		ft_fill(wrt, '-', 1);
	else if (p_args->flags & FLAGS_PLUS)
		ft_fill(wrt, '+', 1);
	else if (p_args->flags & FLAGS_SPACE)
		ft_fill(wrt, ' ', 1);
	if (p_args->flags & FLAGS_ZEROPAD)
		ft_fill(wrt, '0', p_args->width);
	ft_fill(wrt, '0', p_args->precision);
	ft_output(wrt, number, ft_strlen(number));
	if (p_args->flags & FLAGS_MINUS)
		ft_fill(wrt, ' ', p_args->width);
}

void	print_hexdecimal(int *wrt, t_printf *p_args, char *number)
{
	if (!(*number && *number != '0'))
		p_args->flags &= ~FLAGS_HASHTAG;
	if (p_args->flags & FLAGS_PRECISION || p_args->flags & FLAGS_MINUS)
		p_args->flags &= ~FLAGS_ZEROPAD;
	if (p_args->spec == 'p')
		return (print_address(wrt, p_args, number));
	if (p_args->flags & FLAGS_HASHTAG)
		p_args->width -= 2;
	if (p_args->precision >= ft_strlen(number))
		p_args->width -= p_args->precision;
	else
		p_args->width -= ft_strlen(number);
	p_args->precision = p_args->precision - ft_strlen(number);
	if (!(p_args->flags & FLAGS_MINUS) && !(p_args->flags & FLAGS_ZEROPAD))
		ft_fill(wrt, ' ', p_args->width);
	if ((p_args->flags & FLAGS_HASHTAG) && p_args->spec == 'x')
		ft_output(wrt, "0x", ft_strlen("0x"));
	else if (p_args->flags & FLAGS_HASHTAG)
		ft_output(wrt, "0X", ft_strlen("0x"));
	if (p_args->flags & FLAGS_ZEROPAD)
		ft_fill(wrt, '0', p_args->width);
	ft_fill(wrt, '0', p_args->precision);
	ft_output(wrt, number, ft_strlen(number));
	if (p_args->flags & FLAGS_MINUS)
		ft_fill(wrt, ' ', p_args->width);
}

void	print_string(int *wrt, t_printf *p_args, char *str)
{
	size_t	chars_to_print;

	if (p_args->flags & FLAGS_PRECISION && !str && p_args->precision >= 6)
		chars_to_print = 6;
	else if (p_args->flags & FLAGS_PRECISION && !str)
		chars_to_print = 0;
	else if (p_args->flags & FLAGS_PRECISION && ft_strlen(str) > \
			p_args->precision)
		chars_to_print = p_args->precision;
	else if (!str)
		chars_to_print = 6;
	else
		chars_to_print = ft_strlen(str);
	p_args->width -= chars_to_print;
	if (!(p_args->flags & FLAGS_MINUS))
		ft_fill(wrt, ' ', p_args->width);
	if (str)
		while (chars_to_print--)
			ft_fill(wrt, *str++, 1);
	else if ((p_args->flags & FLAGS_PRECISION && p_args->precision >= 6) || \
			!(p_args->flags & FLAGS_PRECISION))
		ft_output(wrt, "(null)", ft_strlen("(null)"));
	if (p_args->flags & FLAGS_MINUS)
		ft_fill(wrt, ' ', p_args->width);
}
