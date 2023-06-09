/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:28:51 by dmanoel-          #+#    #+#             */
/*   Updated: 2022/09/16 09:43:55 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const char	*s;
	char		*d;
	const char	*ls;
	char		*ld;

	s = (const char *) src;
	d = (char *) dest;
	ls = (const char *) src + n;
	ld = (char *) dest + n;
	if (dest < src)
		while (n--)
			*d++ = *s++;
	else
		while (n--)
			*--ld = *--ls;
	return (dest);
}
