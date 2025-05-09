/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giblee <abc@abc.com>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:48:33 by giblee            #+#    #+#             */
/*   Updated: 2025/05/07 12:05:50 by giblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Allocate memory for an array of elements, and initialize the memory to zero.
void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}

// string length
size_t	ft_strlen(const char *s)
{
	size_t	size;

	size = 0;
	while (s && s[size])
		size++;
	return (size);
}

// Create a new string (s1 + s2), up to s2_len char
char	*ft_strjoin(char *s1, char *s2, int s2_len)
{
	char	*result;
	int		i;
	int		j;

	i = 0;
	j = 0;
	result = calloc(sizeof(char), ft_strlen(s1) + s2_len + 1);
	if (!result)
		return (NULL);
	while (i < (int)ft_strlen(s1))
	{
		result[i] = s1[i];
		i++;
	}
	while (j < s2_len)
	{
		result[i + j] = s2[j];
		j++;
	}
	result[i + j] = '\0';
	return (result);
}
