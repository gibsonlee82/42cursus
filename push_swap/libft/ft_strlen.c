/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giblee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:17:50 by giblee            #+#    #+#             */
/*   Updated: 2025/05/07 11:05:38 by giblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	size;

	size = 0;
	while (s[size] != '\0')
		size++;
	return (size);
}

/*
#include <stdio.h>
#include <string.h>
void	main(void)
{
	printf("strlen: %zu\n", strlen("how are you"));
	printf("ft_strlen: %zu\n", ft_strlen("how are you"));
}
*/
