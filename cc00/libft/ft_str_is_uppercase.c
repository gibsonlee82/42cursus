/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giblee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:59:41 by giblee            #+#    #+#             */
/*   Updated: 2025/02/19 10:59:58 by giblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
int	ft_str_is_uppercase(char *str)
{
	while (*str != '\0')
	{
		if (!(*str >= 'A' && *str <= 'Z'))
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
	char *a = "DFSDF";
	char *b = "asfd asfd";
	char *c = "asfDDFasdf";
	char *d = "";
	printf("%s: %i\n", a, ft_str_is_uppercase(a));
	printf("%s: %i\n", b, ft_str_is_uppercase(b));
	printf("%s: %i\n", c, ft_str_is_uppercase(c));
	printf("%s: %i\n", d, ft_str_is_uppercase(d));
}
*/
