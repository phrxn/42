/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 23:45:17 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/06/26 20:38:32 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	translate_b_to_a(t_instru *instru)
{
	while (instru)
	{
		if (instru->move == INST_PFT)
			instru->move = INST_PTF;
		else if (instru->move == INST_PTF)
			instru->move = INST_PFT;
		else if (instru->move == INST_SF)
			instru->move = INST_ST;
		else if (instru->move == INST_ST)
			instru->move = INST_SF;
		else if (instru->move == INST_RF)
			instru->move = INST_RT;
		else if (instru->move == INST_RT)
			instru->move = INST_RF;
		else if (instru->move == INST_RRF)
			instru->move = INST_RRT;
		else if (instru->move == INST_RRT)
			instru->move = INST_RRF;
		instru = instru->next;
	}
}

void	add_instru_to_list_a(t_push_swap *push_swap, t_instru *instru)
{
	t_instru	*instru_last;

	instru_last = push_swap->instru_list;
	if (!instru_last || !instru)
	{
		push_swap->instru_list = instru;
		return ;
	}
	while (instru_last)
	{
		if (!instru_last->next)
			break ;
		instru_last = instru_last->next;
	}
	instru_last->next = instru;
}

void	add_instru_to_list_b(t_push_swap *push_swap, t_instru *instru)
{
	t_instru	*instru_last;

	instru_last = push_swap->instru_list;
	if (!instru_last || !instru)
	{
		push_swap->instru_list = instru;
		return ;
	}
	while (instru_last)
	{
		if (!instru_last->next)
			break ;
		instru_last = instru_last->next;
	}
	translate_b_to_a(instru);
	instru_last->next = instru;
}
