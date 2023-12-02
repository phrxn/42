/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 11:40:00 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/06/19 14:24:42 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_UTILS_H
# define STACK_UTILS_H

# include "push_swap.h"

t_stack	*create_stack(int *numbers, unsigned int numbers_size);

void	destroy_stack(t_stack *stack);

int		is_stack_sorted(t_stack *stack);

#endif
