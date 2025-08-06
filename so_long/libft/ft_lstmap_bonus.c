/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giblee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 14:52:47 by giblee            #+#    #+#             */
/*   Updated: 2025/05/14 10:47:06 by giblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Iterates through the list ’lst’, applies the
// function ’f’ to each node’s content, and creates
// a new list resulting of the successive applications
// of the function ’f’. The ’del’ function is used to
// delete the content of a node if needed.
// lst: The address of a pointer to a node.
// f: The address of the function applied to each node’s content.
// del: The address of the function used to delete a node’s content if needed.
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*result;

	head = NULL;
	while (lst)
	{
		result = ft_lstnew((*f)(lst -> content));
		if (!result)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		ft_lstadd_back(&head, result);
		lst = lst -> next;
	}
	return (head);
}

// t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
// {
// 	t_list	*new_list;
// 	t_list	*new_node;
// 	void	*new_content;
// 	t_list	*temp;
//
// 	new_list = NULL;
// 	if (!lst || !f)
// 		return (NULL);
// 	while (lst)
// 	{
// 		new_content = f(lst->content);
// 		new_node = ft_lstnew(new_content);
// 		if (!new_node)
// 		{
// 			ft_lstclear(&new_list, del);
// 			return (NULL);
// 		}
// 		temp = new_list;
// 		if (!temp)
// 			new_list = new_node;
// 		else
// 		{
// 			while (temp->next)
// 				temp = temp->next;
// 			temp->next = new_node;
// 		}
// 			lst = lst->next;
// 	}
// 	return (new_list);
// }
