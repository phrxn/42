/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 17:31:15 by dmanoel-          #+#    #+#             */
/*   Updated: 2022/09/19 09:49:33 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *p, int ch)
{
	char	c;

	c = (char)ch;
	while (*p && *p != c)
		p++;
	if (*p == c)
		return ((char *)p);
	else
		return ((void *)0);
}
