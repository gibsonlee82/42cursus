/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giblee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 11:36:47 by giblee            #+#    #+#             */
/*   Updated: 2025/05/14 10:48:49 by giblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// The calloc() function allocates memory for an array of  nmemb  elements
// of  size bytes each and returns a pointer to the allocated memory.  The
// memory is set to zero.  If nmemb or size is 0,  then  calloc()  returns
// either  NULL,  or a unique pointer value that can later be successfully
// passed to free().  If the multiplication of nmemb and size would result
// in  integer  overflow, then calloc() returns an error.  By contrast, an
// integer overflow would not be detected in the following  call  to  mal‐
// loc(),  with the result that an incorrectly sized block of memory would
// be allocated:
// 	malloc(nmemb * size);
void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	product;
	void	*ptr;

	product = nmemb * size;
	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (size && ((product / size) != nmemb))
	{
		return (NULL);
	}
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
