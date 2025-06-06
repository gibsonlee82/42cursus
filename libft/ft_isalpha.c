/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giblee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 10:48:04 by giblee            #+#    #+#             */
/*   Updated: 2025/05/07 11:01:25 by giblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

/*
#include <stdio.h>
void	main(void)
{
	char a = 'a';
	char b = '1';
	char c = 'c';
	printf("%c: %i\n", a, ft_isalpha(a));
	printf("%c: %i\n", b, ft_isalpha(b));
	printf("%c: %i\n", c, ft_isalpha(c));
}
*/
