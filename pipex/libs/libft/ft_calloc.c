/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 11:31:23 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/04/13 13:40:20 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	byte;
	void	*p;

	byte = nmemb * size;
	if (!byte)
	{
		byte = 1;
		p = malloc(byte);
	}
	else
	{	
		if (byte / size != nmemb)
			return ((void *)0);
		p = malloc(byte);
	}
	if (p)
		ft_bzero(p, byte);
	return (p);
}
