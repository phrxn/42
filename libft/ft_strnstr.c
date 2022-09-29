/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 10:36:36 by dmanoel-          #+#    #+#             */
/*   Updated: 2022/09/23 22:52:55 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_size;

	little_size = ft_strlen(little);
	if (!little_size)
		return ((char *)big);
	if (*big)
	{
		while (len >= little_size && len--)
		{
			if (ft_memcmp(big, little, little_size))
				big++;
			else
				return ((char *)big);
		}
	}
	return ((void *)0);
}
