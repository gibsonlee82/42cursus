/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giblee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 11:06:34 by giblee            #+#    #+#             */
/*   Updated: 2025/05/07 12:51:50 by giblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//void	*ft_memset(void *ptr, int value, size_t num);

// Erases the data in the n bytes of the memory 
// starting at the location pointed to by s, 
// by writing zeros (bytes containing '\0') to that area.
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
