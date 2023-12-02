/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 20:41:59 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/06/26 20:55:38 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define RF  0
# define RRF 1
# define RT	2
# define RRT 3

// Push From --> To
# define INST_PFT 0001
// Push To --> From
# define INST_PTF 0002

// Swap From
# define INST_SF  0004
// Swap To
# define INST_ST  0010
// INST_SF and INST_ST at the same time
# define INST_SS  0014

// Rotation stack From
# define INST_RF  0020
// Rotation stack To
# define INST_RT  0040
// INST_RF and INST_RT at the same time
# define INST_RR  0060

// Reverse Rotation stack From
# define INST_RRF 0100
// Reverse Rotation stack To
# define INST_RRT 0200
// INST_RF and INST_RT at the same time
# define INST_RRR 0300

typedef unsigned int	t_uint;

typedef struct s_node	t_node;

typedef struct s_node
{
	int		value;
	t_node	*previous;
	t_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	int		max_value;
	int		min_value;
	t_uint	size;
}	t_stack;

typedef struct s_instru	t_instru;

typedef struct s_instru
{
	t_uint		move;
	t_uint		amount;
	t_instru	*next;
}	t_instru;

typedef struct s_push_swap
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_instru	*instru_list;
}	t_push_swap;

#endif
