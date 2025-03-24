/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giblee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:55:35 by giblee            #+#    #+#             */
/*   Updated: 2025/02/19 10:56:14 by giblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <unistd.h>
char	*ft_strcpy(char *dest, char *src)
{
	char	*dup;

	dup = dest;
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (dup);
}

/*
void	main(void)
{
	char*	s;
	char*	d;

	s = "hello";
	printf("Source: %s\n", s);
	d = ft_strcpy(d, s);
	printf("Dest: %s\n", d);
}
*/
