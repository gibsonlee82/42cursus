/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giblee <abc@abc.com>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 10:00:33 by giblee            #+#    #+#             */
/*   Updated: 2025/08/29 11:13:10 by giblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

/**********************************************************************
 * init_game: Initializes the game state structure with default values.
 * - g: Pointer to the game state structure to be initialized.
 *
 * This function:
 * - Sets all pointers (mlx, win, map) to NULL.
 * - Resets map dimensions (width, height) to 0.
 * - Sets player position (x, y) to -1 (indicating uninitialized).
 * - Initializes collectible count, exit count, and move counter to 0.
 *
 * Assumes:
 * - g is a valid, allocated pointer to a t_game struct.
 **********************************************************************/
static void	init_game(t_game *g)
{
	g->mlx = NULL;
	g->win = NULL;
	g->map = NULL;
	g->map_width = 0;
	g->map_height = 0;
	g->player_x = -1;
	g->player_y = -1;
	g->collectibles = 0;
	g->exit_cnt = 0;
	g->moves = 0;
}

/**********************************************************************
 * main: Entry point of the program. Initializes game and starts engine.
 * - argc: Argument count.
 * - argv: Argument vector containing program name and map filename.
 *
 * This function:
 * - Ensures exactly one argument is provided (the map filename).
 * - Checks if the filename ends with the ".ber" extension.
 * - Initializes the game state.
 * - Loads the map from the provided file.
 * - Validates the map for correctness (walls, player, exit, collectibles).
 * - Initializes the MiniLibX (mlx) graphics library.
 * - Starts the game loop via start_game().
 *
 * Assumes:
 * - argv[1] exists and is a readable map file ending with ".ber".
 * - Supporting functions (load_map, validate_map, start_game) handle
 *   memory allocation, error handling, and game loop setup.
 **********************************************************************/
int	main(int argc, char **argv)
{
	t_game	g;

	if (argc != 2)
		error_exit("usage: ./so_long file.ber\n", &g);
	init_game(&g);
	if (ft_strncmp(argv[1] + (ft_strlen(argv[1]) - 4), ".ber", 4) != 0)
		error_exit("need .ber\n", &g);
	load_map(&g, argv[1]);
	validate_map(&g);
	g.mlx = mlx_init();
	if (!g.mlx)
		error_exit("mlx init\n", &g);
	start_game(&g);
	return (0);
}
