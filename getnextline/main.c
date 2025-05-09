#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int	fd1 = open("test1.txt", O_RDONLY);
	int	fd2 = open("test2.txt", O_RDONLY);

	if (fd1 < 0 || fd2 < 0)
	{
		perror("Failed to open test file");
		return (1);
	}

	printf("Reading test1.txt:\n");
	char	*line1;
	while ((line1 = get_next_line(fd1)) != NULL)
	{
		printf("-> %s", line1);
		free(line1);
	}
	close(fd1);

	printf("\nReading test2.txt:\n");
	char	*line2;
	while ((line2 = get_next_line(fd2)) != NULL)
	{
		printf("-> %s", line2);
		free(line2);
	}
	close(fd2);

	return (0);
}
