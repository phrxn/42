/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 08:38:56 by dmanoel-          #+#    #+#             */
/*   Updated: 2022/09/14 17:18:00 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
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
	return (ft_strdup(pointer));
}
