/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 14:47:37 by dmanoel-          #+#    #+#             */
/*   Updated: 2022/09/26 09:36:41 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s_final;
	char	*new_s;
	size_t	needed_size;

	s_final = (char *)s;
	while (*s_final)
		s_final++;
	while (*s && start--)
		s++;
	needed_size = s_final - s;
	if (len > needed_size)
		len = needed_size;
	s_final = ft_calloc(len + 1, sizeof(*s));
	if (!s_final)
		return (s_final);
	new_s = s_final;
	if (!*s)
		return (s_final);
	while (len--)
		*s_final++ = *s++;
	return (new_s);
}
