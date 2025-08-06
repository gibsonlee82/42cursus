/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giblee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 14:47:53 by giblee            #+#    #+#             */
/*   Updated: 2025/05/13 15:10:56 by giblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Iterates through the list ’lst’ and applies the
// function ’f’ to the content of each node.
// lst: The address of a pointer to a node.
// f: The address of the function to apply to each node’s content.
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*iter;

	if (!lst || !f)
		return ;
	iter = lst;
	while (iter)
	{
		f(iter->content);
		iter = iter->next;
	}
}
