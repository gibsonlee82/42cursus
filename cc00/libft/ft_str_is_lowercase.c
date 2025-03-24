/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giblee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:58:54 by giblee            #+#    #+#             */
/*   Updated: 2025/02/19 10:59:14 by giblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
int	ft_str_is_lowercase(char *str)
{
	while (*str != '\0')
	{
		if (!(*str >= 'a' && *str <= 'z'))
		{
			return (0);
		}
		str++;
	}
	return (1);
}

/*
void	main(void)
{
	char *a = "asdfasf";
	char *b = "asfd asfd";
	char *c = "asfDDFasdf";
	char *d = "";
	printf("%s: %i\n", a, ft_str_is_lowercase(a));
	printf("%s: %i\n", b, ft_str_is_lowercase(b));
	printf("%s: %i\n", c, ft_str_is_lowercase(c));
	printf("%s: %i\n", d, ft_str_is_lowercase(d));
}
*/
