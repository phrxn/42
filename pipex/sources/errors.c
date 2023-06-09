/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 21:28:54 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/04/21 21:37:07 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/errors.h"
#include "../include/pipex.h"
#include "../include/process.h"
#include "../include/utils.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * syscall_error -	call perror to show system call and can close the program.
 *					If is to exit, the pipex struct and process are freed.
 * @pipex:		pointer to pipex struct.
 * @msg:		message to show in the perror.
 * @is_to_exit:	if is to close the program. if 1 the structs are freed and the
 *				program is closed.
 */
void	syscall_error(t_pipex *pipex, char *msg_to_perror, int is_to_exit)
{
	print_message(2, NAME);
	print_message(2, ": ");
	perror(msg_to_perror);
	if (is_to_exit)
	{
		if (pipex)
		{
			free_pipex(pipex);
			free_process(&pipex->process);
		}
		exit(1);
	}
}

/**
 * program_error - show a message erro no stderr, and can close the program.
 * @pipex:		pointer to pipex struct.
 * @msg1:		message 1 to show in stderr. If NULL nothing is printed.
 * @msg2:		message 2 to show in stderr. If NULL nothing is printed.
 * @is_to_exit:	if is to close the program. if 1 the structs are freed and the
 *				program is closed.
 */
void	program_error(t_pipex *pipex, char *msg1, char *msg2, int is_to_exit)
{
	if (msg1 && msg2)
	{
		print_message(2, NAME);
		print_message(2, ": ");
	}
	if (msg1)
		print_message(2, msg1);
	if (msg2)
		print_message(2, msg2);
	if (is_to_exit)
	{
		if (pipex)
		{
			free_pipex(pipex);
			free_process(&pipex->process);
		}
		exit(1);
	}
}
