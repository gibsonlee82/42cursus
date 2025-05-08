/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giblee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:56:03 by giblee            #+#    #+#             */
/*   Updated: 2025/05/07 11:25:25 by giblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

// n: number of char to compare
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[1] && (s1[i] == s2[i]) && (i < n - 1))
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/*
#include <stdio.h>
#include <string.h>
void	main(void)
{
	char	*s1 = "wor";
	char	*s2 = "worl4";
	printf("ft_strncmp: %i\n", ft_strncmp(s1, s2, 6));
	printf("strncmp: %i\n", strncmp(s1, s2, 6));
	printf("ft_strncmp: %i\n", ft_strncmp(s1, s2, 4));
	printf("strncmp: %i\n", strncmp(s1, s2, 4));
	printf("ft_strncmp: %i\n", ft_strncmp(s1, s2, 3));
	printf("strncmp: %i\n", strncmp(s1, s2, 3));
	printf("ft_strncmp: %i\n", ft_strncmp(s1, s2, 0));
	printf("strncmp: %i\n", strncmp(s1, s2, 0));
}
*/
