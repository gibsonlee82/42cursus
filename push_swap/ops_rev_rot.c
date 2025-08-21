/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rev_rot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giblee <abc@abc.com>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 10:00:33 by giblee            #+#    #+#             */
/*   Updated: 2025/08/19 11:05:29 by giblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include <unistd.h>

/**********************************************************************
 * Shifts all elements of the given stack downwards by one position.
 * - stack: Pointer to the stack to be reverse rotated.
 *
 * This function:
 * - Checks if the stack contains at least two elements.
 * - Finds the last element in the stack and the node before it.
 * - Moves the last element to the top of the stack.
 *
 * If the stack has fewer than two elements, no operation is performed.
**********************************************************************/
static void	reverse_rotate(t_list **stack)
{
	t_list	*prev;
	t_list	*last;

	if (!*stack || !(*stack)->next)
		return ;
	prev = *stack;
	while (prev->next && prev->next->next)
		prev = prev->next;
	last = prev->next;
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rra(t_list **a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_list **b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_list **a, t_list **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}
