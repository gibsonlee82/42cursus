/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giblee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 14:42:48 by giblee            #+#    #+#             */
/*   Updated: 2025/05/13 14:46:57 by giblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Deletes and frees the given node and all its
// successors, using the function ’del’ and free(3).
// Finally, set the pointer to the list to NULL.
// lst: The address of a pointer to a node.
// del: The address of the function used to delete
// the content of the node.
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*ilist;

	if (!lst || !del)
		return ;
	ilist = *lst;
	while (ilist)
	{
		tmp = (ilist)->next;
		del((ilist)->content);
		free(ilist);
		ilist = tmp;
	}
	*lst = NULL;
}
