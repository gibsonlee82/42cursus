/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giblee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:07:01 by giblee            #+#    #+#             */
/*   Updated: 2025/05/07 12:13:33 by giblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdlib.h>

static int	ft_numlen(int n)
{
	int	len;

	if (n <= 0)
		len = 1;
	else
		len = 0;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

// Allocates memory (using malloc(3)) and returns a string representing 
// the integer received as an argument. Negative numbers must be handled.
char	*ft_itoa(int n)
{
	int		len;
	char	*str;
	long	num;

	len = ft_numlen(n);
	str = (char *)malloc(len + 1);
	num = (long) n;
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	if (num == 0)
		str[0] = '0';
	while (num > 0)
	{
		str[--len] = '0' + (num % 10);
		num /= 10;
	}
	return (str);
}

/*
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>  // for INT_MAX and INT_MIN

void main(void)
{
    char *s;

    // Test 1: Zero
    s = ft_itoa(0);
    printf("Test 1: %d -> '%s'\n", 0, s);
    free(s);

    // Test 2: Positive number
    s = ft_itoa(12345);
    printf("Test 2: %d -> '%s'\n", 12345, s);
    free(s);

    // Test 3: Negative number
    s = ft_itoa(-67890);
    printf("Test 3: %d -> '%s'\n", -67890, s);
    free(s);

    // Test 4: INT_MAX
    s = ft_itoa(INT_MAX);
    printf("Test 4: %d -> '%s'\n", INT_MAX, s);
    free(s);

    // Test 5: INT_MIN
    s = ft_itoa(INT_MIN);
    printf("Test 5: %d -> '%s'\n", INT_MIN, s);
    free(s);
}
*/
