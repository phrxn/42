/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 11:31:23 by dmanoel-          #+#    #+#             */
/*   Updated: 2022/09/23 23:51:30 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	bytes;
	void	*p;

	bytes = nmemb * size;
	if (!bytes)
	{
		bytes = 1;
		p = malloc(bytes);
	}
	else
	{	
		if (bytes / size != nmemb)
			return ((void *)0);
		p = malloc(bytes);
	}
	if (p)
		ft_bzero(p, bytes);
	return (p);
}
