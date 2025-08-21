/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giblee <abc@abc.com>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 10:00:33 by giblee            #+#    #+#             */
/*   Updated: 2025/08/19 11:13:10 by giblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include <stdlib.h>

static int	cleanup_and_exit(t_list **a, t_list **b, int exit_code)
{
	free_stack(a);
	free_stack(b);
	return (exit_code);
}

/**********************************************************************
 * main: Entry point of the program. Parses input, checks if sorting is
 *       needed, and performs sorting if required.
 * - argc: Argument count.
 * - argv: Argument vector containing input values to be sorted.
 *
 * This function:
 * - Initializes two stacks (a and b).
 * - Parses command-line arguments into stack A.
 * - Checks if stack A is already sorted.
 * - If not sorted, calls gl_sort() to sort the stack using stack B.
 * - Cleans up all allocated memory before exiting.
 *
 * Assumes:
 * - Input arguments are valid integers (validated in parse_args).
 * - No duplicate values are passed.
 * - Stack A is built from argv[1] to argv[argc - 1].
 **********************************************************************/
int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	parse_args(argc, argv, &a);
	if (is_sorted(a))
		return (cleanup_and_exit(&a, &b, 0));
	gl_sort2(&a, &b);
	return (cleanup_and_exit(&a, &b, 0));
}
