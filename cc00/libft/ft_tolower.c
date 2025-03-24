/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giblee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:01:43 by giblee            #+#    #+#             */
/*   Updated: 2025/02/19 11:01:56 by giblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
char	*ft_tolower(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = str[i] - 'A' + 'a';
		}
		i++;
	}
	return (str);
}

/*
void	main(void)
{
	char	a[] = "How are you";
	char	b[] = "Hwer8 sadf09";
	char	c[] = "87778  97\n";

	printf("%s: %s", a, ft_tolower(a));
	printf("%s: %s", b, ft_tolower(b));
	printf("%s: %s", c, ft_tolower(c));
}
*/
