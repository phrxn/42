/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_commons.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 22:27:42 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/06/24 22:30:07 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/instruction_commons.h"
#include "../includes/push_swap.h"
#include <stddef.h>
#include <stdlib.h>

static size_t	count_move(const t_instru *to_count)
{
	size_t	count;

	count = 0;
	while (to_count)
	{
		count += to_count->amount;
		to_count = to_count->next;
	}
	return (count);
}

t_instru	*instru_malloc(int type, int amount, t_instru *next)
{
	t_instru	*instruc;

	instruc = malloc(sizeof * instruc * 1);
	if (!instruc)
	{
		instru_free(next);
		return (0);
	}
	instruc->move = type;
	instruc->amount = amount;
	instruc->next = next;
	return (instruc);
}

void	instru_free(t_instru *to_free)
{
	t_instru	*aux;

	while (to_free)
	{
		aux = to_free->next;
		free(to_free);
		to_free = aux;
	}
}

/**
 * Compare two instruction lists and return the one with the fewest moves.
 *
 * @instru1: list for comparison
 * @instru2: list for comparison
 *
 * Return: 0 if both have the same number of moves,
 *		   1 if the first has more moves,
 *		   -1 if the second has less moves.
 */
int	instru_cmp(const t_instru *instru1, const t_instru *instru2)
{
	size_t	instru1_size;
	size_t	instru2_size;

	instru1_size = count_move(instru1);
	instru2_size = count_move(instru2);
	if (instru1_size < instru2_size)
		return (-1);
	return (instru1_size > instru2_size);
}
