/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:24:25 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/06/14 21:57:38 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_H
# define CONVERT_H

int		ft_atoi(const char *number, int *status);

int		*ft_atoi_argv(char **argv, int argv_size);

void	create_index(int *array, int array_size, unsigned int start_index);

#endif
