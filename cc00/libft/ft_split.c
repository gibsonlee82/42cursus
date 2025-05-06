/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giblee <abc@abc.com>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:48:33 by giblee            #+#    #+#             */
/*   Updated: 2025/03/06 11:51:06 by giblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

// copy n char of string
char	*ft_strdupword(const char *src, unsigned int n)
{
	unsigned int	i;
	char			*dest;

	dest = malloc(sizeof(char) + (n + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = (char) src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_split_redirect(char **result, const char *str, char c)
{
	const char	*c_str;
	int		len;
	int		num_string;

	num_string = 0;
	c_str = str;
	len = 0;
	while (*str != '\0')
	{
		if (*str == c)
		{
			if (len > 0)
				result[num_string++] = ft_strdupword(c_str, len);
			len = 0;
			c_str = str + 1;
		}
		else
			len++;
		str++;
	}
	if (len > 0)
		result[num_string] = ft_strdupword(c_str, len);
	result[num_string + 1] = NULL;
	return (result);
}

// Allocates memory (using malloc(3)) and returns an array of strings, 
// obtained by splitting 's' using the character 'c' as a delimiter.
char	**ft_split(char const *s, char c)
{
	char	**result;

	result = malloc(sizeof(char *) * 9999);
	if (result == NULL)
		return (NULL);
	result = ft_split_redirect(result, s, c);
	return (result);
}

/*
#include <stdio.h>
int	main(void)
{
	char	**result;
	int	num_words;
	int	i;

	num_words = 0;
	result = ft_split("hello, how are you? I am fine.", ' ');
	//num_words = count_words("hello, how are you? I am fine.", ",? ");
	//printf("number of words = %d\n", num_words);
	i = 0;
	while (result[i] != NULL)
	{
		printf("token #%d: %s\n", i, result[i]);
		i++;
	}
	return (0);
}
*/