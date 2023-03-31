/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:41:21 by dmanoel-          #+#    #+#             */
/*   Updated: 2022/09/16 10:27:08 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	new_str_size;

	new_str_size = ft_strlen(s1) + ft_strlen(s2) + 1;
	new_str = ft_calloc(new_str_size, sizeof(*new_str));
	if (!new_str)
		return (new_str);
	ft_strlcat(new_str, s1, new_str_size);
	ft_strlcat(new_str, s2, new_str_size);
	return (new_str);
}
