/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manipulation.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 21:43:58 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/06/14 21:44:13 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_MANIPULATION_H
# define STACK_MANIPULATION_H

# include "../push_swap.h"

void	swap(t_stack *stack);

void	rotation(t_stack *stack);

void	rrotation(t_stack *stack);

void	push_from_to(t_stack *stack_from, t_stack *stack_to);

#endif
