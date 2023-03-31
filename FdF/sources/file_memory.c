/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 10:23:31 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/03/22 20:32:45 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/file_memory.h"
#include "../include/errors.h"
#include "../libs/libft/libft.h"
#include <unistd.h>
#include <fcntl.h>

static void	die_read(int fd, char *msg)
{
	close(fd);
	fatal_error(msg);
}

/**
 * do_read - reads the fd.
 * @fd:	     an already opened file descriptor.
 * @buffer:  an already mallocated buffer. 
 *
 * Reads the fd and returns a pointer to the 
 * read data.
 *
 * Return:
 *    On success:
 *    	A pointer to the data readed from the fd.
 *    On failure:
 *  	Show the error message and closes the program with
 *  	exit(1)
 */
static char	*do_read(int fd, char *buffer, char *file_data)
{
	char	*pointer_tmp;
	int		readed;

	readed = READ_BUFFER_SIZE;
	while (readed == READ_BUFFER_SIZE)
	{
		readed = read(fd, buffer, READ_BUFFER_SIZE);
		if (readed == -1)
		{
			free(file_data);
			free(buffer);
			die_read(fd, "[do_read] read syscall error.");
		}
		pointer_tmp = file_data;
		file_data = ft_strjoin(file_data, buffer);
		free(pointer_tmp);
		if (!file_data)
		{
			free(buffer);
			die_read(fd, "[do_read] new file_data error.");
		}
		ft_bzero(buffer, READ_BUFFER_SIZE);
	}
	free(buffer);
	return (file_data);
}

/**
 * read_map_file - prepares a temp buffer and call do_read
 * @fd:	an already opened file descriptor;
 *
 * This function prepares a temp buffer that will hold 
 * the data reads by the read syscall. 
 *
 * Return:
 *    On success:
 *    	A pointer to the data readed from the fd.
 *    On failure:
 *  	Show the error message and closes the program with
 *  	exit(1)
 */
static char	*read_map_file(int fd)
{
	char	*buffer;
	char	*file_data;

	buffer = ft_calloc(READ_BUFFER_SIZE + 1, sizeof(*buffer));
	if (!buffer)
		die_read(fd, "[read_map_file] buffer malloc error.");
	file_data = ft_strdup("");
	if (!file_data)
	{
		free(buffer);
		die_read(fd, "[do_read] pointer malloc error.");
	}
	file_data = do_read(fd, buffer, file_data);
	return (file_data);
}

/*
 * load_file_in_memory - reads a regular file into memory.
 * @file_name: the file name, like: /home/user/file.txt
 *
 * This function reads a regular file into memory and returns a pointer
 * to that file in memory. If any errors occur while opening, reading
 * or malloc an error message will be displayed in the STD_ERR and the program
 * will EXIT.
 *
 * Return:
 * 		A pointer to the regular file in memory.
 */
char	*load_file_in_memory(const char *file_name)
{
	int		fd;
	char	*file_data;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		fatal_error("[load_map_in_memory] open map file.");
	file_data = read_map_file(fd);
	close(fd);
	return (file_data);
}
