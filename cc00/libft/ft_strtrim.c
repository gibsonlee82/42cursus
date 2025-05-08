/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giblee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 11:54:04 by giblee            #+#    #+#             */
/*   Updated: 2025/05/07 12:02:11 by giblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdlib.h>
// #include "ft_strlen.c"
// #include "ft_strdup.c"
// #include "ft_substr.c"

int	ft_isset(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

// Allocates memory (using malloc(3)) and returns a copy of 's1' 
// with characters from 'set' removed from the beginning and the end
char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	start;
	size_t	end;

	if (!s1 || !set || s1[0] == '\0')
		return (ft_strdup(""));
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_isset(s1[start], set))
		start++;
	while (end > start && ft_isset(s1[end - 1], set))
		end--;
	if (end < start)
		return (ft_strdup(""));
	return (ft_substr(s1, start, end - start));
}

/*
#include <stdio.h>
void    main(void) {
    char *trimmed;

    // Test 1: Basic trim
    trimmed = ft_strtrim("   Hello, world!   ", " ");
    printf("Test 1: '%s'\n", trimmed);
    free(trimmed);

    // Test 2: Trim tabs and newlines
    trimmed = ft_strtrim("\n\t  Hello\n\t  ", " \n\t");
    printf("Test 2: '%s'\n", trimmed);
    free(trimmed);

    // Test 3: No trimming needed
    trimmed = ft_strtrim("Hello", " ");
    printf("Test 3: '%s'\n", trimmed);
    free(trimmed);

    // Test 4: Entire string is trimmed
    trimmed = ft_strtrim("     ", " ");
    printf("Test 4: '%s'\n", trimmed);
    free(trimmed);

    // Test 5: Empty string input
    trimmed = ft_strtrim("", " ");
    printf("Test 5: '%s'\n", trimmed);
    free(trimmed);

    // Test 6: Trim set is empty
    trimmed = ft_strtrim("   Hello  ", "");
    printf("Test 6: '%s'\n", trimmed);
    free(trimmed);

    // Test 7: String has internal trim characters
    trimmed = ft_strtrim("!!!Hello!!World!!!", "!");
    printf("Test 7: '%s'\n", trimmed);
    free(trimmed);
}
*/
