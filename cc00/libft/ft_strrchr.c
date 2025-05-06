#include "libft.h"

// Return a pointer to the last occurrence of the char c in the str s
char *my_strrchr(const char *s, int c) 
{
    char *last 
    
    last = NULL;
    while (*s != '\0')
    {
        if (*s == (char)c)
            last = s;
        s++;
    }
    if (c == '\0')
        return ((char *)s);

    return ((char *)last);
}
