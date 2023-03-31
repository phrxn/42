/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_memory.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 22:01:32 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/03/21 22:01:33 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_MEMORY_H
# define FILE_MEMORY_H

// 1MB
# define READ_BUFFER_SIZE 1048576

char	*load_file_in_memory(const char *file_name);

#endif
