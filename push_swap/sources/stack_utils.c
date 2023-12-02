/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 11:44:17 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/06/27 11:52:12 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack_utils.h"
#include "../includes/push_swap.h"
#include "../includes/plumbing/stack.h"
#include <stdlib.h>

static void	start_stack(t_stack *stack)
{
	stack->head = 0;
	stack->max_value = 0;
	stack->min_value = 0;
	stack->size = 0;
}

/**
 * Creates a stack with the values inside the array. The first value in the
 * array will be the top of the stack and the last value will be the bottom.
 *
 * @numbers: the array with numbers 
 * @numbers_size: the array size
 *
 * Return: a pointer to the created stack, 0 if any errors occur.
 *
 */
t_stack	*create_stack(int *numbers, unsigned int numbers_size)
{
	t_stack			*stack;
	t_node			*new_node;

	stack = malloc(sizeof(*stack));
	if (!stack)
		return (0);
	start_stack(stack);
	while (numbers_size)
	{
		numbers_size--;
		new_node = malloc(sizeof(*new_node));
		if (!new_node)
		{
			destroy_stack(stack);
			return (0);
		}
		new_node->value = numbers[numbers_size];
		push(stack, new_node);
	}
	return (stack);
}

/**
 * Free a stack and all of its nodes.
 */
void	destroy_stack(t_stack *stack)
{
	t_node			*node_to_free;

	if (!stack)
		return ;
	while (stack->size)
	{
		node_to_free = pull(stack);
		free(node_to_free);
	}
	free(stack);
}

/**
 * Check if nodes in a stack are sorted.
 *
 * @stack: stack to check.
 * 
 * Return: 1 if the nodes are sorted, 0 if the stack is empty or not sorted.
 */
int	is_stack_sorted(t_stack *stack)
{
	unsigned int	index_number;
	t_node			*node_to_check;

	index_number = 0;
	if (!stack->size)
		return (0);
	node_to_check = stack->head;
	while (index_number < stack->size)
	{
		if (node_to_check->value != index_number)
			return (0);
		index_number++;
		node_to_check = node_to_check->previous;
	}
	return (1);
}
