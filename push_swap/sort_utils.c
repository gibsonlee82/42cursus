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

/**********************************************************************
 * Helper function to get max of 2 values
 **********************************************************************/
int ft_max(int a, int b)
{
    if (a > b)
        return (a);
    else
        return (b);
}

/**********************************************************************
 * Helper function to update the cheapest move.
 **********************************************************************/
void update_if_cheaper(int cost, int i, int cost_a, int cost_b,
    int *min_cost, int *cheapest, int *best_cost_a, int *best_cost_b)
{
    if (cost < *min_cost)
    {
        *min_cost = cost;
        *cheapest = i;
        *best_cost_a = cost_a;
        *best_cost_b = cost_b;
    }
}

/**********************************************************************
 * Computes the cost of moving an element from one stack to another, 
 *	depending on direction.
 *
 * Returns: combined cost for the move.
 **********************************************************************/
int compute_cost(t_list *src, t_list *dst, int pos, int *cost_src,
    int *cost_dst, int (*get_pos_fn)(t_list *, int))
{
    int size_src;
    int size_dst;
    int val;
    int dst_pos;

    size_src = ft_lstsize(src);
    size_dst = ft_lstsize(dst);

    val = ((t_data *)ft_lstget(src, pos)->content)->value;
    dst_pos = get_pos_fn(dst, val);

    if (pos <= size_src / 2)
        *cost_src = pos;
    else
        *cost_src = pos - size_src;

    if (dst_pos <= size_dst / 2)
        *cost_dst = dst_pos;
    else
        *cost_dst = dst_pos - size_dst;

    if ((*cost_src > 0 && *cost_dst > 0) || (*cost_src < 0 && *cost_dst < 0))
        return ft_max(abs(*cost_src), abs(*cost_dst));
    else
        return abs(*cost_src) + abs(*cost_dst);
}
