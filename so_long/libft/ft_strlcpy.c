/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giblee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:08:21 by giblee            #+#    #+#             */
/*   Updated: 2025/02/20 11:26:56 by giblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Safer alternative to strcpy and strncpy for copying C strings.
// Designed to prevent buffer overflows by always null-terminating the result.
// Return: total length of the source string (strlen(src)).
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (src[i])
		i++;
	if (size == 0)
		return (i);
	j = 0;
	while (src[j] != '\0' && j < size - 1)
	{
		dst[j] = src[j];
		j++;
	}
	dst[j] = '\0';
	return (i);
}

/*
#include <stdio.h>
#include <string.h>
void	main(void)
{
	char	*s;
	char	d[10];
	int	n;

	s = "hello world\n";
	printf("%s\n", s);
	printf("ft_strlcpy: %i\n", ft_strlcpy(d, s, 9));
	printf("dest: %s\n", d);
	//printf("strlcpy: %i\n", strlcpy(d, s, 9);
}
*/
