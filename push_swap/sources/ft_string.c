/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 23:46:23 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/06/27 16:29:42 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_string.h"
#include <unistd.h>

void	put_string(const char *str, int fd)
{
	while (*str)
	{
		write(fd, str, 1);
		str++;
	}
}
