#include "libft.h"

// Compare the first n bytes of memory areas s1 and s2
int ft_memcmp(const void *s1, const void *s2, size_t n) 
{
    unsigned char *ptr1;
    unsigned char *ptr2;

    ptr1 = s1;
    ptr2 = s2;
    while (n--) 
    {
        if (*ptr1 != *ptr2)
            return (*ptr1 - *ptr2);
        ptr1++;
        ptr2++;
    }
    return (0);
}
