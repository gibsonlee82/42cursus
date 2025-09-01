/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giblee <abc@abc.com>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 10:00:33 by giblee            #+#    #+#             */
/*   Updated: 2025/08/29 11:13:10 by giblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

/**********************************************************************
 * check_shape_and_walls: Validates the map's rectangular shape and walls.
 * - g: Pointer to the game state structure containing the map.
 *
 * This function:
 * - Ensures every row of the map has the same width.
 * - Verifies that the left and right borders of each row are walls ('1').
 * - Verifies that the top and bottom rows are completely walls ('1').
 *
 * Assumes:
 * - g->map is non-NULL, properly loaded, and dimensions are set.
 * - g->map_width and g->map_height have been initialized in load_map().
 **********************************************************************/
static void	check_shape_and_walls(t_game *g)
{
	int		y;
	int		w;

	y = 0;
	w = g->map_width;
	while (y < g->map_height)
	{
		if ((int)ft_strlen(g->map[y]) != w)
			error_exit("map not rectangular\n");
		if (g->map[y][0] != '1' || g->map[y][w - 1] != '1')
			error_exit("map not closed (sides)\n");
		y++;
	}
	y = 0;
	while (y < w)
	{
		if (g->map[0][y] != '1' || g->map[g->map_height - 1][y] != '1')
			error_exit("map not closed (top/bottom)\n");
		y++;
	}
}

/**********************************************************************
 * count_and_check_chars: Validates map contents and counts entities.
 * - g: Pointer to the game state structure containing the map.
 *
 * This function:
 * - Iterates through every tile in the map.
 * - Ensures only valid characters ('0', '1', 'C', 'E', 'P') are used.
 * - Counts collectibles ('C') and exits ('E').
 * - Stores the player’s starting position ('P').
 * - Verifies that the map has exactly one exit, at least one collectible,
 *   and exactly one player position.
 *
 * Assumes:
 * - g->map is fully loaded and rectangular.
 * - g->map_width and g->map_height are valid.
 **********************************************************************/
static void	count_and_check_chars(t_game *g)
{
	int	x;
	int	y;
	char c;

	y = 0;
	while (y < g->map_height)
	{
		x = 0;
		while (x < g->map_width)
		{
			c = g->map[y][x];
			if (c != '0' && c != '1' && c != 'C' && c != 'E' && c != 'P')
				error_exit("invalid char\n");
			if (c == 'C')
				g->collectibles++;
			if (c == 'E')
				g->exit_cnt++;
			if (c == 'P')
			{
				g->player_x = x;
				g->player_y = y;
			}
			x++;
		}
		y++;
	}
	if (g->exit_cnt != 1 || g->collectibles < 1 || g->player_x < 0)
		error_exit("map needs 1E 1P >=1C\n");
}

/**********************************************************************
 * load_map: Loads the map from a file into the game state.
 * - g: Pointer to the game state structure to store the map.
 * - path: Path to the map file (.ber).
 *
 * This function:
 * - Opens the given map file for reading.
 * - Reads the entire contents into a buffer.
 * - Splits the contents by newline into an array of strings.
 * - Stores the lines in g->map, setting map height and width.
 * - Ensures the map is not empty.
 *
 * Returns:
 * - 1 on success.
 *
 * Assumes:
 * - path points to a valid file.
 * - sl_read_all() and ft_split() are implemented and handle memory.
 **********************************************************************/
// int	load_map(t_game *g, const char *path)
// {
// 	int		fd;
// 	char	*all;
// 	char	**lines;
// 	int		h;

// 	fd = open(path, O_RDONLY);
// 	if (fd < 0)
// 		error_exit("open\n");
// 	all = sl_read_all(fd);
// 	close(fd);
// 	lines = ft_split(all, '\n');
// 	free(all);
// 	if (!lines || !lines[0])
// 		error_exit("empty map\n");
// 	h = 0;
// 	while (lines[h])
// 		h++;
// 	g->map = lines;
// 	g->map_height = h;
// 	g->map_width = (int)ft_strlen(lines[0]);
// 	return (1);
// }
int load_map(t_game *g, const char *path)
{
    int fd = open(path, O_RDONLY);
    char *all;
    char **lines;
    int h = 0;

    if (fd < 0)
        error_exit("open\n");
    all = sl_read_all(fd);
    close(fd);

    lines = ft_split(all, '\n');
    free(all);

    if (!lines || !lines[0])
        error_exit("empty map\n");

    while (lines[h])
        h++;

    g->map = lines;
    g->map_height = h;
    g->map_width = (int)ft_strlen(lines[0]);
    return 1;
}

/**********************************************************************
 * validate_map: Performs full validation of the loaded map.
 * - g: Pointer to the game state structure containing the map.
 *
 * This function:
 * - Resets player, collectible, and exit counters.
 * - Validates rectangularity and wall boundaries using check_shape_and_walls().
 * - Validates characters and counts entities using count_and_check_chars().
 * - Ensures the map is solvable by calling validate_path().
 *
 * Returns:
 * - 1 on successful validation.
 *
 * Assumes:
 * - g->map has been loaded by load_map().
 * - validate_path() is implemented to check map reachability.
 **********************************************************************/
int	validate_map(t_game *g)
{
	g->player_x = -1;
	g->player_y = -1;
	g->collectibles = 0;
	g->exit_cnt = 0;
	check_shape_and_walls(g);
	count_and_check_chars(g);
	validate_path(g);
	return (1);
}
