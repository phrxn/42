/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 20:38:05 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/06/26 20:53:45 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/plumbing/stack.h"
#include <stdlib.h>
#include <limits.h>

static	void	pull_set_max_min(t_stack *stack)
{
	int				min_max_values[2];
	unsigned int	count;
	t_node			*node_aux;

	min_max_values[0] = INT_MAX;
	min_max_values[1] = INT_MIN;
	if (stack->size == 0)
	{
		stack->max_value = 0;
		stack->min_value = 0;
		return ;
	}
	node_aux = stack->head;
	count = stack->size;
	while (count--)
	{
		if (node_aux->value > min_max_values[1])
			min_max_values[1] = node_aux->value;
		if (node_aux->value < min_max_values[0])
			min_max_values[0] = node_aux->value;
		node_aux = node_aux->previous;
	}
	stack->max_value = min_max_values[1];
	stack->min_value = min_max_values[0];
}

static	void	push_set_max_min(t_stack *stack, t_node *node)
{
	int				min_max_values[2];
	unsigned int	count;
	t_node			*node_aux;

	min_max_values[0] = INT_MAX;
	min_max_values[1] = INT_MIN;
	if (stack->size == 1)
	{
		stack->max_value = node->value;
		stack->min_value = node->value;
	}
	node_aux = stack->head;
	count = stack->size - 1;
	while (count--)
	{
		node_aux = node_aux->previous;
		if (node_aux->value > min_max_values[1])
			min_max_values[1] = node_aux->value;
		if (node_aux->value < min_max_values[0])
			min_max_values[0] = node_aux->value;
	}
	if (node->value > min_max_values[1])
		stack->max_value = node->value;
	if (node->value < min_max_values[0])
		stack->min_value = node->value;
}

/**
 *	Place a node on top of the stack. Also set:
 *	stack size, stack min_value and stack max_value
 *	
 *	no:       stack before:    stack after:	
 *	 _____                        _____ 
 *  |__2__|      _____           |__2__|
 * 	          	|__4__|          |__4__|
 *              |__3__|          |__3__|
 *
 */
void	push(t_stack *stack, t_node *no_new)
{
	t_node	*head_old;
	t_node	*tail;

	if (!stack->size)
	{
		no_new->previous = no_new;
		no_new->next = no_new;
	}
	else
	{
		head_old = stack->head;
		tail = head_old->next;
		no_new->previous = head_old;
		no_new->next = tail;
		head_old->next = no_new;
		tail->previous = no_new;
	}
	stack->head = no_new;
	stack->size++;
	push_set_max_min(stack, no_new);
}

/**
 *	Remove a node on top of the stack. Also set:
 *	stack size, stack min_value and stack max_value
 *	
 *	stack before:    stack after:      no:	
 *   _____                            _____ 
 *  |__2__|           _____          |__2__| 
 *  |__4__|          |__4__|
 *  |__3__|          |__3__|
 *
 * Return: If the stack is not empty, this method removes the top node and
 * returns it, if the stack is empty NULL is returned.
 */
t_node	*pull(t_stack *stack)
{
	t_node	*head_new;
	t_node	*tail;
	t_node	*on_top;

	if (!stack->size)
		return (0);
	else
	{
		head_new = stack->head->previous;
		tail = stack->head->next;
		tail->previous = head_new;
		head_new->next = tail;
	}
	stack->size--;
	on_top = stack->head;
	stack->head = head_new;
	if (!stack->size)
		stack->head = 0;
	pull_set_max_min(stack);
	return (on_top);
}
