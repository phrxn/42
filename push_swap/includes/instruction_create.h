/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_create.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 22:31:19 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/06/26 00:32:09 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTION_CREATE_H
# define INSTRUCTION_CREATE_H

# include <stddef.h>
# include "../includes/push_swap.h"

t_instru	*cheapest_intru(t_instru *a, t_instru *b);

t_instru	*instru_create(int a_type, int a_amount, int b_type, int b_amount);

t_instru	*create_cheapest_instru(const t_uint rots[4]);

#endif
