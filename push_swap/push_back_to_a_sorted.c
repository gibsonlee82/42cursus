/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back_to_a_sorted.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giblee <abc@abc.com>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 16:50:33 by giblee            #+#    #+#             */
/*   Updated: 2025/08/21 11:04:51 by giblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**********************************************************************
 * Finds the minimum and maximum values in stack A, along with the
 * position of the maximum value.
 *   a        - Stack A
 *   min_val  - Pointer to store minimum value
 *   max_val  - Pointer to store maximum value
 *   max_pos  - Pointer to store position of maximum value
 *
 * Return:
 *   Size of stack A
 **********************************************************************/
static int get_min_max_info(t_list *a, int *min_val, int *max_val, int *max_pos)
{
    int     pos;
    int     curr;
    t_list  *tmp;

    pos = 0;
    *min_val = INT_MAX;
    *max_val = INT_MIN;
    *max_pos = 0;
    tmp = a;
    while (tmp)
    {
        curr = ((t_data *)tmp->content)->value;
        if (curr < *min_val)
            *min_val = curr;
        if (curr > *max_val)
        {
            *max_val = curr;
            *max_pos = pos;
        }
        tmp = tmp->next;
        pos++;
    }
    return (pos);
}

/**********************************************************************
 * Finds the position where val fits between two consecutive elements
 * in stack A (considering wrap-around).
 *   a    - Stack A
 *   val  - Value to insert
 *
 * Return:
 *   Position where val should be inserted, or 0 if not found
 **********************************************************************/
static int find_between_position(t_list *a, int val)
{
    int     pos;
    int     curr;
    int     next;
    t_list  *tmp;

    pos = 0;
    tmp = a;
    while (tmp)
    {
        curr = ((t_data *)tmp->content)->value;
        if (tmp->next)
            next = ((t_data *)tmp->next->content)->value;
        else
            next = ((t_data *)a->content)->value;
        if ((curr < next && curr < val && val < next) ||
            (curr > next && (val > curr || val < next)))
            return (pos + 1);
        tmp = tmp->next;
        pos++;
    }
    return (0);
}

/**********************************************************************
 * Finds the index in stack A where a value from stack B should be
 * inserted to keep A sorted in ascending order (circular).
 *   a    - Stack A
 *   val  - Value from stack B
 *
 * Return:
 *   Index in A where 'val' should be inserted
 **********************************************************************/
static int get_insert_position(t_list *a, int val)
{
    int min_val;
    int max_val;
    int max_pos;
    int size;

    if (!a)
        return (0);
    size = get_min_max_info(a, &min_val, &max_val, &max_pos);
    if (val < min_val || val > max_val)
        return ((max_pos + 1) % size);
    return (find_between_position(a, val));
}

/**********************************************************************
 * find_cheapest_for_a:
 *  Finds B element with minimal moves to A.
 **********************************************************************/
static int find_cheapest_for_a(t_list *b, t_list *a,
    int *best_cost_a, int *best_cost_b)
{
    int i;
    int cheapest_index;
    int min_cost;
    int cost_a;
    int cost_b;
    int cost;

    i = 0;
    cheapest_index = 0;
    min_cost = INT_MAX;
    t_list *tmp = b;
    *best_cost_a = 0;
    *best_cost_b = 0;
    while (tmp)
    {
        //cost = compute_cost_for_a(a, b, i, &cost_a, &cost_b);
        cost = compute_cost(b, a, i, &cost_b, &cost_a, get_insert_position);
        update_if_cheaper(cost, i, cost_a, cost_b, 
            &min_cost, &cheapest_index, best_cost_a, best_cost_b);
        tmp = tmp->next;
        i++;
    }
    return (cheapest_index);
}

/**********************************************************************
 * push_back_to_a_sorted:
 *  Push all elements from B to A in ascending order with minimal moves.
 **********************************************************************/
void push_back_to_a_sorted(t_list **a, t_list **b)
{
    int cost_a;
    int cost_b;

    while (*b)
    {
        find_cheapest_for_a(*b, *a, &cost_a, &cost_b);
        execute_rotations(a, b, cost_a, cost_b);
        pa(a, b);
    }
}
