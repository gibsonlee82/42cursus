#include "libft.h"

// Applies the function ’f’ to each character of the string passed as argument, 
// passing its index as the first argument. Each character is passed by
// address to 'f' so it can be modified if necessary.
void    ft_striteri(char *s, void (*f)(unsigned int, char *))
{
    unsigned int i;

    if (!s || !f)
        return ;
    i = 0;
    while (s[i]) 
    {
        f(i, &s[i]);
        i++;
    }
}

/*
#include <stdio.h>

// Function 1: Convert to uppercase
void to_upper(unsigned int i, char *c) {
    if (*c >= 'a' && *c <= 'z')
        *c -= 32;
}

// Function 2: Add index to character (ASCII shift)
void add_index(unsigned int i, char *c) {
    *c = *c + i;
}

// Function 3: Alternate case
void alt_case(unsigned int i, char *c) {
    if (*c >= 'a' && *c <= 'z') {
        if (i % 2 == 0)
            *c -= 32; // to uppercase
    }
}

void    main(void)
{
    char test1[] = "hello world";
    char test2[] = "abcd";
    char test3[] = "lorem ipsum";
    char test4[] = "";

    // Test 1: to_upper
    ft_striteri(test1, to_upper);
    printf("Test 1 (to_upper): %s\n", test1);  // Expected: "HELLO WORLD"

    // Test 2: add_index
    ft_striteri(test2, add_index);
    printf("Test 2 (add_index): %s\n", test2);  // Expected: 'a'+0, 'b'+1, 'c'+2, 'd'+3 → "aceg"

    // Test 3: alt_case
    ft_striteri(test3, alt_case);
    printf("Test 3 (alt_case): %s\n", test3);  // Expected: "LoReM IpSuM"

    // Test 4: empty string
    ft_striteri(test4, to_upper);
    printf("Test 4 (empty): '%s'\n", test4);  // Expected: ""

    // Test 5: NULL input
    ft_striteri(NULL, to_upper);  // Should do nothing / not crash
    printf("Test 5 (NULL input): Passed if no crash\n");
}
*/