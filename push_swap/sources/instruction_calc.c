/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_calc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 22:34:10 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/06/26 20:47:20 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/instruction_calc.h"
#include "../includes/push_swap.h"
#include "../includes/instruction_create.h"

/**
 * Return the index of a number that is on the stack (if it exists in it).
 *
 * @search:	stack to get the index.
 * @number:	index of the number inside the stack.
 * @status: indicates whether the function was executed successfully. 
 * 			0 yes, 1 not.
 *
 * Return: 	If the status value is one, an error has occurred
 * 			(the number wasn't found inside the stack, for example) and the
 * 			function's return value should be disregarded. If the status value 
 * 			is zero, the return of this function is the index of the number 
 * 			inside the stack.
 */
t_uint	get_index(t_stack *search, int number, int *status)
{
	t_node	*node;
	t_uint	index;

	index = 0;
	if (search->size)
		node = search->head;
	while (index < search->size)
	{
		if (node->value == number)
		{
			*status = 0;
			return (index);
		}
		index++;
		node = node->previous;
	}
	*status = 1;
	return (0);
}

/**
 * Returns the number that is in the index inside the stack.
 *
 * @search:	stack to get the number.
 * @index:	index of the number inside the stack.
 * @status: indicates whether the function was executed successfully. 
 * 			0 yes, 1 not.
 *
 * Return: 	If the status value is one, an error has occurred
 * 			(such as invalid index, for example) and the function's return value
 * 			should be disregarded. If the status value is zero, the return of 
 * 			this function is the value that is in the index inside the stack.
 */
int	get_number(t_stack *search, t_uint index, int *status)
{
	t_node	*node;
	int		count_index;

	if (!search->size || index >= search->size)
	{
		*status = 1;
		return (0);
	}
	node = search->head;
	count_index = 0;
	while (count_index < index)
	{
		node = node->previous;
		count_index++;
	}
	*status = 0;
	return (node->value);
}

/**
 * Calculates the number of rotations and reverse rotations to leave a number at
 * the top of the stack.
 *
 * @stack:	stack to search number.
 * @num:	number to calc rotations and reverse rotations
 * @rot:	pointer to store the number of  rotations
 * @rrot:	pointer to store the number of reverse rotations
 *
 * Return:	0 if num exists on the stack and the calculation was successful,
 * 			1 otherwise.
 */
int	calc_rots(t_stack *stack, int num, t_uint *rot, t_uint *rrot)
{	
	t_uint	number_index;
	int		status;

	number_index = get_index(stack, num, &status);
	if (status)
		return (1);
	*rot = 0;
	*rrot = 0;
	if (stack->size > 1)
	{
		*rot = number_index;
		*rrot = stack->size - number_index;
	}
	return (0);
}

/**
 * Search the number which num should be on top of the stack.
 * The stack size must be at least 1 with valid max and min values.
 *
 * 		stack (example)
 *		  6
 *        3
 *        1
 * Examples: for the num 5 , this method returns 3.
 * 			 for the num 2 , this method returns 1.
 * 			 for the num 7 or 0, this method returns 6.
 *
 * @stack:	stack to do the search.
 * Return:	number to search whick number it should be on top.
 */
int	get_undo_value(t_stack *stack, int num)
{
	int	undo;
	int	status;

	undo = stack->max_value;
	status = 1;
	if (num > stack->min_value && num < stack->max_value)
	{
		while (status)
		{
			undo = num--;
			get_index(stack, undo, &status);
		}
	}
	return (undo);
}

/**
 * Calculates the smallest number of instructions to move a number from one 
 * stack to another stack.
 * 
 * @from:	stack where the number is.
 * @to:		stack where the number should go.
 * @index:	index of the number on the stack from.
 *
 * Return: A list of the fewest number of instructions to move the number, or 
 * NULL if an error occurs.
 */
t_instru	*calc_instru_for_number(t_stack *from, t_stack *to, t_uint index)
{
	t_uint	rotations[4];
	int		number;
	int		status;

	rotations[2] = 0;
	rotations[3] = 0;
	if (!from->size)
		return (0);
	number = get_number(from, index, &status);
	if (status)
		return (0);
	if (calc_rots(from, number, rotations, rotations + 1))
		return (0);
	if (to->size > 1)
		calc_rots(to, get_undo_value(to, number), rotations + 2, rotations + 3);
	return (create_cheapest_instru(rotations));
}
