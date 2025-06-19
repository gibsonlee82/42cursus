/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giblee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 13:44:04 by giblee            #+#    #+#             */
/*   Updated: 2025/05/21 13:44:08 by giblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Purpose: Writes a single character to standard output.
// Parameters: c — the character to print.
// Returns: Always returns 1 (one character printed).
int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

// Purpose: Writes a string to standard output.
// Parameters: s — the string to print.
// Returns: Number of characters printed. 
//   If s is NULL, prints (null) and returns 6.
int	ft_putstr(char *s)
{
	int	i;

	if (!s)
		return (write(1, "(null)", 6));
	i = 0;
	while (s[i])
		write(1, &s[i++], 1);
	return (i);
}

// Purpose: Prints a signed integer to standard output using recursion.
// Parameters: n — the integer to print.
// Returns: Number of characters printed.
int	ft_putnbr(int n)
{
	long	num;
	int		count;

	num = n;
	count = 0;
	if (num < 0)
	{
		count += write(1, "-", 1);
		num *= -1;
	}
	if (num >= 10)
		count += ft_putnbr(num / 10);
	count += ft_putchar((num % 10) + '0');
	return (count);
}

// Purpose: Prints an unsigned integer to standard output using recursion.
// Parameters: n — the unsigned integer to print.
// Returns: Number of characters printed.
int	ft_putnbr_unsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_putnbr_unsigned(n / 10);
	count += ft_putchar((n % 10) + '0');
	return (count);
}
