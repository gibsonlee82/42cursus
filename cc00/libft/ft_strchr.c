#include "libft.h"

// Return a pointer to the first occurrence of the character c in the string s
char    *my_strchr(const char *s, int c) 
{
    while (*s) 
    {
        if (*s == (char)c) 
            return (char *)s;
        s++;
    }
    if ((char)c == *s)
        return (char *)s;
    return (NULL);
}
