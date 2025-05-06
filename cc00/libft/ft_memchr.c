#include "libft.h"

// Scan the initial n bytes of the memory area pointed by s for the first instance of c.
// Return: pointer to the matching byte or NULL if the char does not occur in the memory area.
void *ft_memchr(const void *s, int c, size_t n)
{
    unsigned char *ptr;
    unsigned char uc;
    
    ptr = s;
    uc = (unsigned char)c;
    while (n--)
    {
        if (*ptr == uc)
            return (void *)ptr;
        ptr++;
    }
    return (NULL);
}