/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giblee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 11:10:25 by giblee            #+#    #+#             */
/*   Updated: 2025/05/07 11:13:01 by giblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void	*ft_memcpy(void *dest, const void *src, size_t n);

// Copy n bytes from memory area src to memory area dest.  
// The memory areas may overlap: copying takes place as though 
// the bytes in src are first copied into a temporary array that 
// does not overlap src or dest, and the bytes are then copied from 
// the temporary array to dest.
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (!d && !s)
		return (NULL);
	if (s > d)
		return (ft_memcpy(d, s, n));
	else
		while (n--)
			d[n] = s[n];
	return (d);
}
