#include "libft.h"

// Allocates memory (using malloc(3)) and returns a substring from the string 's'.
// The substring starts at index 'start' and has a maximum length of 'len'.
char        *ft_substr(char const *s, unsigned int start, size_t len)
{
    size_t  s_len;
    char    *substr;
    size_t  i;

    s_len = ft_strlen(s);
    if (start >= s_len)
        return (ft_strdup(""));
    if (len > s_len - start)
        len = s_len - start;
    substr = (char *)malloc(sizeof(char) * len + 1);
    if (!substr)
        return (NULL);
    i = 0;
    while (i < len && s[start + i])
    {
        substr[i] = s[start + i];
        i++;
    }
    substr[i] = '\0';
    return (substr);
}