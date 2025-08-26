/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giblee <abc@abc.com>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 10:00:33 by giblee            #+#    #+#             */
/*   Updated: 2025/08/19 12:39:14 by giblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/**********************************************************************
 * Frees a null-terminated array of strings.
 * - arr: Pointer to the array of strings to be freed.
 *
 * This function:
 * - Iterates through each element of the array.
 * - Frees each individual string.
 * - Frees the array pointer itself.
 *
 * The function assumes the array is null-terminated.
**********************************************************************/
void	free_split(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

/**********************************************************************
 * Safely parses a string into an integer with bounds checking.
 * - str: Pointer to a null-terminated string representing an integer.
 *
 * This function:
 * - Validates that the input string is not NULL or empty.
 * - Parses an optional '+' or '-' sign at the beginning.
 * - Ensures all characters after the sign are numeric digits.
 * - Accumulates the numeric value into a long to detect overflows.
 * - Checks for overflow/underflow relative to INT_MAX and INT_MIN.
 * - Calls error_exit(NULL, NULL) on invalid input or out-of-bounds value.
 *
 * Returns:
 * - The parsed integer as an int.
 *
 * This function guarantees:
 * - Only valid, bounded integers are returned.
 * - Malformed or unsafe inputs trigger a controlled exit.
 **********************************************************************/
static int	parse_int_safe(const char *str)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	if (!str || !*str)
		error_exit(NULL, NULL);
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			error_exit(NULL, NULL);
		result = result * 10 + (str[i] - '0');
		if (sign == 1 && result > INT_MAX)
			error_exit(NULL, NULL);
		if (sign == -1 && (sign * result) < INT_MIN)
			error_exit(NULL, NULL);
		i++;
	}
	return ((int)(sign * result));
}

/**********************************************************************
* Adds a new integer to the stack as a t_data node.
* - a: Pointer to the stack.
* - str: String representing a number to be added.
*
* This function:
* - Validates the string as a number.
* - Converts it to an int and checks for duplicates.
* - Allocates a t_data structure storing value and index.
* - Wraps it in a t_list node and appends to the stack.
*
* On error (invalid number, duplicate, or malloc failure), calls error_exit().
**********************************************************************/
static void	add_number(t_list **a, char **split, char *str)
{
	int		num;
	t_list	*new_node;
	t_data	*new_data;

	if (!is_valid_number(str))
		error_exit(a, split);
	num = parse_int_safe(str);
	if (num < INT_MIN || num > INT_MAX || is_duplicate(*a, num))
		error_exit(a, split);
	new_data = malloc(sizeof(t_data));
	if (!new_data)
		error_exit(a, split);
	new_data->value = (int)num;
	new_data->index = -1;
	new_node = ft_lstnew(new_data);
	if (!new_node)
	{
		free(new_data);
		error_exit(a, split);
	}
	ft_lstadd_back(a, new_node);
}

/**********************************************************************
* Splits a single argument containing multiple numbers and 
*      adds each number to the stack.
* - a: Pointer to the stack.
* - arg: String containing one or more numbers separated by spaces.
*
* This function:
* - Uses ft_split to separate numbers.
* - Calls add_number() for each element.
* - Frees the split array after use.
**********************************************************************/
static void	parse_string(t_list **a, char *arg)
{
	int		j;
	char	**nums;

	nums = ft_split(arg, ' ');
	if (!nums)
		error_exit(NULL, NULL);
	j = 0;
	while (nums[j])
	{
		add_number(a, nums, nums[j]);
		j++;
	}
	free_split(nums);
}

/**********************************************************************
* Parses all command-line arguments into stack A.
* - argc: Number of command-line arguments.
* - argv: Array of argument strings.
* - a: Pointer to the stack where numbers will be stored.
*
* This function:
* - Iterates through each argument (starting from argv[1]).
* - Calls parse_string() to handle each argument, which may contain 
*   multiple space-separated numbers.
* - Ensures that all numbers are validated and added to stack A.
*
* On invalid input (non-integer strings, duplicates, or out-of-range
* values), the program calls error_exit(), which writes "Error\n" to
* stderr and exits.
**********************************************************************/
void	parse_args(int argc, char **argv, t_list **a)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		parse_string(a, argv[i]);
		i++;
	}
}
