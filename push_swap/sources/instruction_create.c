/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_create.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 22:25:28 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/06/26 00:31:48 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/instruction_create.h"
#include "../includes/instruction_commons.h"
#include "../includes/push_swap.h"
#include "../includes/instruction_compress.h"
#include <stddef.h>
#include <stdlib.h>

static t_instru	*add_pft(t_instru *instru)
{
	t_instru	*instru_pft;
	t_instru	*instru_next;
	t_instru	*instru_last;

	instru_pft = instru_malloc(INST_PFT, 1, 0);
	if (!instru_pft)
	{
		instru_free(instru);
		return (0);
	}
	if (!instru)
		return (instru_pft);
	instru_last = instru;
	instru_next = instru_last->next;
	while (instru_next)
	{
		instru_last = instru_next;
		instru_next = instru_last->next;
	}
	instru_last->next = instru_pft;
	return (instru);
}

t_instru	*cheapest_intru(t_instru *a, t_instru *b)
{
	int	cheap_intru;

	cheap_intru = instru_cmp(a, b);
	if (cheap_intru < 1)
	{
		instru_free(b);
		return (a);
	}
	else
	{
		instru_free(a);
		return (b);
	}
}

t_instru	*instru_create(int a_type, int a_amount, int b_type, int b_amount)
{
	t_instru	*instru_created;

	instru_created = 0;
	if (b_amount)
	{
		instru_created = instru_malloc(b_type, b_amount, instru_created);
		if (!instru_created)
			return (0);
	}
	if (a_amount)
	{
		instru_created = instru_malloc(a_type, a_amount, instru_created);
		if (!instru_created)
			return (0);
	}
	instru_compres(instru_created);
	return (instru_created);
}

t_instru	*create_cheapest_instru(const t_uint rots[4])
{
	t_instru	*inst_ret;
	t_instru	*inst_aux;

	inst_ret = instru_create(INST_RF, rots[RF], INST_RT, rots[RT]);
	inst_aux = instru_create(INST_RF, rots[RF], INST_RRT, rots[RRT]);
	inst_ret = cheapest_intru(inst_ret, inst_aux);
	inst_aux = instru_create(INST_RRF, rots[RRF], INST_RT, rots[RT]);
	inst_ret = cheapest_intru(inst_ret, inst_aux);
	inst_aux = instru_create(INST_RRF, rots[RRF], INST_RRT, rots[RRT]);
	inst_ret = cheapest_intru(inst_ret, inst_aux);
	return (add_pft(inst_ret));
}
