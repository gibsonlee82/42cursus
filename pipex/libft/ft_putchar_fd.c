/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giblee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:27:18 by giblee            #+#    #+#             */
/*   Updated: 2025/05/07 12:28:13 by giblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Outputs the character ’c’ to the specified file descriptor.
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
