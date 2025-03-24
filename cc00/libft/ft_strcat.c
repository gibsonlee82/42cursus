/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giblee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 12:00:59 by giblee            #+#    #+#             */
/*   Updated: 2025/02/24 17:21:42 by giblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	char	*str;

	str = dest;
	while (*dest)
		dest++;
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	dest = str;
	return (dest);
}

/*
#include <stdio.h>
#include <string.h>
void	main(void)
{
	char	s1[100] = "Hello ";
	char	s2[] = "World";
	char	s3[100] = "Hello ";
	char	s4[] = "World";

	printf("ft_strcat: %s\n", ft_strcat(s1, s2));
	printf("strcat: %s\n", strcat(s3, s4));
	printf("ft_strcat: %s\n", s1);
	printf("strcat: %s\n", s3);
}
*/
