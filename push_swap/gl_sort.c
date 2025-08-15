/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giblee <abc@abc.com>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 10:50:33 by giblee            #+#    #+#             */
/*   Updated: 2025/08/15 12:05:50 by giblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/**********************************************************************
 * Assigns a sorted rank (index) to each stack element.
 * - stack: Pointer to the stack to index.
 *
 * This function:
 * - Iterates over each node and compares its value with others.
 * - Counts how many values are smaller to determine the 0-based index.
 * - Stores the index in t_data->index for radix sort.
 *
 * Example:
 *   Stack values: 40, 10, 30
 *   Indices after indexing: 2, 0, 1
 **********************************************************************/
void	index_stack(t_list *stack)
{
	int		count;
	t_list	*tmp2;
	t_data	*d1;
	t_list	*tmp1;
	t_data	*d2;

	tmp1 = stack;
	while (tmp1)
	{
		count = 0;
		tmp2 = stack;
		d1 = tmp1->content;
		while (tmp2)
		{
			d2 = tmp2->content;
			if (d2->value < d1->value)
				count++;
			tmp2 = tmp2->next;
		}
		d1->index = count;
		tmp1 = tmp1->next;
	}
}

/**********************************************************************
 * process_bit_pass
 * ----------------
 * Processes one pass of radix sort for a specific bit position.
 * 
 * Parameters:
 *   a   - Pointer to stack A (list of t_data* nodes).
 *   b   - Pointer to stack B (used as a temporary stack).
 *   bit - Bit position to check (0 = least significant bit).
 *   size- Total number of elements in stack A.
 * 
 * Behavior:
 *   - Iterates through all elements in stack A.
 *   - Checks if the bit at position `bit` is set in d->index.
 *   - If bit is set, rotates stack A (ra).
 *   - If bit is not set, pushes to stack B (pb).
 *   - After processing all elements, pushes all from B back to A.
 **********************************************************************/
static void	process_bit_pass(t_list **a, t_list **b, int bit, int size)
{
	int		j;
	t_data	*d;

	j = 0;
	while (j < size)
	{
		d = (*a)->content;
		if ((d->index >> bit) & 1)
			ra(a);
		else
			pb(a, b);
		j++;
	}
	while (*b)
		pa(a, b);
}

/**********************************************************************
 * radix_sort
 * ----------
 * Sorts the stack A using a binary radix sort algorithm.
 * 
 * Parameters:
 *   a - Pointer to stack A (list of t_data* nodes).
 *   b - Pointer to stack B (temporary stack, initially empty).
 * 
 * Behavior:
 *   - Calculates the maximum number of bits needed based on the
 *     largest index in stack A.
 *   - For each bit position (from LSB to MSB):
 *       Calls process_bit_pass() to rearrange elements based on
 *       the current bit.
 *   - Sorting is done in ascending order based on index values.
 **********************************************************************/
void	radix_sort(t_list **a, t_list **b)
{
	int	size;
	int	max_bits;
	int	bit;

	size = ft_lstsize(*a);
	max_bits = 0;
	while ((size - 1) >> max_bits)
		max_bits++;
	bit = 0;
	while (bit < max_bits)
		process_bit_pass(a, b, bit++, size);
}

// Main GL sort
void	gl_sort(t_list **a, t_list **b)
{
	int	size;

	size = ft_lstsize(*a);
	if (size <= 1 || is_sorted(*a))
		return ;
	index_stack(*a);
	if (size <= 3)
		sort_three(a);
	else if (size <= 5)
		sort_five(a, b);
	else
		radix_sort(a, b);
}
