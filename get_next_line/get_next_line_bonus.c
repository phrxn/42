/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 22:35:44 by dmanoel-          #+#    #+#             */
/*   Updated: 2022/10/07 01:10:33 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

static void	delete_module(t_module *mod)
{
	if (mod->buf)
		free(mod->buf);
	mod->buf = 0;
}

static int	create_module(t_module *mod, int fd)
{
	mod->l_start = 0;
	mod->buf = malloc(BUFFER_SIZE);
	if (!mod->buf)
		return (1);
	mod->readed = read(fd, mod->buf, BUFFER_SIZE);
	if (mod->readed < 1)
		delete_module(mod);
	if (mod->readed < 0)
		return (1);
	while (mod->l_start < mod->readed && mod->buf[mod->l_start] != '\n')
		mod->l_start++;
	if (mod->l_start < mod->readed)
		mod->l_size = mod->l_start + 1;
	else
		mod->l_size = mod->l_start;
	mod->l_start++;
	mod->l_end = mod->l_start;
	return (0);
}

static char	*l_make(char *line, char *append, int copy_n_bytes, int size)
{
	if (size)
	{
		line = malloc(size + 1);
		if (line)
			line[size] = 0;
		size -= copy_n_bytes;
	}
	if (line)
		while (copy_n_bytes--)
			line[size++] = *append++;
	return (line);
}

static char	*read_fd(int fd, t_module old, t_module *mod_new, int l_size)
{
	t_module	tmp;
	char		*line;

	if (create_module(&tmp, fd))
		return (0);
	if (tmp.l_start > BUFFER_SIZE)
		line = read_fd(fd, old, mod_new, l_size + BUFFER_SIZE);
	else
	{
		line = l_make(0, tmp.buf, tmp.l_size, l_size + tmp.l_size);
		if (old.buf)
			l_make(line, old.buf + old.l_start, old.l_size, 0);
		*mod_new = tmp;
		return (line);
	}
	if (line)
		l_make(line + l_size, tmp.buf, BUFFER_SIZE, 0);
	delete_module(&tmp);
	return (line);
}

char	*get_next_line(int fd)
{
	static t_module	mod_list[1024];	
	t_module		mod;
	char			*line;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (0);
	mod = mod_list[fd];
	while (mod.l_end < mod.readed && mod.buf[mod.l_end] != '\n')
		mod.l_end++;
	mod.l_size = mod.l_end - mod.l_start;
	if (mod.l_end < mod.readed)
	{
		mod.l_size++;
		line = l_make(0, mod.buf + mod.l_start, mod.l_size, mod.l_size);
		mod.l_start = mod.l_end + 1;
		mod.l_end = mod.l_start;
		mod_list[fd] = mod;
	}
	else
	{
		line = read_fd(fd, mod, mod_list + fd, mod.l_size);
		delete_module(&mod);
	}
	return (line);
}
