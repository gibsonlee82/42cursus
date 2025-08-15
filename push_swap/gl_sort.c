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
* radix_sort: Sorts a stack using bitwise radix sort via an auxiliary stack.
* - a: Pointer to the main stack.
* - b: Pointer to the auxiliary stack.
*
* This function:
* - Computes the number of bits needed for the maximum index.
* - For each bit position:
*     - Pushes nodes with 0 at that bit to stack B.
*     - Rotates nodes with 1 at that bit in stack A.
* - Moves all nodes back from B to A.
*
* Requires:
* - Each node has a valid index assigned by index_stack().
**********************************************************************/
void	radix_sort(t_list **a, t_list **b)
{
	int		size;
	int		max_bits;
	int		i;
	int		j;
	t_data	*d;

	size = ft_lstsize(*a);
	max_bits = 0;
	while ((size - 1) >> max_bits)
		max_bits++;
	i = 0;
	j = 0;
	while (i++ < max_bits)
	{
		while (j++ < size)
		{
			d = (*a)->content;
			if ((d->index >> i) & 1)
				ra(a);
			else
				pb(a, b);
		}
		while (*b)
			pa(a, b);
	}
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
