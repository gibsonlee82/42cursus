/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back_to_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giblee <abc@abc.com>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 16:50:33 by giblee            #+#    #+#             */
/*   Updated: 2025/08/21 11:04:51 by giblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int get_source_position(t_list *a, int val)
{
    int pos;
    int curr;
    int next;
    t_list *tmp;
    
    pos = 0;
    tmp = a;
    if (!a)
        return (0);
    while (tmp)
    {
        curr = ((t_data *)tmp->content)->value;
        if (tmp->next)
            next = ((t_data *)tmp->next->content)->value;
        else
            next = ((t_data *)a->content)->value; // wrap-around
        // Check if val fits between curr and next (ascending order)
        if ((curr < val && val < next) || 
            (curr > next && (val > curr || val < next))) // wrap-around case
            return (pos + 1);
        tmp = tmp->next;
        pos++;
    }
    return (0);
}

/**********************************************************************
 * rotate_to_top:
 * Rotates stack s so that the element at index comes to top.
 * Uses simultaneous rotation with paired stack if both costs align.
 * - s: target stack
 * - index: position to bring to top
 **********************************************************************/
static void rotate_to_top(t_list **a, int index)
{
    int size = ft_lstsize(*a);
    int cost = (index <= size / 2) ? index : index - size;
    while (cost > 0)
    {
        ra(a);
        cost--;
    }
    while (cost < 0)
    {
        rra(a);
        cost++;
    }
}

/**********************************************************************
 * push_back_to_a:
 *  Pushes all elements from B back to A in sorted order.
 *
 *  Parameters:
 *    - a: Stack A (partially sorted)
 *    - b: Stack B (elements to insert)
 **********************************************************************/
void push_back_to_a(t_list **a, t_list **b)
{
    int val;
    int target;
    while (*b)
    {
        val = ((t_data *)(*b)->content)->value;
        target = get_source_position(*a, val);
        rotate_to_top(a, target);
        pa(a, b);
    }
}