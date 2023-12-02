/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_calc.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:13:48 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/06/26 22:42:16 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTION_CALC_H
# define INSTRUCTION_CALC_H

# include "push_swap.h"

t_uint		get_index(t_stack *search, int number, int *status);

int			get_number(t_stack *search, t_uint index, int *status);

int			calc_rots(t_stack *stack, int num, t_uint *rot, t_uint *rrot);

int			get_undo_value(t_stack *stack, int number);

t_instru	*calc_instru_for_number(t_stack *from, t_stack *to, t_uint index);

#endif
