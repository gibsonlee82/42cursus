/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giblee <abc@abc.com>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 10:00:33 by giblee            #+#    #+#             */
/*   Updated: 2025/08/29 11:13:10 by giblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

/**********************************************************************
 * flood: Recursive flood-fill used for path validation.
 * - m: Copy of the map as a 2D array of characters.
 * - x, y: Current coordinates being explored.
 * - g: Pointer to the game state structure for map dimensions.
 *
 * This function:
 * - Stops recursion if coordinates are outside map bounds.
 * - Stops if the current cell is a wall ('1') or already visited ('V').
 * - Marks the current cell as visited ('V').
 * - Recursively calls itself in four directions (up, down, left, right).
 *
 * Assumes:
 * - m is a valid copy of g->map with the same dimensions.
 * - g->map_width and g->map_height define valid boundaries.
 **********************************************************************/
static void	flood(char **m, int x, int y, t_game *g)
{
	if (x < 0 || y < 0)
		return ;
	if (y >= g->map_height || x >= g->map_width)
		return ;
	if (m[y][x] == '1' || m[y][x] == 'V')
		return ;
	m[y][x] = 'V';
	flood(m, x + 1, y, g);
	flood(m, x - 1, y, g);
	flood(m, x, y + 1, g);
	flood(m, x, y - 1, g);
}

/**********************************************************************
 * dup_map: Creates a deep copy of the current map.
 * - g: Pointer to the game state structure containing the map.
 *
 * This function:
 * - Allocates memory for a duplicate 2D array of the map.
 * - Copies each row from g->map using ft_strdup().
 * - Terminates the array with a NULL pointer.
 * - Exits with error if allocation fails.
 *
 * Returns:
 * - A pointer to the duplicated 2D array of the map.
 *
 * Assumes:
 * - g->map is loaded and valid.
 * - ft_calloc and ft_strdup are available and working correctly.
 **********************************************************************/
static char	**dup_map(t_game *g)
{
	char	**cp;
	int		y;

	cp = ft_calloc(g->map_height + 1, sizeof(char *));
	if (!cp)
		error_exit("malloc\n", g);
	y = 0;
	while (y < g->map_height)
	{
		cp[y] = ft_strdup(g->map[y]);
		if (!cp[y])
			error_exit("malloc\n", g);
		y++;
	}
	return (cp);
}

/**********************************************************************
 * check_reachability: Validates reachability of collectibles and exit.
 * - g: Pointer to the game state containing original map data.
 * - cp: Flooded duplicate of the map where reachable tiles are marked.
 *
 * This function:
 * - Iterates through every tile in the map copy.
 * - Counts reachable collectibles ('C' marked as 'V').
 * - Checks if exit ('E') is reachable (marked as 'V').
 * - Frees each row of the map copy after scanning.
 * - Frees the map copy array itself.
 * - Exits with error if not all collectibles are reachable or if exit
 *   is unreachable.
 *
 * Assumes:
 * - cp is a valid flooded duplicate created by dup_map().
 * - flood() has already marked reachable areas with 'V'.
 **********************************************************************/
static void	check_reachability(t_game *g, char **cp)
{
	int	y;
	int	x;
	int	cf;
	int	ef;

	cf = 0;
	ef = 0;
	y = 0;
	while (y < g->map_height)
	{
		x = 0;
		while (x < g->map_width)
		{
			if (g->map[y][x] == 'C' && cp[y][x] == 'V')
				cf++;
			if (g->map[y][x] == 'E' && cp[y][x] == 'V')
				ef = 1;
			x++;
		}
		free(cp[y]);
		y++;
	}
	free(cp);
	if (cf != g->collectibles || ef == 0)
		error_exit("unsolvable map\n", g);
}

/**********************************************************************
 * validate_path: Ensures the map is solvable by flood-fill validation.
 * - g: Pointer to the game state structure containing the map.
 *
 * This function:
 * - Creates a duplicate of the map with dup_map().
 * - Runs flood-fill starting at the player’s position to mark reachable
 *   tiles in the duplicate.
 * - Calls check_reachability() to ensure all collectibles and exit are
 *   reachable from the starting position.
 * - Exits with error if the map is unsolvable.
 *
 * Returns:
 * - 1 if the map is valid and solvable.
 *
 * Assumes:
 * - g->map is fully loaded and rectangular.
 * - g->player_x and g->player_y are set.
 **********************************************************************/
int	validate_path(t_game *g)
{
	char	**cp;

	cp = dup_map(g);
	flood(cp, g->player_x, g->player_y, g);
	check_reachability(g, cp);
	return (1);
}
