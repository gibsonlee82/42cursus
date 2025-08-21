/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giblee <abc@abc.com>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 10:00:33 by giblee            #+#    #+#             */
/*   Updated: 2025/08/19 11:05:09 by giblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include <unistd.h>

/**********************************************************************
 * Moves the top element from one stack to another.
 * - from: Pointer to the source stack (element will be removed here).
 * - to  : Pointer to the destination stack (element will be added here).
 *
 * This function:
 * - Checks if the source stack is non-empty.
 * - Removes the first element from the source stack.
 * - Inserts the removed element at the top of the destination stack.
 *
 * If the source stack is empty, no operation is performed.
**********************************************************************/
static void	push(t_list **from, t_list **to)
{
	t_list	*tmp;

	if (!*from)
		return ;
	tmp = *from;
	*from = (*from)->next;
	tmp->next = *to;
	*to = tmp;
}

void	pa(t_list **a, t_list **b)
{
	push(b, a);
	write(1, "pa\n", 3);
}

void	pb(t_list **a, t_list **b)
{
	push(a, b);
	write(1, "pb\n", 3);
}
