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
 * get_insert_position:
 *  Finds the index in ascending circular stack A where val from B
 *  should be inserted to maintain ascending order.
 *  Returns 0-based index.
 **********************************************************************/
static int get_insert_position(t_list *a, int val)
{
    int pos = 0;
    t_list *tmp = a;
    int min_val = INT_MAX;
    int max_val = INT_MIN;
    int max_pos = 0;

    if (!a)
        return 0;

    // find min/max in A
    while (tmp)
    {
        int curr = ((t_data *)tmp->content)->value;
        if (curr < min_val) min_val = curr;
        if (curr > max_val) { max_val = curr; max_pos = pos; }
        tmp = tmp->next;
        pos++;
    }

    if (val < min_val || val > max_val)
        return (max_pos + 1) % pos;

    pos = 0;
    tmp = a;
    while (tmp)
    {
        int curr = ((t_data *)tmp->content)->value;
        int next = tmp->next ? ((t_data *)tmp->next->content)->value
                              : ((t_data *)a->content)->value;
        if ((curr < next && curr < val && val < next) ||
            (curr > next && (val > curr || val < next)))
            return pos + 1;
        tmp = tmp->next;
        pos++;
    }
    return 0;
}

/**********************************************************************
 * compute_cost_for_a:
 *  Calculates move cost to push B[bpos] into correct A position.
 **********************************************************************/
static int compute_cost_for_a(t_list *a, t_list *b, int bpos,
    int *cost_a, int *cost_b)
{
    int size_a = ft_lstsize(a);
    int size_b = ft_lstsize(b);
    int val = ((t_data *)ft_lstget(b, bpos)->content)->value;
    int apos = get_insert_position(a, val);

    *cost_b = (bpos <= size_b / 2) ? bpos : bpos - size_b;
    *cost_a = (apos <= size_a / 2) ? apos : apos - size_a;

    if ((*cost_a > 0 && *cost_b > 0) || (*cost_a < 0 && *cost_b < 0))
        return ft_max(abs(*cost_a), abs(*cost_b));
    else
        return abs(*cost_a) + abs(*cost_b);
}

/**********************************************************************
 * find_cheapest_for_a:
 *  Finds B element with minimal moves to A.
 **********************************************************************/
static int find_cheapest_for_a(t_list *b, t_list *a,
    int *best_cost_a, int *best_cost_b)
{
    int i = 0, cheapest = 0, min_cost = INT_MAX, cost_a, cost_b, cost;
    t_list *tmp = b;

    *best_cost_a = 0;
    *best_cost_b = 0;
    while (tmp)
    {
        cost = compute_cost_for_a(a, b, i, &cost_a, &cost_b);
        if (cost < min_cost)
        {
            min_cost = cost;
            cheapest = i;
            *best_cost_a = cost_a;
            *best_cost_b = cost_b;
        }
        tmp = tmp->next;
        i++;
    }
    return cheapest;
}

/**********************************************************************
 * push_back_to_a_sorted:
 *  Push all elements from B to A in ascending order with minimal moves.
 **********************************************************************/
void push_back_to_a_sorted(t_list **a, t_list **b)
{
    int cost_a, cost_b;

    while (*b)
    {
        find_cheapest_for_a(*b, *a, &cost_a, &cost_b);
        execute_rotations(a, b, cost_a, cost_b);
        pa(a, b);
    }
}
