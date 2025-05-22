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

int	ft_puthex(unsigned int n, int uppercase)
{
	char	*hex;
	int		count;

	hex = (uppercase ? "0123456789ABCDEF" : "0123456789abcdef");
	count = 0;
	if (n >= 16)
		count += ft_puthex(n / 16, uppercase);
	count += ft_putchar(hex[n % 16]);
	return (count);
}

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
