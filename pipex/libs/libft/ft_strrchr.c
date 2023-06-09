/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 17:31:15 by dmanoel-          #+#    #+#             */
/*   Updated: 2022/09/19 10:29:06 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *p, int ch)
{
	char	*tmp_pointer;
	char	char_to_search;

	tmp_pointer = ((void *)0);
	char_to_search = (char)ch;
	while (1)
	{
		if (*p == char_to_search)
			tmp_pointer = (char *)p;
		if (*p++ == 0)
			return (tmp_pointer);
	}
}
