/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 12:31:18 by dmanoel-          #+#    #+#             */
/*   Updated: 2022/09/16 11:34:39 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new_s;
	unsigned int	count;

	count = 0;
	new_s = ft_strdup(s);
	if (!new_s)
		return (new_s);
	while (new_s[count])
	{
		new_s[count] = f(count, s[count]);
		count++;
	}
	return (new_s);
}
