#include "libft.h"

// Allocate memory for an array of elements, and initialize the memory to zero.
void *ft_calloc(size_t nmemb, size_t size) 
{
    // Allocate memory (num * size)
    void *ptr;
    
    ptr = malloc(nmemb * size);
    if (!ptr)
        return (NULL);
    ft_bzero(ptr, nmemb * size)
    return (ptr);
}
