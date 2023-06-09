/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 14:16:15 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/04/24 19:16:57 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGV_H
# define ARGV_H

int		apply_candidate(char *start, char space_replace);

char	select_candidate(char *str);

void	replace_candidate_to_space(char **argv, char candidate);

#endif
