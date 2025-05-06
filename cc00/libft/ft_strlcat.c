/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giblee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:04:11 by giblee            #+#    #+#             */
/*   Updated: 2025/02/24 18:05:36 by giblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s);

// Appends src to the end of dest, making sure not to write more than size - 1 
// characters in total (including the original content of dest), 
// and always null-terminates the result if size > 0.
// Return: The total length of the string it tried to create:
//   strlen(dest_original) + strlen(src)
size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	d_len;
	size_t	s_len;

	d_len = ft_strlen(dest);
	s_len = ft_strlen(src);
	if (size <= d_len)
		return (size + s_len);
	i = 0;
	while ((i < size - d_len - 1) && src[i])
	{
		dest[d_len + i] = src[i];
		i++;
	}
	dest[d_len + i] = '\0';
	return (s_len + d_len);
}

/*
#include <bsd/string.h>
#include <string.h>
#include <stdio.h>

void	main(void)
{
	char	s1[] = "Destination string";
	char	s2[] = "This is a super long string";
	char	s3[] = "Destination string";
	char	s4[] = "This is a super long string";
	unsigned int	n = 31;
	unsigned int	i = 0;

	i = strlcat(s1, s2, n);
	printf("strlcat: %s (%d)\n", s1, i);
	//i = ft_strlcat(s3, s4, n);
	//printf("ft_strlcat: %s (%d)\n", s3, i);
}
*/
