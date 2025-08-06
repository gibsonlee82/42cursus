#include "so_long.h"

/*
 Loads the map from the .ber file into memory.
*/
int	load_map(t_game *game, char *filename)
{
	int		fd;
	char	*line;
	int		i;

	game->height = count_rows(filename);
	if (game->height == 0)
		return (0);
	game->map = allocate_map(game->height);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	i = 0;
	while (i < game->height)
	{
		line = get_next_line(fd);
		game->map[i++] = ft_strtrim(line, "\n");
		free(line);
	}
	close(fd);
	game->width = ft_strlen(game->map[0]);
	return (1);
}

int	count_rows(char *filename)
{
	int		fd;
	int		count;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	count = 0;
	while ((line = get_next_line(fd)))
	{
		free(line);
		count++;
	}
	close(fd);
	return (count);
}

char	**allocate_map(int height)
{
	char	**map;

	map = malloc(sizeof(char *) * (height + 1));
	if (!map)
		return (NULL);
	map[height] = NULL;
	return (map);
}

void	free_map(char **map)
{
	int	i;

	if (!map)
		return;
	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}
