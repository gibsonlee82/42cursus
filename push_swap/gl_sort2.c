/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_sort2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giblee <abc@abc.com>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 16:50:33 by giblee            #+#    #+#             */
/*   Updated: 2025/08/21 11:04:51 by giblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**********************************************************************
 * final_rotate_a:
 *  Rotates stack A so that the smallest element is at the top.
 *  Uses the minimal number of rotations (ra or rra).
 *
 *  Parameters:
 *    - a: Stack A (sorted but possibly rotated)
 **********************************************************************/
void final_rotate_a(t_list **a)
{
    int min_pos = find_min_value_pos(*a);

    if (min_pos <= ft_lstsize(*a) / 2)
    {
        while (min_pos--)
            ra(a);
    }
    else
    {
        int rev = ft_lstsize(*a) - min_pos;
        while (rev--)
            rra(a);
    }
}

/**********************************************************************
 *  Sorts stack A using the cheapest move algorithm.
 *  Steps:
 *    1. Push two elements from A to B.
 *    2. Push cheapest elements from A to B maintaining B in 
 *           descending order.
 *    3. Sort the remaining 3 elements in A.
 *    4. Push all elements from B back to A, while maintaining A in 
 *           ascending order.
 *    5. Rotate A so smallest element is at the top (calls final_rotate_a).
 *
 *  Parameters:
 *    - a: Stack A (unsorted)
 *    - b: Stack B (empty)
 **********************************************************************/
void gl_sort2(t_list **a, t_list **b)
{
    if (ft_lstsize(*a) <= 3)
    {
        sort_three(a);
        return ;
    }
    pb(a, b);
    pb(a, b);
    while (ft_lstsize(*a) > 3)
        push_to_b_sorted(a, b);
    sort_three(a);
    push_back_to_a(a, b);
    final_rotate_a(a);
}
