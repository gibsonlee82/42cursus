/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giblee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:37:26 by giblee            #+#    #+#             */
/*   Updated: 2025/05/07 11:00:56 by giblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Convert a string (ASCII representation of an integer) into an int
int	ft_atoi(const char *s)
{
	int	num;
	int	sign;
	int	i;

	num = 0;
	i = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n' \
|| s[i] == '\v' || s[i] == '\f' || s[i] == '\r')
		i++;
	sign = 1;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign *= -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		num = (num * 10) + (s[i] - '0');
		i++;
	}
	return (num * sign);
}

/*
#include <stdio.h>
#include <stdlib.h>

void	main(void)
{
	char	s1[] = "   ---+--+1234ab567";
	char	s2[] = "  -++-123000dsdf";
	char	s3[] = "-12300  ";
	char	s4[] = "12300";
	printf("ft_atoi(%s): %d\n",s1,ft_atoi(s1));  
	printf("atoi(%s): %d\n",s1,atoi(s1));  
	printf("ft_atoi(%s): %d\n",s2,ft_atoi(s2));  
	printf("atoi(%s): %d\n",s2,atoi(s2));  
	printf("ft_atoi(%s): %d\n",s2,ft_atoi(s3));  
	printf("atoi(%s): %d\n",s2,atoi(s3));  
	printf("ft_atoi(%s): %d\n",s2,ft_atoi(s4));  
	printf("atoi(%s): %d\n",s2,atoi(s4));  
}
*/
