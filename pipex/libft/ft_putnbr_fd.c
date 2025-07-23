/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giblee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:31:29 by giblee            #+#    #+#             */
/*   Updated: 2025/05/07 12:33:53 by giblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include "ft_putchar_fd.c"

// Outputs the integer ’n’ to the specified file descriptor.
void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	ft_putchar_fd((n % 10) + '0', fd);
}

/*
void    main(void)
{
    // Test 1: Positive number
    ft_putnbr_fd(12345, 1);  // Output: 12345
    write(1, "\n", 1);

    // Test 2: Negative number
    ft_putnbr_fd(-67890, 1);  // Output: -67890
    write(1, "\n", 1);

    // Test 3: Zero
    ft_putnbr_fd(0, 1);      // Output: 0
    write(1, "\n", 1);

    // Test 4: INT_MIN
    ft_putnbr_fd(-2147483648, 1); // Output: -2147483648
    write(1, "\n", 1);
}
*/