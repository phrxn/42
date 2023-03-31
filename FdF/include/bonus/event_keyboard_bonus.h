/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_keyboard_bonus.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 22:04:07 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/03/21 22:04:08 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_KEYBOARD_BONUS_H
# define EVENT_KEYBOARD_BONUS_H

# define VK_ESC 65307

# define VK_COMMA 44
# define VK_PERIOD 46

# define VK_A 97 
# define VK_C 99 
# define VK_D 100 
# define VK_G 103 
# define VK_I 105 
# define VK_M 109 
# define VK_Q 113 
# define VK_R 114 
# define VK_S 115 
# define VK_T 116 
# define VK_W 119 
# define VK_PLUS 61 
# define VK_MINUS 45 

# define VK_LEFT 65361 
# define VK_UP 65362
# define VK_RIGHT 65363
# define VK_DOWN 65364

int	key_pressed(int key, void *param);

#endif
