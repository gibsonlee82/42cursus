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

/**********************************************************************
 *  Finds the correct position in stack A to insert a given value
 *  from stack B while maintaining ascending order.
 *  - a: Stack A
 *  - val: Value to insert
 *
 * Returns:
 *  - 0-based index in A where 'val' should be inserted.
 *    If the value fits between two elements, returns position + 1.
 *    Wrap-around is handled if 'val' is smaller than the smallest
 *    or larger than the largest element in A.
 *
 * Notes:
 *  - If stack A is empty, returns 0.
 **********************************************************************/
static int get_insert_position(t_list *a, int val)
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
            next = ((t_data *)a->content)->value;
        if ((curr < val && val < next) || 
            (curr > next && (val > curr || val < next)))
            return (pos + 1);
        tmp = tmp->next;
        pos++;
    }
    return (0);
}

/**********************************************************************
 * Rotates stack s so that the element at index comes to top.
 * - s: target stack
 * - index: position to bring to top
 **********************************************************************/
static void rotate_to_top(t_list **a, int index)
{
    int size;
    int cost;

    size = ft_lstsize(*a);
    if (index < size / 2)
        cost = index;
    else
        cost = index - size;
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
    int pos;
    while (*b)
    {
        val = ((t_data *)(*b)->content)->value;
        pos = get_insert_position(*a, val);
        rotate_to_top(a, pos);
        pa(a, b);
    }
}