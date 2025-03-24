/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giblee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:43:38 by giblee            #+#    #+#             */
/*   Updated: 2025/02/19 11:54:38 by giblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/*
void	main(void)
{
	char	*s1 = "H";
	char	*s2 = "World";
	printf("ft_strcmp: %i\n", ft_strcmp(s1, s2));
	printf("strcmp: %i\n", strcmp(s1, s2));
}
*/
