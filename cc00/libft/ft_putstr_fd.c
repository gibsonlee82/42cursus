#include "libft.h"

// Outputs the string 's' to the specified file descriptor.
void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s)
        return ;
	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

/*
#include <fcntl.h> // open
#include <unistd.h> // close

void	main(void)
{
    // Test 1: Write to stdout
    ft_putstr_fd("Hello, world!\n", 1);

    // Test 2: Write to stderr
    ft_putstr_fd("Error message!\n", 2);

    // Test 3: Write to a file
    int fd;

	fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd >= 0)
	{
        ft_putstr_fd("Written to file.\n", fd);
        close(fd);
    }
}
*/