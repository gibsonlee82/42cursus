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
 * get_target_position:
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

static int ft_max(int a, int b)
{
    if (a > b)
        return (a);
    else
        return (b);
}

/**********************************************************************
 * calc_cost:
 * Calculates the minimal total moves needed to push element at
 * position apos in A to the correct position in B, considering
 * simultaneous rotations (rr) or reverse rotations (rrr).
 * - a: Stack A
 * - b: Stack B
 * - apos: Position in A
 * Return: Minimal move count (int)
 **********************************************************************/
static int calc_cost(t_list *a, t_list *b, int apos)
{
    int size_a;
    int size_b;
    int val;
    int bpos;
    int cost_a;
    int cost_b;

    size_a = ft_lstsize(a);
    size_b = ft_lstsize(b);
    if (apos <= size_a / 2)
        cost_a = apos;
    else
        cost_a = apos - size_a;
    val = ((t_data *)ft_lstget(a, apos)->content)->value;
    bpos = get_target_position(b, val);
    if (bpos <= size_b / 2)
        cost_b = bpos;
    else
        cost_b = bpos - size_b;
    if ((cost_a > 0 && cost_b > 0) || (cost_a < 0 && cost_b < 0))
        return (ft_max(abs(cost_a), abs(cost_b)));
    else
        return (abs(cost_a) + abs(cost_b));
}

/**********************************************************************
 * find_cheapest:
 * Scans A to find the element with the minimal move cost to B.
 * Accounts for simultaneous rotations (rr/rrr).
 * - a: Stack A
 * - b: Stack B
 * Return: Index of the cheapest element to move
 **********************************************************************/
static int find_cheapest(t_list *a, t_list *b)
{
    int i;
    int cheapest_a;
    int min_cost;
    t_list *tmp;
    int cost;

    i = 0;
    cheapest_a = 0;
    min_cost = INT_MAX;
    tmp = a;
    while (tmp)
    {
        cost = calc_cost(a, b, i);
        if (cost < min_cost)
        {
            min_cost = cost;
            cheapest_a = i;
        }
        tmp = tmp->next;
        i++;
    }
    return (cheapest_a);
}

/**********************************************************************
 * compute_costs:
 *  Calculates rotation costs for stacks A and B to move an element
 *  efficiently.
 **********************************************************************/
static void compute_costs(t_list *a, t_list *b, int apos, int target,
    int *cost_a, int *cost_b)
{
    int size_a;
    int size_b;

    size_a = ft_lstsize(a);
    size_b = ft_lstsize(b);

    if (apos <= size_a / 2)
        *cost_a = apos;
    else
        *cost_a = apos - size_a;

    if (target <= size_b / 2)
        *cost_b = target;
    else
        *cost_b = target - size_b;
}

/**********************************************************************
 * execute_rotations:
 *  Performs combined rotations (rr / rrr) and individual rotations
 *  based on calculated costs.
 **********************************************************************/
static void execute_rotations(t_list **a, t_list **b, int cost_a, int cost_b)
{
    while (cost_a > 0 && cost_b > 0)
        rr(a, b), cost_a--, cost_b--;
    while (cost_a < 0 && cost_b < 0)
        rrr(a, b), cost_a++, cost_b++;
    while (cost_a > 0)
        ra(a), cost_a--;
    while (cost_a < 0)
        rra(a), cost_a++;
    while (cost_b > 0)
        rb(b), cost_b--;
    while (cost_b < 0)
        rrb(b), cost_b++;
}

/**********************************************************************
 * push_to_b_sorted:
 *  Pushes the cheapest element from A to B while keeping B sorted
 *  in descending order.
 **********************************************************************/
void push_to_b_sorted(t_list **a, t_list **b)
{
    int apos;
    int bpos;
    int val;
    int cost_a;
    int cost_b;

    apos = find_cheapest(*a, *b);
    val = ((t_data *)ft_lstget(*a, apos)->content)->value;
    bpos = get_target_position(*b, val);
    compute_costs(*a, *b, apos, bpos, &cost_a, &cost_b);
    execute_rotations(a, b, cost_a, cost_b);
    pb(a, b);
}
