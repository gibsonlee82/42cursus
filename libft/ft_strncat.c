/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giblee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 11:57:07 by giblee            #+#    #+#             */
/*   Updated: 2025/02/24 17:27:15 by giblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char			*str;
	unsigned int	i;

	str = dest;
	while (*dest)
		dest++;
	i = 0;
	while (*src && i < nb)
	{
		*dest = *src;
		dest++;
		src++;
		i++;
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
	char	s1[] = "Hello ";
	char	s2[] = "World\n";
	char	s3[] = "Hello ";
	char	s4[] = "World\n";

	printf("ft_strncpy: %s\n", ft_strncat(s1, s2, (unsigned int) 3));
	printf("strncpy: %s\n", strncat(s3, s4, (unsigned int) 3));
	printf("ft_strncpy: %s\n", s1);
	printf("strncpy: %s\n", s3);
}
*/
