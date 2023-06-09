/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dupz.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 21:50:46 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/04/25 22:02:17 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DUPZ_H
# define DUPZ_H

# include "pipex.h"

void	dupz(t_pipex *pipex, char *msg_to_perror, int oldfd, int newfd);

#endif
