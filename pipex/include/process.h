/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 19:22:22 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/04/24 21:18:38 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESS_H
# define PROCESS_H

# include "pipex.h"
# include <stdlib.h>

void	prepare_process(t_pipex *pipex, char *full_cmd, int f_cmd, int l_cmd);

void	free_process(t_process *process);

#endif
