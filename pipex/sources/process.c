/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 21:32:17 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/04/24 22:56:23 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/process.h"
#include "../include/errors.h"
#include "../include/pipex.h"
#include "../include/argv.h"
#include "../include/path.h"
#include "../include/utils.h"
#include "../libs/libft/libft.h"

/**
 * check_and_prepare_argv - replaces spaces within command arguments.
 * @pipex:		a pointer to struct pipex
 * @full_cmd:	full command with or without args.
 */
static char	check_and_prepare_argv(t_pipex *pipex, char *full_cmd)
{
	char	candidate;

	candidate = select_candidate(full_cmd);
	if (!candidate)
		program_error(pipex, "Could not find a valid character"
			" to separate the command line arguments.\n", 0, 1);
	if (apply_candidate(full_cmd, candidate))
		program_error(pipex, "quote and/or dquote opened.\n", 0, 1);
	return (candidate);
}

/**
 * prepare_process - fill a process struct with info that will used by execve
 * @process:	a pointer to pipex struct
 * @full_cmd:	a string containing a command with or without parameters.
 * 				e.g:	"cat" , "wc -c" , "./my_cmd" , "./my_cmd -a -b" ...
 * @env:		the environment variables
 */
void	prepare_process(t_pipex *pipex, char *full_cmd, int f_cmd, int l_cmd)
{
	char		**argv_splited;
	int			malloc_status;
	t_process	*process;
	char		candidate;

	malloc_status = 0;
	process = &pipex->process;
	candidate = check_and_prepare_argv(pipex, full_cmd);
	argv_splited = ft_split(full_cmd, ' ');
	if (!argv_splited)
		program_error(pipex, "split argv failed.\n", 0, 1);
	replace_candidate_to_space(argv_splited, candidate);
	process->path = get_cmd_fpath(argv_splited[0], pipex->env, &malloc_status);
	if (malloc_status)
		program_error(pipex, "Error while creating the path for the"\
		"command executable.?", 0, 1);
	process->argv = argv_splited;
	if (!process->path)
	{
		if ((f_cmd && pipex->file_fds[0] == -1)
			|| (l_cmd && pipex->file_fds[1] == -1))
			return ;
		else
			program_error(0, argv_splited[0], ": command not found\n", 0);
	}
}

void	free_process(t_process *process)
{
	size_t	count;

	if (!process)
		return ;
	count = 0;
	if (process->argv)
	{
		while (process->argv[count])
			free(process->argv[count++]);
		free(process->argv);
	}
	if (process->path)
		free(process->path);
	process->argv = NULL;
	process->path = NULL;
}
