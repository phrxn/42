/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 10:36:18 by dmanoel-          #+#    #+#             */
/*   Updated: 2022/09/16 10:36:02 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	s1_size;
	char	*s1_end;

	s1_size = ft_strlen(s1);
	s1_end = (char *) s1 + s1_size;
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	while (s1_end >= s1 && ft_strchr(set, *s1_end))
		s1_end--;
	s1_end++;
	s1_size = (s1_end - s1);
	s1_end = ft_calloc(s1_size + 1, sizeof(*s1_end));
	if (s1_end)
		ft_memcpy(s1_end, s1, s1_size);
	return (s1_end);
}
