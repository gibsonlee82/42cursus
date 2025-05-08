/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giblee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 11:33:14 by giblee            #+#    #+#             */
/*   Updated: 2025/05/07 11:36:09 by giblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Find the first occurrence of a substring within a string, up to n char
char	*ft_strnstr(const char *str, const char *ss, size_t len)
{
	size_t	ss_len;

	if (*ss == '\0')
		return ((char *)str);
	ss_len = 0;
	while (ss[ss_len] != '\0')
		ss_len++;
	while (len >= ss_len && *str != '\0')
	{
		if (ft_strncmp(str, ss, ss_len) == 0)
			return ((char *)str);
		str++;
		len--;
	}
	return (NULL);
}
