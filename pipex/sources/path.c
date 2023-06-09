/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:29:02 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/04/21 17:48:18 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/path.h"
#include "../include/argv.h"
#include "../include/utils.h"
#include "../include/pipex.h"
#include "../libs/libft/libft.h"
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

static char	*make_full_path(char *path_env, char *cmd, size_t size, int *m_ok)
{
	char	*full_path_cmd;
	size_t	cmd_size;

	cmd_size = ft_strlen(cmd);
	size += cmd_size ;
	full_path_cmd = ft_calloc((size + 2), sizeof(*path_env));
	if (!full_path_cmd)
	{
		*m_ok = -1;
		return (0);
	}
	while (cmd_size--)
		full_path_cmd[size--] = cmd[cmd_size];
	full_path_cmd[size] = '/';
	while (size--)
		full_path_cmd[size] = path_env[size];
	if (access(full_path_cmd, F_OK | X_OK))
	{
		free(full_path_cmd);
		full_path_cmd = NULL;
	}
	return (full_path_cmd);
}

static char	*ft_make_paths(char *path_env, char *cmd, size_t count, int *m_ok)
{
	char			*cmd_full_path;
	char			*end;
	unsigned int	size;

	cmd_full_path = NULL;
	while (*path_env && *path_env == ':')
		path_env++;
	end = path_env;
	while (*end && *end != ':')
		end++;
	size = end - path_env;
	if (size)
		cmd_full_path = ft_make_paths(end, cmd, count + 1, m_ok);
	if (cmd_full_path == NULL && size && *m_ok >= 0)
		cmd_full_path = make_full_path(path_env, cmd, size, m_ok);
	return (cmd_full_path);
}

/**
 * get_cmd_fpath - Create a full path to the command.
 * @cmd:	command
 * @env:	environment variables
 * 
 * If the cmd parameter has no '/' this method tries to look for the 
 * command in the PATH environment variable.
 * e.g.:
 * 		if cmd is 'cat' return is => /bin/cat
 * 		if cmd is ./my_cmd reuturn is => ./my_cmd
 * Return:
 * 		On success:
 * 			ALWAYS a malloced string with a path to the command
 * 		On failure:
 * 			if the command isn't found in PATH or PATH don't e
 * 			A NULL pointer.
 */
char	*get_cmd_fpath(char *cmd, char **env, int *malloc_status)
{
	char	*env_path;
	char	*cmd_full_path;
	size_t	count;

	env_path = NULL;
	cmd_full_path = NULL;
	count = 0;
	while (env && *env)
	{
		if (ft_strnstr(*env++, "PATH=", 5))
		{
			env_path = *--env;
			break ;
		}
	}
	if (ft_strchr(cmd, '/'))
	{
		cmd_full_path = ft_strdup(cmd);
		if (!cmd_full_path)
			*malloc_status = 1;
	}
	else
		if (env_path)
			cmd_full_path = ft_make_paths(env_path + 5, cmd, 0, malloc_status);
	return (cmd_full_path);
}
