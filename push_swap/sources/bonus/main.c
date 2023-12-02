/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 01:06:20 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/06/27 16:34:51 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../../includes/check_parameters.h"
#include "../../includes/convert.h"
#include "../../includes/ft_string.h"
#include "../../includes/instruction_commons.h"
#include "../../includes/bonus/checker.h"
#include "../../includes/stack_utils.h"
#include <stdlib.h>
#include <stddef.h>

static void	die(int *numbers, int exit_code)
{
	if (numbers)
		free(numbers);
	put_string("Error\n", 2);
	exit(exit_code);
}

static void	start(t_push_swap *push_swap, int argc, char **argv)
{
	int	*numbers;

	if (argc < 2)
		exit(0);
	if (!all_parameters_numbers(argv + 1))
		die(0, 255);
	numbers = ft_atoi_argv(argv + 1, argc - 1);
	if (!numbers)
		die(numbers, 0);
	if (has_equals_numbers(numbers, argc - 1))
		die(numbers, 0);
	create_index(numbers, argc - 1, 0);
	push_swap->stack_a = create_stack(numbers, argc - 1);
	if (!push_swap->stack_a)
		die(0, 0);
	push_swap->stack_b = create_stack(0, 0);
	if (!push_swap->stack_b)
		die(0, 0);
	push_swap->instru_list = 0;
	free(numbers);
}

static void	end(t_push_swap *push_swap)
{
	if (push_swap->stack_a)
		destroy_stack(push_swap->stack_a);
	if (push_swap->stack_b)
		destroy_stack(push_swap->stack_b);
	if (push_swap->instru_list)
		instru_free(push_swap->instru_list);
}

int	main(int argc, char **argv)
{
	int			exit_code;
	t_push_swap	push_swap;

	start(&push_swap, argc, argv);
	exit_code = checker(&push_swap);
	end(&push_swap);
	return (exit_code);
}
