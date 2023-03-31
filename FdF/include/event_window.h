/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_window.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 22:01:17 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/03/21 22:01:18 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_WINDOW_H
# define EVENT_WINDOW_H

int	window_destroy(void *param);

int	window_expose(void *param);

int	window_visibly(void *param);

#endif
