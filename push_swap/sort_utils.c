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
static void	get_top3values(t_list *a, int *first, int *second, int *third)
{
	t_data	*data;

	data = a->content;
	*first = data->value;
	data = a->next->content;
	*second = data->value;
	data = a->next->next->content;
	*third = data->value;
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

	get_top3values(*a, &first, &second, &third);
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

/**********************************************************************
 * find_min_index_pos:
 *  Finds the position of the smallest indexed element in a stack.
 *
 *  Parameters:
 *    - stack: The stack to search
 *
 *  Returns:
 *    - The 0-based position of the element with the smallest index
 **********************************************************************/
int find_min_value_pos(t_list *stack)
{
    int min_value;
    int pos;
    int min_pos;
    t_list *tmp;

    if (!stack)
        return (-1);

    tmp = stack;
    min_value = ((t_data *)tmp->content)->value;
    pos = 0;
    min_pos = 0;

    while (tmp)
    {
        if (((t_data *)tmp->content)->value < min_value)
        {
            min_value = ((t_data *)tmp->content)->value;
            min_pos = pos;
        }
        tmp = tmp->next;
        pos++;
    }
    return (min_pos);
}