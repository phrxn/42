/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 19:49:11 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/04/24 19:51:00 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H
# include "pipex.h"

void	syscall_error(t_pipex *pipex, char *msg_to_perror, int is_to_exit);

void	program_error(t_pipex *pipex, char *msg1, char *msg2, int is_to_exit);

#endif
