/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 10:57:12 by dmanoel-          #+#    #+#             */
/*   Updated: 2022/10/18 15:15:27 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H
# include <unistd.h>
# include <stdarg.h>

# define FLAGS_SPACE (1U)
# define FLAGS_ZEROPAD (2U)
# define FLAGS_HASHTAG (4U)
# define FLAGS_MINUS (8U)
# define FLAGS_PLUS (16U)
# define FLAGS_PRECISION (32U)

# define INT_DIGITS_BUFFER_SIZE 21

typedef struct s_printf
{
	unsigned int	flags;
	int				width;
	int				precision;
	char			spec;
}	t_printf;

typedef struct s_itoa_args
{
	char			str[INT_DIGITS_BUFFER_SIZE];
	char			*pointer;
	int				base;
}	t_itoa_args;	

void	print_address(int *wrt, t_printf *p_args, char *number);

void	print_address_nil(int *wrt, t_printf *p_args, char *number);

void	print_decimal(int *wrt, t_printf *p_args, char *number, int is_neg);

void	print_hexdecimal(int *wrt, t_printf *p_args, char *number);

void	print_char(int *wrt, t_printf *p_args, char c);

void	print_string(int *wrt, t_printf *p_args, char *str);

int		ft_strlen(char *str);

void	ft_output(int *wrt, char *str, size_t size);

void	ft_fill(int *wrt, char c, int number);

void	itoa(int *wrt, t_printf *p_args, unsigned long number, int is_neg);

int		ft_printf(const char *format, ...);

#endif
