/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 10:41:05 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/03/22 10:41:11 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/utils.h"
#include "../libs/libft/libft.h"
#include <stdlib.h>

void	free_split(char **ptr)
{
	int	i;

	if (!ptr)
		return ;
	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free (ptr);
}

int	is_hex_digit(int ch)
{
	if (ft_isdigit(ch))
		return (ch - '0');
	if (ch >= 'a' && ch <= 'f')
		return ((ch - 'a') + 10);
	if (ch >= 'A' && ch <= 'F')
		return ((ch - 'A') + 10);
	return (-1);
}

int	get_hex_value(char *str)
{
	int		int_to_return;

	int_to_return = 0;
	str += 2;
	while (*str)
	{
		int_to_return = (int_to_return * 16) + is_hex_digit(*str);
		str++;
	}
	return (int_to_return);
}
