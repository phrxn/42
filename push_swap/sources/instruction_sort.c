/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 20:34:32 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/06/26 20:49:33 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/instruction_sort.h"
#include "../includes/push_swap.h"
#include "../includes/instruction_create.h"
#include "../includes/instruction_list.h"
#include "../includes/instruction_calc.h"
#include "../includes/instruction_calc2.h"
#include "../includes/instruction_apply.h"
#include "../includes/instruction_print.h"
#include "../includes/stack_utils.h"

static void	sort_size_two(t_push_swap *push_swap)
{
	t_stack		*stack_a;
	int			index[2];
	t_instru	*instru;

	instru = 0;
	stack_a = push_swap->stack_a;
	index[0] = stack_a->head->value;
	index[1] = stack_a->head->previous->value;
	if (index[0] > index[1])
		instru = instru_create(INST_SF, 1, 0, 0);
	add_instru_to_list_a(push_swap, instru);
	instru_apply(push_swap->stack_a, push_swap->stack_b, instru);
}

static void	sort_size_three(t_push_swap *push_swap)
{
	t_stack		*stack_a;
	int			index[3];
	t_instru	*instru;

	stack_a = push_swap->stack_a;
	index[0] = stack_a->head->value;
	index[1] = stack_a->head->previous->value;
	index[2] = stack_a->head->previous->previous->value;
	instru = 0;
	if (index[0] < index[1] && index[0] < index[2] && index[1] > index[2])
		instru = instru_create(INST_RRF, 1, INST_SF, 1);
	else if (index[0] < index[1] && index[0] > index[2] && index[1] > index[2])
		instru = instru_create(INST_RRF, 1, 0, 0);
	else if (index[0] > index[1] && index[0] < index[2] && index[1] < index[2])
		instru = instru_create(INST_SF, 1, 0, 0);
	else if (index[0] > index[1] && index[0] > index[2] && index[1] > index[2])
		instru = instru_create(INST_RF, 1, INST_SF, 1);
	else if (index[0] > index[1] && index[0] > index[2] && index[1] < index[2])
		instru = instru_create(INST_RF, 1, 0, 0);
	else
		return ;
	add_instru_to_list_a(push_swap, instru);
	instru_apply(push_swap->stack_a, push_swap->stack_b, instru);
}

/**
 * Calculates the best instructions for a number from one stack to another.
 *
 * Return: 0 if an error occurs or a pointer to a list of instructions.
 */
static t_instru	*best_move_to_stack(t_stack *stack_from, t_stack *stack_to)
{
	t_uint		index;
	t_instru	*instru_best;
	t_instru	*instru_aux;

	index = 0;
	instru_best = calc_instru_for_number(stack_from, stack_to, index);
	index++;
	while (index < stack_from->size)
	{
		instru_aux = calc_instru_for_number(stack_from, stack_to, index);
		instru_best = cheapest_intru(instru_best, instru_aux);
		index++;
	}
	return (instru_best);
}

static void	sort_size_big(t_push_swap *push_swap)
{
	t_instru	*instru_tmp;

	while (push_swap->stack_a->size > 3)
	{
		instru_tmp = best_move_to_stack(push_swap->stack_a, push_swap->stack_b);
		add_instru_to_list_a(push_swap, instru_tmp);
		instru_apply(push_swap->stack_a, push_swap->stack_b, instru_tmp);
	}
	sort_size_three(push_swap);
	while (push_swap->stack_b->size)
	{
		instru_tmp = instru_calc2(push_swap->stack_b, push_swap->stack_a, 0);
		instru_apply(push_swap->stack_b, push_swap->stack_a, instru_tmp);
		add_instru_to_list_b(push_swap, instru_tmp);
	}
}

void	sort_stack(t_push_swap *push_swap)
{
	t_instru	*align_stack;

	if (is_stack_sorted(push_swap->stack_a))
		return ;
	if (push_swap->stack_a->size == 2)
		sort_size_two(push_swap);
	if (push_swap->stack_a->size == 3)
		sort_size_three(push_swap);
	if (push_swap->stack_a->size > 3)
		sort_size_big(push_swap);
	if (!is_stack_sorted(push_swap->stack_a))
	{
		align_stack = organize_stack(push_swap->stack_a);
		add_instru_to_list_a(push_swap, align_stack);
		instru_apply(push_swap->stack_a, push_swap->stack_b, align_stack);
	}
	print_instruction(push_swap);
}
