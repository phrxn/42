/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:44:17 by dmanoel-          #+#    #+#             */
/*   Updated: 2022/09/16 10:13:36 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned const char	*source;
	unsigned char		content;

	source = (unsigned const char *) s;
	content = (unsigned char) c;
	while (n--)
	{
		if (*source == content)
			return ((void *) source);
		source++;
	}
	return ((void *)0);
}
