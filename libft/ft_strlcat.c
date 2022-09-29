/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 16:47:41 by dmanoel-          #+#    #+#             */
/*   Updated: 2022/09/17 00:20:52 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t maxlen)
{
	size_t	dst_size;
	size_t	maxlen_tmp;

	dst_size = 0;
	maxlen_tmp = maxlen;
	while (maxlen_tmp-- && dst[dst_size])
		dst_size++;
	if (dst_size == maxlen)
		return (dst_size + ft_strlen(src));
	return (dst_size + ft_strlcpy(dst + dst_size, src, maxlen - dst_size));
}
