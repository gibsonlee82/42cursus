/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giblee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:56:03 by giblee            #+#    #+#             */
/*   Updated: 2025/02/24 16:57:52 by giblee           ###   ########.fr       */
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

/*
#include <stdio.h>
#include <string.h>
void	main(void)
{
	char	*s1 = "world";
	char	*s2 = "wor4";
	printf("ft_strncmp: %i\n", ft_strncmp(s1, s2, 5));
	printf("strncmp: %i\n", strncmp(s1, s2, 5));
	printf("ft_strncmp: %i\n", ft_strncmp(s1, s2, 4));
	printf("strncmp: %i\n", strncmp(s1, s2, 4));
	printf("ft_strncmp: %i\n", ft_strncmp(s1, s2, 3));
	printf("strncmp: %i\n", strncmp(s1, s2, 3));
	printf("ft_strncmp: %i\n", ft_strncmp(s1, s2, 0));
	printf("strncmp: %i\n", strncmp(s1, s2, 0));
}
*/
