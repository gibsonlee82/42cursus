/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_rotations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giblee <abc@abc.com>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 16:50:33 by giblee            #+#    #+#             */
/*   Updated: 2025/08/21 11:04:51 by giblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void do_rr(t_list **a, t_list **b, int *cost_a, int *cost_b)
{
    while (*cost_a > 0 && *cost_b > 0)
    {
        rr(a, b);
        (*cost_a)--;
        (*cost_b)--;
    }
}

static void do_rrr(t_list **a, t_list **b, int *cost_a, int *cost_b)
{
    while (*cost_a < 0 && *cost_b < 0)
    {
        rrr(a, b);
        (*cost_a)++;
        (*cost_b)++;
    }
}

static void do_single_rotations(t_list **a, t_list **b, int *cost_a, int *cost_b)
{
    while (*cost_a > 0)
    {
        ra(a);
        (*cost_a)--;
    }
    while (*cost_a < 0)
    {
        rra(a);
        (*cost_a)++;
    }
    while (*cost_b > 0)
    {
        rb(b);
        (*cost_b)--;
    }
    while (*cost_b < 0)
    {
        rrb(b);
        (*cost_b)++;
    }
}

/**********************************************************************
 *  Performs combined rotations (rr / rrr) and individual rotations.
 **********************************************************************/
void execute_rotations(t_list **a, t_list **b, int cost_a, int cost_b)
{
    do_rr(a, b, &cost_a, &cost_b);
    do_rrr(a, b, &cost_a, &cost_b);
    do_single_rotations(a, b, &cost_a, &cost_b);
}
