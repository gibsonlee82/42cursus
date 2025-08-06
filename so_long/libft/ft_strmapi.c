/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giblee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:14:40 by giblee            #+#    #+#             */
/*   Updated: 2025/05/07 12:18:40 by giblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Applies the function f to each char of the string s, 
// passing its index as the first argument and the char itself as the second. 
// A new string is created (using malloc(3)) to store the results from the 
// successive applications of f.
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	j;
	char	*result;

	if (!s || !f)
		return (NULL);
	i = 0;
	while (s[i])
		i++;
	result = (char *)malloc(i + 1);
	if (!result)
		return (NULL);
	j = 0;
	while (j < i)
	{
		result[j] = f(j, s[j]);
		j++;
	}
	result[j] = '\0';
	return (result);
}

/*
#include <stdio.h>
#include <stdlib.h>

// Test function 1: shift each character by index
char add_index(unsigned int i, char c) {
    return (c + i);
}

// Test function 2: uppercase
char to_upper(unsigned int i, char c) {
    if (c >= 'a' && c <= 'z')
        return (c - 32);
    return (c);
}

// Test function 3: alternate case
char alt_case(unsigned int i, char c) {
    if (c >= 'a' && c <= 'z') {
        if (i % 2 == 0)
            return (c - 32);  // uppercase
    }
    return (c);
}

void main(void)
{
    char *result;

    // Test 1: Apply add_index
    result = ft_strmapi("abcd", add_index);  // expected "aceg"
    printf("Test 1 (add_index): %s\n", result);
    free(result);

    // Test 2: Apply to_upper
    result = ft_strmapi("42 school", to_upper);  // expected "42 SCHOOL"
    printf("Test 2 (to_upper): %s\n", result);
    free(result);

    // Test 3: Apply alt_case
    result = ft_strmapi("hello world", alt_case);  // expected "HeLlO WoRlD"
    printf("Test 3 (alt_case): %s\n", result);
    free(result);

    // Test 4: Empty string
    result = ft_strmapi("", to_upper);  // expected ""
    printf("Test 4 (empty string): '%s'\n", result);
    free(result);

    // Test 5: NULL input
    result = ft_strmapi(NULL, to_upper);  // expected NULL
    printf("Test 5 (NULL string): %s\n", result ? result : "NULL");
}
*/
