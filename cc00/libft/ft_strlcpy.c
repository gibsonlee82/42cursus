/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giblee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:08:21 by giblee            #+#    #+#             */
/*   Updated: 2025/02/20 11:26:56 by giblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	while (src[i] != '\0')
	{
		i++;
	}
	return (i);
}

/*
#include <stdio.h>
#include <string.h>
void	main(void)
{
	char	*s;
	char	d[10];
	int	n;

	s = "hello world\n";
	printf("%s\n", s);
	printf("ft_strlcpy: %i\n", ft_strlcpy(d, s, 9));
	printf("dest: %s\n", d);
	//printf("strlcpy: %i\n", strlcpy(d, s, 9);
}
*/
