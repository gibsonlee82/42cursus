#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t num);

// Erases the data in the n bytes of the memory 
// starting at the location pointed to by s, 
// by writing zeros (bytes containing '\0') to that area.
void		ft_bzero(void *s, size_t n)
{
    ft_memset(s, 0, n);
}