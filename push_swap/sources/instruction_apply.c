/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_apply.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 23:41:26 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/06/26 08:39:53 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/plumbing/stack_manipulation.h"

static void	instru_apply_push(t_stack *from, t_stack *to, t_instru *instru)
{
	t_uint	instru_count;

	instru_count = 0;
	while (instru_count < instru->amount)
	{
		if (instru->move == INST_PFT)
			push_from_to(from, to);
		if (instru->move == INST_PTF)
			push_from_to(to, from);
		instru_count++;
	}
}

static void	instru_apply_swap(t_stack *from, t_stack *to, t_instru *instru)
{
	t_uint	instru_count;

	instru_count = 0;
	while (instru_count < instru->amount)
	{
		if (instru->move == INST_SF || instru->move == INST_SS)
			swap(from);
		if (instru->move == INST_ST || instru->move == INST_SS)
			swap(to);
		instru_count++;
	}
}

static void	instru_apply_rotation(t_stack *from, t_stack *to, t_instru *instru)
{
	t_uint	instru_count;

	instru_count = 0;
	while (instru_count < instru->amount)
	{
		if (instru->move == INST_RF || instru->move == INST_RR)
			rotation(from);
		if (instru->move == INST_RT || instru->move == INST_RR)
			rotation(to);
		instru_count++;
	}
}

static void	instru_apply_rrotation(t_stack *from, t_stack *to, t_instru *instru)
{
	t_uint	instru_count;

	instru_count = 0;
	while (instru_count < instru->amount)
	{
		if (instru->move == INST_RRF || instru->move == INST_RRR)
			rrotation(from);
		if (instru->move == INST_RRT || instru->move == INST_RRR)
			rrotation(to);
		instru_count++;
	}
}

void	instru_apply(t_stack *from, t_stack *to, t_instru *instru)
{
	t_uint	mov;

	while (instru)
	{
		mov = instru->move;
		if (mov == INST_PFT || mov == INST_PTF)
			instru_apply_push(from, to, instru);
		if (mov == INST_SF || mov == INST_ST || mov == INST_ST)
			instru_apply_swap(from, to, instru);
		if (mov == INST_RF || mov == INST_RT || mov == INST_RR)
			instru_apply_rotation(from, to, instru);
		if (mov == INST_RRF || mov == INST_RRT || mov == INST_RRR)
			instru_apply_rrotation(from, to, instru);
		instru = instru->next;
	}
}
