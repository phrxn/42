/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_calc2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 20:52:29 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/06/26 20:56:52 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/instruction_calc.h"
#include "../includes/instruction_create.h"

static int	get_undo_value2(t_stack *stack, int num)
{
	int	undo;
	int	status;

	undo = stack->min_value;
	status = 1;
	if (num > stack->min_value && num < stack->max_value)
	{
		while (status)
		{
			undo = num++;
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
t_instru	*instru_calc2(t_stack *from, t_stack *to, t_uint index)
{
	t_uint	rots[4];
	int		number;
	int		status;

	rots[2] = 0;
	rots[3] = 0;
	if (!from->size)
		return (0);
	number = get_number(from, index, &status);
	if (status)
		return (0);
	if (calc_rots(from, number, rots, rots + 1))
		return (0);
	if (to->size > 1)
		calc_rots(to, get_undo_value2(to, number), rots + 2, rots + 3);
	return (create_cheapest_instru(rots));
}

t_instru	*organize_stack(t_stack *almost_organized_stack)
{
	t_uint		rotations[4];
	t_instru	*rot;

	rotations[2] = 0;
	rotations[3] = 0;
	if (!almost_organized_stack->size)
		return (0);
	if (calc_rots(almost_organized_stack, 0, rotations, rotations + 1))
		return (0);
	if (rotations[0] < rotations[1])
		rot = instru_create(INST_RF, rotations[0], 0, 0);
	else
		rot = instru_create(INST_RRF, rotations[1], 0, 0);
	return (rot);
}
