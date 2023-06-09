/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:27:52 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/04/25 21:57:34 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/utils.h"
#include "../include/pipex.h"
#include "../libs/libft/libft.h"

#include <stddef.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

void	print_message(int fd, char *msg)
{
	if (msg && fd >= 0)
		write(fd, msg, ft_strlen(msg));
}

void	free_list_commands(char ***list_commands)
{
	size_t	size;
	char	**list;

	size = 0;
	list = *list_commands;
	if (!list)
		return ;
	while (list[size])
		free(list[size++]);
	free(list);
	*list_commands = NULL;
}
