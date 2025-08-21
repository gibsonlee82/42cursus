/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giblee <abc@abc.com>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 10:00:33 by giblee            #+#    #+#             */
/*   Updated: 2025/08/19 11:06:02 by giblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include <unistd.h>

/**********************************************************************
 * Swaps the top two elements of the given stack.
 * - stack: Pointer to the stack on which to perform the swap.
 *
 * This function:
 * - Checks if the stack has at least two elements.
 * - Exchanges the positions of the first and second nodes.
 * - Updates the stack pointer so the new first node is correct.
 *
 * If the stack has fewer than two elements, no operation is performed.
**********************************************************************/
static void	swap(t_list **stack)
{
	t_list	*first;
	t_list	*second;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	sa(t_list **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_list **b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_list **a, t_list **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
