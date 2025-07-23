/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giblee <abc@abc.com>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:48:33 by giblee            #+#    #+#             */
/*   Updated: 2025/05/07 12:05:50 by giblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// copy n char from string src
char	*ft_strdupword(const char *src, unsigned int n)
{
	unsigned int	i;
	char			*dest;

	dest = ft_calloc(sizeof(char), (n + 1));
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

// count number of words in string s
int	ft_count_words(const char *s, char delimiter)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != delimiter && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == delimiter)
			in_word = 0;
		s++;
	}
	return (count);
}

// char	**ft_split_redirect(char **result, const char *str, char c)
// {
// 	const char	*start;
// 	int			len;
// 	int			num_string;

// 	start = str;
// 	num_string = 0;
// 	len = 0;
// 	while (*str)
// 	{
// 		if (*str == c)
// 		{
// 			if (len > 0)
// 				result[num_string++] = ft_strdupword(start, len);
// 			len = 0;
// 			start = str + 1;
// 		}
// 		else
// 			len++;
// 		str++;
// 	}
// 	if (len > 0)
// 		result[num_string++] = ft_strdupword(start, len);
// 	result[num_string] = NULL;
// 	return (result);
// }

// // Allocates memory (using malloc(3)) and returns an array of strings, 
// // obtained by splitting 's' using the character 'c' as a delimiter.
// char	**ft_split(char const *s, char c)
// {
// 	char	**result;

// 	// if (!s)
// 	// 	return (NULL);
// 	// if (c == '\0')
// 	// {
// 	// 	result = malloc(sizeof(char *) * 2);
// 	// 	if (!result)
// 	// 		return (NULL);
// 	// 	result[0] = (char *) ft_strdup(s);
// 	// 	result[1] = (NULL);
// 	// 	return (result);
// 	// }
// 	result = ft_calloc(sizeof(char *), ft_count_words(s, c) + 1);
// 	if (result == NULL)
// 		return (NULL);
// 	return (ft_split_redirect(result, s, c));
// }

char	**ft_free(char **strs, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

// Get the word from the str, until it meets the char c
// Keep track of the index i, of the string str
char	*get_word(char const *str, char c, int *i)
{
	int	start;
	int	len;

	start = *i;
	len = 0;
	while (str[*i])
	{
		if (str[*i] == c)
			break ;
		(*i)++;
		len++;
	}
	return (ft_strdupword(&str[start], len));
}

// Allocates memory (using malloc(3)) and returns an array of strings, 
// obtained by splitting 's' using the character 'c' as a delimiter.
char	**ft_split(char const *s, char c)
{
	char	**result;
	int		i;
	int		j;

	result = ft_calloc(sizeof(char *), ft_count_words(s, c) + 1);
	if (!s || !result)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] && j < ft_count_words(s, c))
	{
		if (s[i] == c)
			i++;
		else
		{
			result[j] = get_word(s, c, &i);
			if (!result)
				return (ft_free(result, j));
			j++;
		}
	}
	result[j] = NULL;
	return (result);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char		**result;
// 	int			num_words;
// 	int			i;
// 	// const char 	*str = "hello, how are you? I am fine.....";
// 	// char		delimiter = '.';
// 	const char 	*str = "\0aa\0bbb";
// 	char		delimiter = '\0';

// 	printf("String: %s\n", str);
// 	num_words = 0;
// 	result = ft_split(str, delimiter);
// 	num_words = ft_count_words(str, delimiter);
// 	printf("number of words = %d\n", num_words);
// 	i = 0;
// 	while (result[i] != NULL)
// 	{
// 		printf("token #%d: %s\n", i+1, result[i]);
// 		i++;
// 	}
// 	return (0);
// }
