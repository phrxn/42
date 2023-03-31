/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 10:19:49 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/03/22 10:19:57 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/errors.h"
#include "../libs/libft/libft.h"
#include <errno.h>
#include <stdio.h>
#ifdef MOCK
# include "../tests/mock.h"
#endif

void	fatal_error(char *error_message)
{
	if (errno == 0)
		ft_putendl_fd(error_message, 2);
	else
		perror(error_message);
	exit(1);
}
