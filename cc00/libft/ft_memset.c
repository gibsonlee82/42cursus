#include "libft.h"
//#include <stddef.h>

// set a block of memory to specific value
void	*ft_memset(void *ptr, int value, size_t num)
{
	unsigned char *nptr;

	nptr = (unsigned char *) ptr;
	while (num > 0)
	{
		*nptr = (unsigned char) value;
		nptr++;
		num--;
	}
    return (ptr);
}