/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_commons.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 22:30:54 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/06/24 22:30:55 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTION_COMMONS_H
# define INSTRUCTION_COMMONS_H
# include "../includes/push_swap.h"

t_instru	*instru_malloc(int type, int amount, t_instru *next);

void		instru_free(t_instru *to_free);

int			instru_cmp(const t_instru *instru1, const t_instru *instru2);

#endif
