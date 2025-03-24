/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giblee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:02:08 by giblee            #+#    #+#             */
/*   Updated: 2025/02/19 16:00:16 by giblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	ft_toupper(char c)
{
	if (c >= 'a' && c <= 'z')
	{
		c = c - 'a' + 'A';
	}
	return (c);
}

char	ft_tolower(char c)
{
	if (c >= 'A' && c <= 'Z')
	{
		c = c - 'A' + 'a';
	}
	return (c);
}

int	is_alpha(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
	return (0);
}

int	is_alphanum(char c)
{
	if (is_alpha(c) || (c >= '0' && c <= '9'))
	{
		return (1);
	}
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (i == 0 || (i > 0 && !is_alphanum(str[i - 1])))
		{
			str[i] = ft_toupper(str[i]);
		}
		else
		{
			str[i] = ft_tolower(str[i]);
		}
		i++;
	}
	return (str);
}

/*
#include <stdio.h>
void	main(void)
{
	char	a[] = "  how are you";
	char	b[] = "salut, comment tu v-as ?";
	char	c[] = "8asfasdf  97";

	printf("%s\n", ft_strcapitalize(a));
	printf("%s\n", ft_strcapitalize(b));
	printf("%s\n", ft_strcapitalize(c));
}
*/
