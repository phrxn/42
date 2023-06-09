/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:11:47 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/04/25 22:57:40 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/bonus/heredoc_bonus.h"
#include "../../include/errors.h"
#include "../../include/pipex.h"
#include "../../include/utils.h"
#include "../../libs/libft/libft.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * make_line -	try to create a line by reading from stdin and join with
 *				possible buffer piece.
 * @fd_in:			stdin fd.
 * @buffer_line:	a possible piece of line already read.
 *
 * Return:
 *    On successful:
 *		a pointer to malloced line
 * 	  On failure:
 *		NULL if is a empty line (EOF hit a empty line)
 */
static char	*make_line(int fd_in, char *buffer_line)
{
	char	*new_buffer_line;
	char	*tmp_piece;

	tmp_piece = get_next_line(fd_in);
	if (!buffer_line && !tmp_piece)
		return (0);
	else if (buffer_line && !tmp_piece)
		return (buffer_line);
	else if (!buffer_line && tmp_piece)
	{
		new_buffer_line = ft_strdup(tmp_piece);
		free(tmp_piece);
	}
	else
	{
		new_buffer_line = ft_strjoin(buffer_line, tmp_piece);
		free(buffer_line);
		free(tmp_piece);
	}
	return (new_buffer_line);
}

static int	handler_output(char **line, int file_fds[2], int *p_suf, char *lim)
{
	if (ft_strncmp(*line, "\n", 1) && \
		!ft_strncmp(*line, lim, (ft_strlen(*line) - NEW_LINE)))
	{
		free(*line);
		close(file_fds[STDIN2]);
		get_next_line(file_fds[STDIN2]);
		return (0);
	}
	write(file_fds[HDOC_FD], *line, ft_strlen(*line));
	*p_suf = 1;
	free(*line);
	*line = NULL;
	return (1);
}

/**
 * invalid_eof - check if the EOF hit a empty line
 * @stdin2:		fd with stdin
 * @line:		the line readed from stdin
 * @limiter:	the heredoc limiter
 *
 * Return:
 *   On successful:
 *		0 - if line is valid
 *   On failure:
 *      1 - if eof hit a invalid
 */
static int	invalid_eof(int stdin2, char *line, char *limiter)
{
	if (line)
		return (0);
	print_message(2, "\n");
	print_message(2, NAME);
	print_message(2, ": warning: ");
	print_message(2, "here-document delimited by end-of-file (wanted `");
	print_message(2, limiter);
	print_message(2, "')\n");
	close(stdin2);
	get_next_line(stdin2);
	return (1);
}

/**
 * write_file - 	fills tmp heredoc file with stdin input until hit the
 * 					limiter.
 * @file_fds[2]:	array with 2 fds. The first is stdin copy, the second is
 * 					heredoc file.
 * @limiter:		heredoc limiter
 */
void	write_file(int file_fds[2], char *limiter)
{
	char	*line;
	int		print_suffix;

	print_suffix = 1;
	line = 0;
	while (1)
	{
		if (print_suffix)
			write(1, "> ", 2);
		line = make_line(file_fds[STDIN2], line);
		if (invalid_eof(file_fds[STDIN2], line, limiter))
			break ;
		else
		{
			if (ft_strchr(line, '\n'))
			{
				if (!handler_output(&line, file_fds, &print_suffix, limiter))
					break ;
			}
			else
				print_suffix = 0;
		}
	}
}

/**
 * heredoc - create a temp file and fill it with stdin input.
 * @limiter:	the heredoc limiter to stop read from stdin.
 *
 * Return:
 *	On successful:
 *		return a fd to tmp heredoc file filled.
 *	On failure:
 *		close the program if syscall error, or returns -1 fd.
 */
int	heredoc(char *limiter)
{
	int	file_fds[2];
	int	open_flags;
	int	heredoc_ready;

	open_flags = O_WRONLY | O_CREAT | O_EXCL | O_TRUNC ;
	file_fds[STDIN2] = dup(0);
	if (file_fds[STDIN2] < 0)
		syscall_error(0, "heredoc dup stdin", 1);
	file_fds[HDOC_FD] = open(HEREDOC_FILE, open_flags, 0600);
	if (file_fds[HDOC_FD] < 0)
		syscall_error(0, "heredoc create tmp file", 1);
	heredoc_ready = open(HEREDOC_FILE, O_RDONLY);
	if (heredoc_ready < 0)
		syscall_error(0, "heredoc open tmp file", 1);
	unlink(HEREDOC_FILE);
	write_file(file_fds, limiter);
	close(file_fds[HDOC_FD]);
	close(file_fds[STDIN2]);
	return (heredoc_ready);
}
