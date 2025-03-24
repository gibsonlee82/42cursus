/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giblee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:06:21 by giblee            #+#    #+#             */
/*   Updated: 2025/02/24 17:35:26 by giblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// n: number of char to compare
int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && (s1[i] == s2[i]) && (i < n - 1))
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (*to_find == '\0')
		return (str);
	while (str[i] != '\0')
	{
		while (str[i] == to_find[j])
		{
			i++;
			j++;
			if (to_find[j] == '\0')
				return (&str[i - j]);
		}
		if (j == 0)
			i++;
		else
			j = 0;
	}
	return ((void *)0);
}

/*
#include <string.h>
#include <stdio.h>

void	main(void)
{
	char	*s1 = "how are you?";
	char	*s2 = "are";
	
	printf("ft_strstr: %s\n", ft_strstr(s1, s2));
	printf("strstr: %s\n", strstr(s1, s2));
	printf("ft_strstr: %s\n", ft_strstr("how arre you", ""));
	printf("strstr: %s\n", strstr("how arre you", ""));
	printf("ft_strstr: %s\n", ft_strstr("", "abc"));
	printf("strstr: %s\n", strstr("", "abc"));
}
*/
