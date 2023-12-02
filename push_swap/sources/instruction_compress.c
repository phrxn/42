/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_compress.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 15:23:44 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/06/26 04:21:49 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/instruction_compress.h"
#include "../includes/instruction_commons.h"
#include "../includes/push_swap.h"
#include <stdlib.h>

static void	compres_equal_size(t_instru *instru)
{
	instru->move = instru->move | instru->next->move;
	free(instru->next);
	instru->next = 0;
}

static void	compres_not_equal_size(t_instru *instru)
{
	if (instru->amount > instru->next->amount)
	{
		instru->amount -= instru->next->amount;
		instru->next->move = instru->move | instru->next->move;
	}
	else
	{
		instru->move = instru->move | instru->next->move;
		instru->next->amount -= instru->amount;
	}
}

static int	is_valid_to_compress(t_instru *instru)
{
	if (!instru)
		return (0);
	if (!instru->next)
		return (0);
	if (instru->next->move == INST_PFT)
		return (0);
	if (instru->move == INST_RF && instru->next->move == INST_RT)
		return (1);
	if (instru->move == INST_RRF && instru->next->move == INST_RRT)
		return (1);
	return (0);
}

void	instru_compres(t_instru *instru)
{
	if (!is_valid_to_compress(instru))
		return ;
	if (instru->amount == instru->next->amount)
		compres_equal_size(instru);
	else
		compres_not_equal_size(instru);
}
