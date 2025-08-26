/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b_sorted.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giblee <abc@abc.com>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 16:50:33 by giblee            #+#    #+#             */
/*   Updated: 2025/08/21 11:04:51 by giblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**********************************************************************
 *  Finds the index in stack B where a value from stack A should be
 *  inserted to keep B sorted in descending order.
 *    - b: Stack B
 *    - val: Value from stack A
 *
 *  Returns:
 *    - Index in B where 'val' should be inserted
 **********************************************************************/
static int get_target_position(t_list *b, int val)
{
    int pos;
    int best_index;
    int best_val;
    int bval;
    t_list *tmp;

    pos = 0;
    best_index = 0;
    best_val = INT_MIN;
    tmp = b;
    while (tmp)
    {
        bval = ((t_data *)tmp->content)->value;
        if (bval < val && bval > best_val)
        {
            best_val = bval;
            best_index = pos + 1;
        }
        tmp = tmp->next;
        pos++;
    }
    if (!b)
        return (0);
    return (best_index % pos);
}

/**********************************************************************
 * Scans A to find the element with the minimal move cost to B.
 * Accounts for simultaneous rotations (rr/rrr).
 * - a: Stack A
 * - b: Stack B
 * Return: Index of the cheapest element to move
 **********************************************************************/
static t_cost find_cheapest_for_b(t_list *a, t_list *b)
{
    int i;
    int cheapest_index;
    t_cost curr_cost;
    t_cost min_cost;
    t_stacks stacks;
    t_list *tmp;

    i = 0;
    cheapest_index = 0;
    min_cost.total = INT_MAX;
    tmp = a;
    stacks.src = a;
    stacks.dst = b;
    while (tmp)
    {
        curr_cost = compute_cost(stacks, i, get_target_position);
        update_if_cheaper(curr_cost, i, &cheapest_index, &min_cost);
        tmp = tmp->next;
        i++;
    }
    return (min_cost);
}

/**********************************************************************
 * push_to_b_sorted:
 *  Pushes the cheapest element from A to B while keeping B sorted
 *  in descending order.
 **********************************************************************/
void push_to_b_sorted(t_list **a, t_list **b)
{
    t_cost  cost;

    cost = find_cheapest_for_b(*a, *b);
    execute_rotations(a, b, cost.src, cost.dst);
    pb(a, b);
}