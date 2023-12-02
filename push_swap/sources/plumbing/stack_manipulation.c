/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manipulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 21:43:08 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/06/14 21:43:20 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/plumbing/stack_manipulation.h"
#include "../../includes/plumbing/stack.h"
#include "../../includes/push_swap.h"

void	swap(t_stack *stack)
{
	int		tmp_value;
	t_node	*head;
	t_node	*previous;

	if (stack->size < 2)
		return ;
	head = stack->head;
	previous = head->previous;
	tmp_value = head->value;
	head->value = previous->value;
	previous->value = tmp_value;
}

void	rotation(t_stack *stack)
{
	if (stack->size < 2)
		return ;
	stack->head = stack->head->previous;
}

void	rrotation(t_stack *stack)
{
	if (stack->size < 2)
		return ;
	stack->head = stack->head->next;
}

void	push_from_to(t_stack *stack_from, t_stack *stack_to)
{
	t_node	*node;

	if (!stack_from->size)
		return ;
	node = pull(stack_from);
	push(stack_to, node);
}
