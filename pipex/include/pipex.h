/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:16:55 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/04/25 21:57:17 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>

# define NAME "pipex"

# define READ 0
# define WRIT 1

typedef struct s_process
{
	char	*path;
	char	**argv;
}	t_process;

typedef struct s_pipex
{
	pid_t		pid;
	int			pipe_fds[2];
	int			file_fds[2];
	int			fd_in;
	int			last_cmd_exit_code;
	char		**list_commands;
	char		**env;
	t_process	process;
}	t_pipex;

void	start_pipex(t_pipex *pipex);

void	free_pipex(t_pipex *pipex);

void	pipeline(t_pipex *pipex);

#endif
