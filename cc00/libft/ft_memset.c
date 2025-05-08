/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giblee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 11:06:00 by giblee            #+#    #+#             */
/*   Updated: 2025/05/07 12:51:21 by giblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stddef.h>

// set a block of memory to specific value
void	*ft_memset(void *ptr, int value, size_t num)
{
	unsigned char	*str;

	str = (unsigned char *) ptr;
	while (num > 0)
	{
		str[num - 1] = (unsigned char) value;
		num--;
	}
	return (ptr);
}
