/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:29:40 by dmanoel-          #+#    #+#             */
/*   Updated: 2022/09/09 15:13:22 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*s_dup;
	size_t	s_dup_size;

	s_dup_size = ft_strlen(s) + 1;
	s_dup = ft_calloc(s_dup_size, sizeof(*s_dup));
	if (s_dup)
		ft_memcpy(s_dup, s, s_dup_size);
	return (s_dup);
}
