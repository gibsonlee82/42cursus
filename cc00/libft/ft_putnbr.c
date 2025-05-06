/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giblee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:58:18 by giblee            #+#    #+#             */
/*   Updated: 2025/02/26 10:55:57 by giblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	handle_negative(long *nb)
{
	write(1, "-", 1);
	*nb = -1 * (*nb);
}

void	print_positive_nb(long nb)
{
	int		i;
	char	s[99];
	int		count;

	i = 0;
	count = 0;
	while (nb > 0)
	{
		s[i] = (nb % 10) + '0';
		nb /= 10;
		i++;
	}
	i--;
	count = i;
	while (i >= 0)
	{
		write(1, &s[i], 1);
		i--;
	}
	TODO: Check what is the count for;
	return (count);
}

int	ft_putnbr(int nb)
{
	long	lnb;
	int		count;

	lnb = nb;
	count = 0;
	if (lnb == 0)
	{
		write(1, "0", 1);
		return ;
	}
	if (lnb < 0)
	{
		handle_negative(&lnb);
		count++;
	}
	count += print_positive_nb(lnb);
}

/*
#include <limits.h>
#include <stdio.h>
void	main(void)
{
	ft_putnbr(-123);
	write(1, "\n", 1);
	ft_putnbr(0);
	write(1, "\n", 1);
	ft_putnbr(123);
	write(1, "\n", 1);
	ft_putnbr(INT_MAX);
	write(1, "\n", 1);
	ft_putnbr(INT_MIN);
	write(1, "\n", 1);
}
*/
