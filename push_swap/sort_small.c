/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giblee <abc@abc.com>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 10:50:33 by giblee            #+#    #+#             */
/*   Updated: 2025/08/19 11:06:25 by giblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/**********************************************************************
 * get_top_three_indices: Retrieves the indices of the top three elements.
 * - a: Pointer to the start of the stack.
 * - first, second, third: Pointers to integers to store the indices.
 **********************************************************************/
static void	get_top3indices(t_list *a, int *first, int *second, int *third)
{
	t_data	*data;

	data = a->content;
	*first = data->index;
	data = a->next->content;
	*second = data->index;
	data = a->next->next->content;
	*third = data->index;
}

/**********************************************************************
 * Sorts a stack of exactly three elements in ascending order.
 * - a: Pointer to the stack containing three elements.
 *
 * This function:
 * - Retrieves the index values of the top three elements.
 * - Applies the minimal sequence of operations (sa, ra, rra) to sort them.
 * - Covers all possible permutations of three elements:
 *     1. first > second < third, first < third: sa
 *        Example: 2 1 3 -> sa -> 1 2 3
 *     2. first > second > third: sa + rra
 *        Example: 3 2 1 -> sa -> 2 3 1 -> rra -> 1 2 3
 *     3. first > second < third, first > third: ra
 *        Example: 3 1 2 -> ra -> 1 2 3
 *     4. first < second > third, first > third: rra
 *        Example: 2 3 1 -> rra -> 1 2 3
 *     5. first < second > third, first < third: sa + ra
 *        Example: 1 3 2 -> sa -> 3 1 2 -> ra -> 1 2 3
 *     6. first < second < third, no action required
 *        Example: 1 2 3
 * Assumes the stack contains exactly three elements.
**********************************************************************/
void	sort_three(t_list **a)
{
	int	first;
	int	second;
	int	third;

	get_top3indices(*a, &first, &second, &third);
	if (first > second && second < third && first < third)
		sa(a);
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && second > third && first > third)
		rra(a);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}
}

/**********************************************************************
 * find_min_index_pos: Finds the position of the smallest index in the stack.
 * - stack: Pointer to the start of the stack.
 *
 * Returns:
 * - Zero-based position of the smallest index.
 **********************************************************************/
static int	find_min_index_pos(t_list *stack)
{
	t_data	*data;
	int		min_index;
	int		pos;
	int		min_pos;

	pos = 0;
	min_pos = 0;
	if (!stack)
		return (-1);
	data = stack->content;
	min_index = data->index;
	while (stack)
	{
		data = stack->content;
		if (data && (data->index < min_index))
		{
			min_index = data->index;
			min_pos = pos;
		}
		pos++;
		stack = stack->next;
	}
	return (min_pos);
}

/**********************************************************************
 * push_min_to_b: Moves the smallest element from stack A to stack B.
 * - a: Pointer to the main stack (source).
 * - b: Pointer to the auxiliary stack (destination).
 *
 * This function:
 * - Finds the smallest element in stack A.
 * - Rotates or reverse-rotates A to bring it to the top.
 * - Pushes the smallest element to stack B.
 **********************************************************************/
static void	push_min_to_b(t_list **a, t_list **b)
{
	int	min_pos;
	int	size;

	min_pos = find_min_index_pos(*a);
	size = ft_lstsize(*a);
	if (min_pos <= size / 2)
		while (min_pos-- > 0)
			ra(a);
	else
		while (min_pos++ < size)
			rra(a);
	pb(a, b);
}

/**********************************************************************
 * sort_five: Sorts a stack containing up to five elements in ascending order.
 * - a: Pointer to the main stack.
 * - b: Pointer to the auxiliary stack.
 *
 * This function:
 * - Moves the smallest elements from stack A to stack B until three remain.
 * - Sorts the remaining three elements using sort_three().
 * - Pushes back all elements from B to A.
 *
 * Assumes:
 * - Each element has a valid index.
 * - No duplicate elements exist.
**********************************************************************/
void	sort_five(t_list **a, t_list **b)
{
	while (ft_lstsize(*a) > 3)
		push_min_to_b(a, b);
	sort_three(a);
	while (*b)
		pa(a, b);
}
