/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 21:35:52 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/04/25 21:57:09 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
#include "../include/errors.h"
#include "../include/argv.h"
#include "../include/path.h"
#include "../include/process.h"
#include "../include/utils.h"
#include "../include/dupz.h"

#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

static void	child(t_pipex *pipex, char **list_cmds, size_t index_cmd)
{
	char		**env;

	env = pipex->env;
	if (pipex->fd_in == -1)
		program_error(pipex, 0, 0, 1);
	if (list_cmds[index_cmd + 1] && pipex->pipe_fds[1] == -1)
		program_error(pipex, 0, 0, 1);
	if (list_cmds[index_cmd + 1] == NULL && pipex->file_fds[1] == -1)
		program_error(pipex, 0, 0, 1);
	dupz(pipex, "dup fd_in", pipex->fd_in, 0);
	if (index_cmd > 0)
		close(pipex->fd_in);
	if (list_cmds[index_cmd + 1])
		dupz(pipex, "dup pipe_fds[1]", pipex->pipe_fds[1], 1);
	else
		dupz(pipex, "dup file_fds[1]", pipex->file_fds[1], 1);
	free_pipex(pipex);
	if (pipex->process.path)
		execve(pipex->process.path, pipex->process.argv, env);
	if (pipex->process.path)
		syscall_error(pipex, "execve", 0);
	free_process(&pipex->process);
	exit(127);
}

static void	parent(t_pipex *pipex, char **list_cmds, size_t index_cmd)
{
	int	status;

	status = -1;
	pipex->last_cmd_exit_code = 1;
	if (index_cmd > 0 && pipex->fd_in >= 0)
		close(pipex->fd_in);
	pipex->fd_in = pipex->pipe_fds[0];
	close(pipex->pipe_fds[1]);
	pipex->pipe_fds[1] = -1;
	if (list_cmds[index_cmd + 1] == NULL)
	{
		if (waitpid(pipex->pid, &status, 0) == -1)
			syscall_error(pipex, "waitpid", 1);
		if (WIFEXITED(status))
			pipex->last_cmd_exit_code = WEXITSTATUS(status);
	}
}

/**
 * pipeline - make the pipeline
 * @pipex:	pointer to struct with informations to help create the pipeline.
 *
 * Return:
 *		the last children's exit code.
 */
void	pipeline(t_pipex *pipex)
{
	char		**list_cmds;
	size_t		index_cmd;
	t_process	*process;

	list_cmds = pipex->list_commands;
	index_cmd = 0;
	pipex->fd_in = pipex->file_fds[0];
	process = &pipex->process;
	while (list_cmds[index_cmd] != NULL)
	{
		prepare_process(pipex, list_cmds[index_cmd], (index_cmd == 0), \
			(list_cmds[index_cmd + 1] == NULL));
		if (pipe(pipex->pipe_fds) == -1)
			syscall_error(pipex, "pipe", 1);
		pipex->pid = fork();
		if (pipex->pid == -1)
			syscall_error(pipex, "fork", 1);
		if (pipex->pid == 0)
			child(pipex, list_cmds, index_cmd);
		else
			parent(pipex, list_cmds, index_cmd);
		free_process(process);
		index_cmd++;
	}
}

void	start_pipex(t_pipex *pipex)
{
	pipex->pid = -1;
	pipex->pipe_fds[READ] = -1;
	pipex->pipe_fds[WRIT] = -1;
	pipex->file_fds[READ] = -1;
	pipex->file_fds[WRIT] = -1;
	pipex->fd_in = -1;
	pipex->last_cmd_exit_code = -1;
	pipex->list_commands = 0;
	pipex->env = 0;
}

void	free_pipex(t_pipex *pipex)
{
	if (pipex->pipe_fds[READ] != -1)
		close(pipex->pipe_fds[READ]);
	if (pipex->pipe_fds[WRIT] != -1)
		close(pipex->pipe_fds[WRIT]);
	if (pipex->file_fds[READ] != -1)
		close(pipex->file_fds[READ]);
	if (pipex->file_fds[WRIT] != -1)
		close(pipex->file_fds[WRIT]);
	if (pipex->fd_in != -1)
		close(pipex->fd_in);
	if (pipex->list_commands != 0)
		free_list_commands(&pipex->list_commands);
	start_pipex(pipex);
}
