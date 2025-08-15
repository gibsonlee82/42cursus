/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giblee <abc@abc.com>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 10:50:33 by giblee            #+#    #+#             */
/*   Updated: 2025/08/15 12:05:50 by giblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/**********************************************************************
 * Checks if a string represents a valid integer number.
 * - str: The string to be validated.
 *
 * This function:
 * - Allows an optional leading '+' or '-' sign.
 * - Requires at least one digit after an optional sign.
 * - Ensures all remaining characters are numeric digits.
 *
 * Returns:
 * - 1 if the string is a valid integer format.
 * - 0 otherwise.
**********************************************************************/
int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (!str[i] || (str[i] == '-' && !str[i + 1]))
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/**********************************************************************
 * Checks if a given number already exists in the stack.
 * - a  : Pointer to the stack to be searched.
 * - num: The integer value to check for duplicates.
 *
 * This function:
 * - Iterates through each element of the stack.
 * - Compares the stored integer value with the given number.
 *
 * Returns:
 * - 1 if the number is found in the stack.
 * - 0 if the number is not found.
**********************************************************************/
int	is_duplicate(t_list *a, int num)
{
	t_data	*data;

	while (a)
	{
		data = a->content;
		if (data->value == num)
			return (1);
		a = a->next;
	}
	return (0);
}

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

/**********************************************************************
 * Checks if the stack is sorted in ascending order.
 * - a: Pointer to the stack to be checked.
 *
 * This function:
 * - Iterates through the stack from top to bottom.
 * - Compares each element with the next one.
 *
 * Returns:
 * - 1 if the stack is sorted in ascending order.
 * - 0 if any element is greater than the next element.
**********************************************************************/
int	is_sorted(t_list *a)
{
	t_data	*curr;
	t_data	*next;

	while (a && a->next)
	{
		curr = a->content;
		next = a->next->content;
		if (curr->value > next->value)
			return (0);
		a = a->next;
	}
	return (1);
}
