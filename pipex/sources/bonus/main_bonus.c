/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:26:59 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/04/21 23:21:17 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"
#include "../../include/path.h"
#include "../../include/errors.h"
#include "../../include/bonus/heredoc_bonus.h"
#include "../../libs/libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>

/**
 * check_param - 
 *
 */
static void	check_param(int argc, char *argv[], char *env[])
{
	if (argc < 5 || (argc < 6 && (!ft_strncmp(argv[1], "here_doc", 9))))
	{
		program_error(0, "\tUsage: ./pipex {[here_doc LIMITER] | [file_in]}"\
			" cmd1 cmd2 [... cmdn] file_out\n", 0, 1);
	}	
	if (!env || !env[0])
		program_error(0, "Not variable env...", 0, 1);
}

/**
 * get_list_commands - 
 *
 */
static char	**get_list_commands(int argc, char *argv[], int heredoc)
{
	size_t	amount_commands;
	size_t	count;
	char	**list_commands;

	amount_commands = argc - (3 + heredoc);
	count = 0;
	argv += (2 + heredoc);
	list_commands = ft_calloc(sizeof(*argv), amount_commands + 1);
	while (count < amount_commands)
	{
		list_commands[count] = ft_strdup(argv[count]);
		count++;
	}
	return (list_commands);
}

static void	io(t_pipex *pipex, int argc, char *argv[])
{
	int	open_cf;

	open_cf = (O_WRONLY | O_CREAT);
	if (!ft_strncmp(argv[1], "here_doc", 9))
	{
		pipex->file_fds[0] = heredoc(argv[2]);
		if (pipex->file_fds[0] < 0)
			syscall_error(0, argv[1], 0);
		pipex->file_fds[1] = open(argv[argc - 1], open_cf | O_APPEND, 0644);
		if (pipex->file_fds[1] < 0)
			syscall_error(0, argv[argc - 1], 0);
	}
	else
	{
		pipex->file_fds[0] = open(argv[1], O_RDONLY);
		if (pipex->file_fds[0] < 0)
			syscall_error(0, argv[1], 0);
		pipex->file_fds[1] = open(argv[argc -1], open_cf | O_TRUNC, 0644);
		if (pipex->file_fds[1] < 0)
			syscall_error(0, argv[argc - 1], 0);
	}
}

int	main(int argc, char *argv[], char *env[])
{
	int		exit_code;
	int		heredoc;
	t_pipex	pipex;

	check_param(argc, argv, env);
	heredoc = (!ft_strncmp(argv[1], "here_doc", 9));
	start_pipex(&pipex);
	pipex.process.path = NULL;
	pipex.process.argv = NULL;
	pipex.env = env;
	pipex.list_commands = get_list_commands(argc, argv, heredoc);
	if (!pipex.list_commands)
		program_error(&pipex, "list_commands malloc error!", 0, 1);
	io(&pipex, argc, argv);
	pipeline(&pipex);
	exit_code = pipex.last_cmd_exit_code;
	free_pipex(&pipex);
	return (exit_code);
}
