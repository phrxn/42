/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanoel- <dmanoel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:25:22 by dmanoel-          #+#    #+#             */
/*   Updated: 2023/06/26 22:30:12 by dmanoel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/convert.h"
#include <limits.h>
#include <stdlib.h>

/**
 * Converts a number in a string to an int. This method checks if there was 
 * an overflow or underflow during the conversion.
 *
 * @number:	a string with number
 * @status: sets 0 if the conversion went well, 1 if there was an overflow or
 * 			underflow.
 *
 * Return: a int with the number.
 */
int	ft_atoi(const char *number, int *status)
{
	long	int_to_return;
	char	is_negative;

	is_negative = 1;
	int_to_return = 0;
	if (*number == '-' || *number == '+')
	{
		if (*number == '-')
			is_negative = -1;
		number++;
	}
	while (*number >= '0' && *number <= '9')
	{
		int_to_return = (int_to_return * 10) + (*number++ - '0');
		if ((is_negative == 1 && int_to_return > INT_MAX)
			|| (is_negative == -1 && int_to_return > ((long)INT_MAX + 1)))
		{
			*status = 1;
			return (0);
		}
	}
	*status = 0;
	return (int_to_return * is_negative);
}

/**
 * Converts an array of strings to an array of ints.
 * 
 * @argv:	an array of strings.
 * @argv_size:	the argv size
 *
 * Return: a pointer to an array of integers or NULL if an error occurs.
 */
int	*ft_atoi_argv(char **argv, int argv_size)
{
	int	*array_int;
	int	status;
	int	count;

	count = 0;
	array_int = malloc(sizeof * array_int * argv_size);
	if (!array_int)
		return (0);
	while (argv[count])
	{
		array_int[count] = ft_atoi(argv[count], &status);
		if (status)
		{
			free(array_int);
			return (0);
		}
		count++;
	}
	return (array_int);
}

/**
 * Converts array values to index.
 *
 * @array: the pointer to array that must have its values converted to an index.
 * @array_size: the array size
 * @start_index: initial start value (must be) 0.
 *
 */
void	create_index(int *array, int array_size, unsigned int start_index)
{
	int	index;
	int	count;
	int	actual_value;

	if (start_index == array_size)
		return ;
	index = 0;
	count = 0;
	actual_value = array[start_index];
	while (count < array_size)
	{
		if (actual_value > array[count])
			index++;
		count++;
	}	
	if (start_index < array_size)
		create_index(array, array_size, start_index + 1);
	array[start_index] = index;
}
