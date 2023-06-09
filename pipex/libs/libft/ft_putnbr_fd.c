/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 08:38:56 by dmanoel-          #+#    #+#             */
/*   Updated: 2022/09/14 17:15:36 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	number[INT_DIGITS_BUFFER_SIZE];
	char	*pointer;
	int		isnegative;

	pointer = number + INT_DIGITS_BUFFER_SIZE;
	*--pointer = 0;
	isnegative = (n < 0);
	while (1)
	{
		if (n > 0)
			*--pointer = '0' + (n % 10);
		else
			*--pointer = '0' - (n % 10);
		n /= 10;
		if (!n)
			break ;
	}
	if (isnegative)
		*--pointer = '-';
	ft_putstr_fd(pointer, fd);
}
