/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 09:08:17 by dmanoel-          #+#    #+#             */
/*   Updated: 2022/09/15 14:49:47 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**create(const char *start, char c, size_t str_index)
{
	char		**split;
	const char	*end;
	size_t		str_size;

	while (*start && *start == c)
		start++;
	end = start;
	while (*end && *end != c)
		end++;
	str_size = end - start;
	if (str_size)
		split = create(end, c, str_index + 1);
	else
		split = ft_calloc(str_index + 1, sizeof(*split));
	if (split && str_size)
	{
		split[str_index] = ft_substr(start, 0, str_size);
		if (split[str_index])
			return (split);
		while (split[++str_index])
			free(split[str_index]);
		free(split);
		split = 0;
	}
	return (split);
}

char	**ft_split(char const *s, char c)
{
	return (create(s, c, 0));
}
