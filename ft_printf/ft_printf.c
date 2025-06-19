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

// Purpose: Handles each individual format specifier found in ft_printf. 
// Selects the appropriate helper function based on the specifier.
// Parameters:
//   format: pointer to the format specifier character (e.g., 'd', 's').
//   args: the list of variable arguments.
// Returns: Number of characters printed for the given specifier.
static int	ft_format(const char *format, va_list args)
{
	void	*ptr;

	if (*format == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (*format == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (*format == 'p')
	{
		ptr = va_arg(args, void *);
		if (!ptr)
			return (write(1, "(nil)", 5));
		return (write(1, "0x", 2) + ft_putptr((unsigned long)ptr));
	}
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

// Purpose: Custom implementation of printf. It parses the format string 
//   & prints formatted data based on format specifiers (eg. %d, %s, etc)
// Parameters:
//   format: a C-string containing text and format specifiers
// ...: variable number of arg that correspond to the format specifiers
// Returns: Total number of characters printed.
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
		{
			i++;
			count += ft_format(&format[i], args);
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
