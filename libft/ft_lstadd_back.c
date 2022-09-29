/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:01:36 by dmanoel-          #+#    #+#             */
/*   Updated: 2022/09/08 16:13:05 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_no;

	if (!lst)
		return ;
	last_no = ft_lstlast(*lst);
	if (last_no)
		last_no->next = new;
	else
		*lst = new;
}
