/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 23:27:24 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/06/27 19:21:55 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../../includes/bonus/get_next_line.h"
#include "../../includes/bonus/checker.h"
#include "../../includes/instruction_apply.h"
#include "../../includes/instruction_commons.h"
#include "../../includes/stack_utils.h"
#include "../../includes/ft_string.h"
#include <stdlib.h>

static int	get_instruction(char *line)
{
	if (ft_memcmp(line, "pb\n", 3) == 0)
		return (INST_PFT);
	else if (ft_memcmp(line, "pa\n", 3) == 0)
		return (INST_PTF);
	else if (ft_memcmp(line, "sa\n", 3) == 0)
		return (INST_SF);
	else if (ft_memcmp(line, "sb\n", 3) == 0)
		return (INST_ST);
	else if (ft_memcmp(line, "ss\n", 3) == 0)
		return (INST_SS);
	else if (ft_memcmp(line, "ra\n", 3) == 0)
		return (INST_RF);
	else if (ft_memcmp(line, "rb\n", 3) == 0)
		return (INST_RT);
	else if (ft_memcmp(line, "rr\n", 3) == 0)
		return (INST_RR);
	else if (ft_memcmp(line, "rra\n", 4) == 0)
		return (INST_RRF);
	else if (ft_memcmp(line, "rrb\n", 4) == 0)
		return (INST_RRT);
	else if (ft_memcmp(line, "rrr\n", 4) == 0)
		return (INST_RRR);
	else
		return (-1);
}

static int	read_input(void)
{
	char	*line;
	int		instru;

	line = get_next_line(0);
	if (line == NULL)
		instru = 0;
	else
		instru = get_instruction(line);
	free(line);
	return (instru);
}

static void	apply_instru(t_push_swap *push_swap, int instruction)
{
	t_instru	*instru;
	t_stack		*stack_a;
	t_stack		*stack_b;

	stack_a = push_swap->stack_a;
	stack_b = push_swap->stack_b;
	instru = instru_malloc(instruction, 1, 0);
	if (instru)
	{
		instru_apply(stack_a, stack_b, instru);
		instru_free(instru);
	}
}

static void	is_sorted(t_push_swap *push_swap)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = push_swap->stack_a;
	stack_b = push_swap->stack_b;
	if (is_stack_sorted(stack_a) && stack_b->size == 0)
		put_string("OK\n", 1);
	else
		put_string("KO\n", 1);
}

int	checker(t_push_swap *push_swap)
{
	int	instruction;
	int	check_ordering;

	check_ordering = 1;
	while (1)
	{
		instruction = read_input();
		if (instruction == -1)
		{
			put_string("Error\n", 2);
			check_ordering = 0;
			close(0);
			read_input();
			return (255);
		}
		else if (instruction == 0)
			break ;
		else
			apply_instru(push_swap, instruction);
	}
	if (check_ordering)
		is_sorted(push_swap);
	return (0);
}
