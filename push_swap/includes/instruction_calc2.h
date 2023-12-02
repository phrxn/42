/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_calc2.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 20:58:15 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/06/26 20:58:27 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTION_CALC2_H
# define INSTRUCTION_CALC2_H

# include "push_swap.h"

t_instru	*instru_calc2(t_stack *from, t_stack *to, t_uint index);

t_instru	*organize_stack(t_stack *almost_organized_stack);

#endif
