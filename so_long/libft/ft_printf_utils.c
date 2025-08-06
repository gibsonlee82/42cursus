/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giblee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 13:44:04 by giblee            #+#    #+#             */
/*   Updated: 2025/05/21 13:44:08 by giblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Purpose: Prints an unsigned int as a hex string (lowercase or uppercase).
// Parameters:
//   n: the number to convert and print in hex.
//   uppercase: if 1, uses uppercase letters (A-F); otherwise, lowercase (a-f).
// Returns: Number of characters printed.
int	ft_puthex(unsigned int n, int uppercase)
{
	char	*hex;
	int		count;

	if (uppercase)
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	count = 0;
	if (n >= 16)
		count += ft_puthex(n / 16, uppercase);
	count += ft_putchar(hex[n % 16]);
	return (count);
}

// Purpose: Prints a memory address (pointer) as a hexadecimal number, 
//   excluding the "0x" prefix (which is printed in ft_format).
// Parameters: n — the pointer value cast to unsigned long.
// Returns: Number of characters printed.
int	ft_putptr(unsigned long n)
{
	char	*hex;
	int		count;

	hex = "0123456789abcdef";
	count = 0;
	if (n >= 16)
		count += ft_putptr(n / 16);
	count += ft_putchar(hex[n % 16]);
	return (count);
}
