/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giblee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 11:20:54 by giblee            #+#    #+#             */
/*   Updated: 2025/05/07 13:23:10 by giblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Return a pointer to the last occurrence of the char c in the str s
char	*ft_strrchr(const char *s, int c)
{
	int		n;

	n = (int)ft_strlen(s);
	if (!((unsigned char)c))
		return ((char *)&s[n]);
	while (n >= 0)
	{
		if (s[n] == (unsigned char)c)
			return ((char *)&s[n]);
		n--;
	}
	return (NULL);
}
