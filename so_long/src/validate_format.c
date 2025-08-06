#include "so_long.h"

int				validate_map(t_game *game);
static int		is_rectangular(t_game *game);
static int		is_enclosed_by_walls(t_game *game);
static int		count_elements(t_game *game);

/*
** Validates the map based on shape, elements, walls, and path.
*/
int	validate_map(t_game *game)
{
	if (!is_rectangular(game))
		return (write(2, "Error\nMap is not rectangular.\n", 30), 0);
	if (!is_enclosed_by_walls(game))
		return (write(2, "Error\nMap is not enclosed by walls.\n", 37), 0);
	int res = count_elements(game);
	if (res == -1)
		return (write(2, "Error\nInvalid character in map.\n", 32), 0);
	else if (res == 0)
		return (write(2, "Error\nMap must have 1 P, 1 E, and at least 1 C.\n", 48), 0);
	if (!check_path(game))
		return (write(2, "Error\nUnreachable collectible or exit.\n", 39), 0);
	return (1);
}

/*
 * Checks if the map is rectangular by verifying all rows have the same length.
 * Sets the map width if valid, returns 1 if rectangular, 0 otherwise.
 */
static int	is_rectangular(t_game *game)
{
	int	i;
	int	width;

	width = ft_strlen(game->map[0]);
	i = 1;
	while (game->map[i])
	{
		if ((int)ft_strlen(game->map[i]) != width)
			return (0);
		i++;
	}
	game->width = width;
	return (1);
}

/*
 * Checks if the map is enclosed by walls ('1') on all borders.
 * Returns 1 if all edges are walls, 0 otherwise.
 */
static int	is_enclosed_by_walls(t_game *game)
{
	int	x, y;

	// Top and bottom rows
	for (x = 0; x < game->width; x++)
	{
		if (game->map[0][x] != '1' || game->map[game->height - 1][x] != '1')
			return (0);
	}
	// Left and right walls
	for (y = 0; y < game->height; y++)
	{
		if (game->map[y][0] != '1' || game->map[y][game->width - 1] != '1')
			return (0);
	}
	return (1);
}

/*

 * Counts occurrences of player (P), exit (E), and collectibles (C) in the map.
 * Sets player's starting position coordinates.
 * Returns:
 *   -1 if an invalid character is found,
 *    0 if counts of P, E, or C are incorrect,
 *    1 if counts are valid.
 */
static int	count_elements(t_game *game)
{
	int	x, y;
	int	player = 0, exit = 0, collect = 0;

	for (y = 0; y < game->height; y++)
	{
		for (x = 0; game->map[y][x]; x++)
		{
			if (game->map[y][x] == 'P')
			{
				player++;
				game->player_x = x;
				game->player_y = y;
			}
			else if (game->map[y][x] == 'E')
				exit++;
			else if (game->map[y][x] == 'C')
				collect++;
			else if (!ft_strchr("01PEC", game->map[y][x]))
				return (-1);
		}
	}
	game->collect_count = collect;
	if (player != 1 || exit != 1 || collect < 1)
		return (0);
	return (1);
}
