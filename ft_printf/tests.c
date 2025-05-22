#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int main(void)
{
	int		ret1, ret2;
	char	c = 'A';
	char	*str = "Hello, world!";
	char	*null_str = NULL;
	int		n = 42;
	int		neg = -12345;
	unsigned int u = 4294967295U;
	void	*ptr = &n;

	// Character
	ret1 = printf("1. printf:    [%c]\n", c);
	ret2 = ft_printf("1. ft_printf: [%c]\n", c);
	printf("Return values: printf=%d, ft_printf=%d\n\n", ret1, ret2);

	// String
	ret1 = printf("2. printf:    [%s]\n", str);
	ret2 = ft_printf("2. ft_printf: [%s]\n", str);
	printf("Return values: printf=%d, ft_printf=%d\n\n", ret1, ret2);

	// NULL string
	ret1 = printf("3. printf:    [%s]\n", null_str);
	ret2 = ft_printf("3. ft_printf: [%s]\n", null_str);
	printf("Return values: printf=%d, ft_printf=%d\n\n", ret1, ret2);

	// Pointer
	ret1 = printf("4. printf:    [%p]\n", ptr);
	ret2 = ft_printf("4. ft_printf: [%p]\n", ptr);
	printf("Return values: printf=%d, ft_printf=%d\n\n", ret1, ret2);

	// Decimal and Integer
	ret1 = printf("5. printf:    [%d] [%i] [%d]\n", n, neg, 0);
	ret2 = ft_printf("5. ft_printf: [%d] [%i] [%d]\n", n, neg, 0);
	printf("Return values: printf=%d, ft_printf=%d\n\n", ret1, ret2);

	// INT_MIN and INT_MAX
	ret1 = printf("6. printf:    [INT_MIN: %d] [INT_MAX: %d]\n", INT_MIN, INT_MAX);
	ret2 = ft_printf("6. ft_printf: [INT_MIN: %d] [INT_MAX: %d]\n", INT_MIN, INT_MAX);
	printf("Return values: printf=%d, ft_printf=%d\n\n", ret1, ret2);

	// Unsigned
	ret1 = printf("7. printf:    [%u]\n", u);
	ret2 = ft_printf("7. ft_printf: [%u]\n", u);
	printf("Return values: printf=%d, ft_printf=%d\n\n", ret1, ret2);

	// Hexadecimal lowercase
	ret1 = printf("8. printf:    [%x]\n", n);
	ret2 = ft_printf("8. ft_printf: [%x]\n", n);
	printf("Return values: printf=%d, ft_printf=%d\n\n", ret1, ret2);

	// Hexadecimal uppercase
	ret1 = printf("9. printf:    [%X]\n", n);
	ret2 = ft_printf("9. ft_printf: [%X]\n", n);
	printf("Return values: printf=%d, ft_printf=%d\n\n", ret1, ret2);

	// Percent sign
	ret1 = printf("10. printf:    [%%]\n");
	ret2 = ft_printf("10. ft_printf: [%%]\n");
	printf("Return values: printf=%d, ft_printf=%d\n\n", ret1, ret2);

	return 0;
}