/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 22:29:12 by dmanoel-          #+#    #+#             */
/*   Updated: 2022/10/21 00:06:57 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# define INT_DIGITS_BUFFER_SIZE 21

typedef struct s_itoa_vars
{
	char			str[INT_DIGITS_BUFFER_SIZE];
	char			*pointer;
	char			isnegative;
	long unsigned	number;
	int				base;
}	t_itoa_vars;	

int	ft_printf(const char *format, ...) __attribute__((format(printf, 1, 2)));

#endif
