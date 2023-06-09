/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 14:08:58 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/04/21 21:27:42 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/argv.h"
#include "../libs/libft/libft.h"

static void	find_and_replace(char *str, char find, char replace)
{
	while (*str)
	{
		if (*str == find)
			*str = replace;
		str++;
	}
}

/**
 * apply_candidate - replaces spaces in parameters within commands.
 * @start:	full command with or without args.
 *
 * Return:
 * 	0 - If successful
 * 	1 - If there's a quote or double quote opened.
 */
int	apply_candidate(char *start, char space_replace)
{
	char	*quote;

	quote = start;
	while (*quote && (*quote != '\'' && *quote != '\"'))
		quote++;
	if (!*quote)
		return (0);
	start = (quote + 1);
	while (*start && *start != *quote)
		start++;
	if (!*start)
		return (1);
	if (!apply_candidate(start + 1, space_replace))
	{
		while (++quote < start)
			if (*quote == ' ')
				*quote = space_replace;
		return (0);
	}
	return (1);
}

/**
 * select_candidate - selects a char to replace the space in the split.
 * @str:	full command with or without args.
 *
 * Returns:
 * 	A char or NULL if no char is found.
 */
char	select_candidate(char *str)
{
	char	candidate;

	candidate = 127;
	while (candidate)
	{
		if (ft_strchr(str, candidate))
			candidate--;
		else
			break ;
	}
	return (candidate);
}

void	replace_candidate_to_space(char **argv, char candidate)
{
	if (!argv || !*argv)
		return ;
	while (*argv)
		find_and_replace(*argv++, candidate, ' ');
}
