/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:29:40 by dmanoel-          #+#    #+#             */
/*   Updated: 2022/09/19 09:05:13 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t maxlen)
{
	size_t	src_size;

	src_size = ft_strlen(src);
	if (src_size < maxlen)
		ft_memcpy(dst, src, src_size + 1);
	else if (maxlen)
	{
		ft_memcpy(dst, src, maxlen);
		dst[maxlen - 1] = 0;
	}
	return (src_size);
}
