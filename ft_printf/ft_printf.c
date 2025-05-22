/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giblee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 13:44:16 by giblee            #+#    #+#             */
/*   Updated: 2025/05/21 13:44:19 by giblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(const char *format, va_list args)
{
	if (*format == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (*format == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (*format == 'p')
		return (write(1, "0x", 2) + ft_putptr((unsigned long)va_arg(args, void *)));
	else if (*format == 'd' || *format == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (*format == 'u')
		return (ft_putnbr_unsigned(va_arg(args, unsigned int)));
	else if (*format == 'x')
		return (ft_puthex(va_arg(args, unsigned int), 0));
	else if (*format == 'X')
		return (ft_puthex(va_arg(args, unsigned int), 1));
	else if (*format == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
			count += ft_format(&format[++i], args);
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}

