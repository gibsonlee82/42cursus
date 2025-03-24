/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giblee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:56:26 by giblee            #+#    #+#             */
/*   Updated: 2025/02/20 11:23:51 by giblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

/*
#include <stdio.h>
#include <string.h>

void	main(void)
{
	char	s[] = "asdd";
	char	d[] = "this is a very long sentence";

	printf("ft_strncpy: %s\n", ft_strncpy(d, s, 50));
	printf("strncpy: %s\n", strncpy(d, s, 50));
}
*/
