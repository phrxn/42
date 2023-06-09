/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dupz.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 21:46:38 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/04/25 21:50:16 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/dupz.h"
#include "../include/process.h"
#include "../include/pipex.h"
#include "../include/errors.h"

void	dupz(t_pipex *pipex, char *msg_to_perror, int oldfd, int newfd)
{
	if (dup2(oldfd, newfd) == -1)
		syscall_error(pipex, msg_to_perror, 1);
}
