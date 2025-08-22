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
 * Calculates the minimal total moves needed to push element at
 * position apos in A to the correct position in B, considering
 * simultaneous rotations (rr) or reverse rotations (rrr).
 * - a: Stack A
 * - b: Stack B
 * - apos: Position in A
 * Return: Minimal move count (int)
 **********************************************************************/
static int compute_cost(t_list *a, t_list *b, int apos, int *cost_a, int *cost_b)
{
    int size_a;
    int size_b;
    int val;
    int bpos;

    size_a = ft_lstsize(a);
    size_b = ft_lstsize(b);
    if (apos <= size_a / 2)
        *cost_a = apos;
    else
        *cost_a = apos - size_a;
    val = ((t_data *)ft_lstget(a, apos)->content)->value;
    bpos = get_target_position(b, val);
    if (bpos <= size_b / 2)
        *cost_b = bpos;
    else
        *cost_b = bpos - size_b;
    if ((*cost_a > 0 && *cost_b > 0) || (*cost_a < 0 && *cost_b < 0))
        return (ft_max(abs(*cost_a), abs(*cost_b)));
    else
        return (abs(*cost_a) + abs(*cost_b));
}

/**********************************************************************
 * Helper function to update index and cost of cheapest move
 **********************************************************************/
static void update_cheapest(int cost, int i, int cost_a, int cost_b,
    int *min_cost, int *cheapest_index, int *best_cost_a, int *best_cost_b)
{
    if (cost < *min_cost)
    {
        *min_cost = cost;
        *cheapest_index = i;
        *best_cost_a = cost_a;
        *best_cost_b = cost_b;
    }
}

/**********************************************************************
 * Scans A to find the element with the minimal move cost to B.
 * Accounts for simultaneous rotations (rr/rrr).
 * - a: Stack A
 * - b: Stack B
 * Return: Index of the cheapest element to move
 **********************************************************************/
static int find_cheapest(t_list *a, t_list *b, int *best_cost_a, int *best_cost_b)
{
    int i;
    int cheapest_index;
    int min_cost;
    int cost_a;
    int cost_b;
    int cost;
    t_list *tmp;

    i = 0;
    cheapest_index = 0;
    min_cost = INT_MAX;
    tmp = a;
    *best_cost_a = 0;
    *best_cost_b = 0;
    while (tmp)
    {
        cost = compute_cost(a, b, i, &cost_a, &cost_b);
        if (cost < min_cost)
            update_cheapest(cost, i, cost_a, cost_b, 
                &min_cost, &cheapest_index, best_cost_a, best_cost_b);
        tmp = tmp->next;
        i++;
    }
    return cheapest_index;
}

/**********************************************************************
 * push_to_b_sorted:
 *  Pushes the cheapest element from A to B while keeping B sorted
 *  in descending order.
 **********************************************************************/
void push_to_b_sorted(t_list **a, t_list **b)
{
    int cost_a;
    int cost_b;

    find_cheapest(*a, *b, &cost_a, &cost_b);
    execute_rotations(a, b, cost_a, cost_b);
    pb(a, b);
}
