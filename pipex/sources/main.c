/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:26:59 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/04/21 22:46:17 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
#include "../include/errors.h"
#include "../include/path.h"
#include "../include/process.h"
#include "../include/utils.h"
#include "../libs/libft/libft.h"

#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdio.h>

/**
 * check_param - 
 *
 */
void	check_param(int argc, char *env[])
{
	if (argc != 5)
	{
		program_error(0, "\tUsage:./pipex file1 \"cmd1\" \"cmd2\" file2\n\n"\
		"\tfile1: input file to first cmd1\n"\
		"\tcmd1: first command for pipe with or without parameters examples:"\
		" \"ls\"  \"ls -l\"\n"\
		"\tcmd2: last command for pipe with or without parameters examples:"\
		" \"ls\"  \"wc -c\"\n" \
		"\tfile2: output file to last cmd2\n", 0, 1);
	}	
	if (!env || !env[0])
		program_error(0, "Not variable env...", 0, 1);
}

/**
 * get_list_commands - 
 *
 */
static char	**get_list_commands(int argc, char *argv[])
{
	size_t	amount_commands;
	size_t	count;
	char	**list_commands;

	amount_commands = argc - 3;
	count = 0;
	argv += 2;
	list_commands = ft_calloc(sizeof(*argv), amount_commands + 1);
	while (count < amount_commands)
	{
		list_commands[count] = ft_strdup(argv[count]);
		count++;
	}
	return (list_commands);
}

/**
 * io - open de file in and file out files
 *
 * @pipex:	pointer to pipex struct
 * @argv:	argv to get the file name.
 */
static void	io(t_pipex *pipex, char *argv[])
{
	pipex->file_fds[0] = open(argv[1], O_RDONLY);
	if (pipex->file_fds[0] < 0)
		syscall_error(0, argv[1], 0);
	pipex->file_fds[1] = open(argv[4], O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (pipex->file_fds[1] < 0)
		syscall_error(0, argv[4], 0);
}

int	main(int argc, char *argv[], char *env[])
{
	int		exit_code;
	t_pipex	pipex;

	check_param(argc, argv);
	start_pipex(&pipex);
	pipex.process.path = NULL;
	pipex.process.argv = NULL;
	pipex.env = env;
	pipex.list_commands = get_list_commands(argc, argv);
	if (!pipex.list_commands)
		program_error(&pipex, "list_commands malloc error!", 0, 1);
	io(&pipex, argv);
	pipeline(&pipex);
	exit_code = pipex.last_cmd_exit_code;
	free_pipex(&pipex);
	return (exit_code);
}
