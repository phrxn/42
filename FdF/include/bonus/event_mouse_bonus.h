/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_mouse_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 22:04:13 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/03/21 22:04:14 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_MOUSE_BONUS_H
# define EVENT_MOUSE_BONUS_H

# define MOU_BTN_1 1
# define MOU_BTN_M 2
# define MOU_BTN_2 3

# define MOU_SCRL_UP 4
# define MOU_SCRL_DW 5

int	mouse_pressed(int button, int x, int y, void *param);

int	mouse_released(int button, int x, int y, void *param);

#endif
