/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giblee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 14:21:03 by giblee            #+#    #+#             */
/*   Updated: 2025/05/14 13:37:21 by giblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Counts the number of nodes in the list.
// lst: The beginning of the list.
int	ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*iter;

	count = 0;
	iter = lst;
	while (iter)
	{
		count++;
		iter = iter->next;
	}
	return (count);
}
