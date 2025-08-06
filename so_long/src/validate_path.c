#include "so_long.h"

static void		flood_fill(char **map, int x, int y);
static char		**copy_map(char **map, int height);
static int		has_reachable_items(char **map);

/*
** Checks if all collectibles and exit are reachable from player.
*/
int	check_path(t_game *game)
{
	char	**map_copy;
	int		result;

	map_copy = copy_map(game->map, game->height);
	if (!map_copy)
		return (0);
	flood_fill(map_copy, game->player_x, game->player_y);
	result = has_reachable_items(map_copy);
	free_map(map_copy);
	return (result);
}

/*
 * Recursively marks all reachable tiles from (x, y) on the map.
 * Replaces walkable tiles (not walls '1' or already filled 'F') with 'F',
 * effectively checking all paths in 4 directions (DFS flood fill).
 */
static void	flood_fill(char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == 'F')
		return ;
	map[y][x] = 'F';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

/*
** Duplicates a 2D map array of strings.
**
** Allocates and returns a deep copy of the original map up to the given height.
** Each row is duplicated using ft_strdup. The returned array is NULL-terminated.
**
** Parameters:
** - map: The original 2D map array to copy.
** - height: The number of rows to copy.
**
** Returns:
** - A newly allocated copy of the map, or NULL if allocation fails.
*/
static char	**copy_map(char **map, int height)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (height + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (map[i])
	{
		copy[i] = ft_strdup(map[i]);
		if (!copy[i])
			return (NULL);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

/*
** has_reachable_items:
** Checks if all collectibles ('C') and the exit ('E') were reached
** by the flood fill. Iterates through the map and returns 0 if any
** 'C' or 'E' is still present.
**
** map: 2D char array of the map after flood fill.
**
** Returns:
**	- 1 if all items were reached (no 'C' or 'E' remains),
**  - 0 otherwise.
*/
static int	has_reachable_items(char **map)
{
	int	y = 0, x;

	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C' || map[y][x] == 'E')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}
