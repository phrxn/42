/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_print.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 20:37:22 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/06/27 16:33:06 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/instruction_print.h"

static void	print_instruction_mov(t_uint mov)
{
	if (mov == INST_PFT)
		put_string("pb\n", 1);
	if (mov == INST_PTF)
		put_string("pa\n", 1);
	if (mov == INST_SF)
		put_string("sa\n", 1);
	if (mov == INST_ST)
		put_string("sb\n", 1);
	if (mov == INST_SS)
		put_string("ss\n", 1);
	if (mov == INST_RF)
		put_string("ra\n", 1);
	if (mov == INST_RT)
		put_string("rb\n", 1);
	if (mov == INST_RR)
		put_string("rr\n", 1);
	if (mov == INST_RRF)
		put_string("rra\n", 1);
	if (mov == INST_RRT)
		put_string("rrb\n", 1);
	if (mov == INST_RRR)
		put_string("rrr\n", 1);
}

void	print_instruction(t_push_swap *push_swap)
{
	t_instru	*list;
	t_uint		count;

	list = push_swap->instru_list;
	while (list)
	{
		count = 0;
		while (count < list->amount)
		{
			print_instruction_mov(list->move);
			count++;
		}
		list = list->next;
	}
}
