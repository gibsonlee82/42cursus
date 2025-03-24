/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giblee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:00:46 by giblee            #+#    #+#             */
/*   Updated: 2025/02/19 11:01:18 by giblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
char	*ft_toupper(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] = str[i] - 'a' + 'A';
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

	printf("%s: %s", a, ft_toupper(a));
	printf("%s: %s", b, ft_toupper(b));
	printf("%s: %s", c, ft_toupper(c));
}
*/
