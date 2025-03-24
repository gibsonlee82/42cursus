/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giblee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:37:26 by giblee            #+#    #+#             */
/*   Updated: 2025/02/26 11:06:52 by giblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *s)
{
	int	num;
	int	sign;

	num = 0;
	while (*s == ' ' || *s == '\t' || *s == '\n' \
		|| *s == '\v' || *s == '\f' || *s == '\r')
		s++;
	sign = 1;
	while (*s == '-' || *s == '+')
	{
		if (*s == '-')
		{
			sign *= -1;
		}
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		num = (num * 10) + (*s - '0');
		s++;
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
