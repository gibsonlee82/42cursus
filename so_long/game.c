/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giblee <abc@abc.com>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 10:00:33 by giblee            #+#    #+#             */
/*   Updated: 2025/08/29 11:13:10 by giblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

/**********************************************************************
 * close_game: Cleans up resources and exits the program.
 * - g: Pointer to the game state structure.
 *
 * This function:
 * - Destroys the game window if it exists.
 * - Frees all allocated rows of the map and the map itself.
 * - Terminates the program with exit(0).
 *
 * Assumes:
 * - g->mlx and g->win are initialized if a window was created.
 * - g->map is allocated and has g->map_height rows.
 **********************************************************************/
int	close_game(t_game *g)
{
	if (g->win)
		mlx_destroy_window(g->mlx, g->win);
	if (g->map)
		free_map(g->map);
	exit(0);
}

/**********************************************************************
 * start_game: Initializes window, loads resources, and starts game loop.
 * - g: Pointer to the game state structure.
 *
 * This function:
 * - Creates a new MLX window sized according to map dimensions.
 * - Loads game textures with load_textures().
 * - Renders the initial map on the window with render_map().
 * - Registers event hooks:
 *     - Hook 17 (window close) to close_game().
 *     - Key press events to handle_key().
 * - Enters the MLX main loop to begin rendering and event handling.
 *
 * Returns:
 * - 0 on success (though this function only exits when the game ends).
 *
 * Assumes:
 * - g->mlx has been initialized with mlx_init().
 * - g->map, g->map_width, and g->map_height are set.
 * - load_textures() and render_map() are implemented and succeed.
 **********************************************************************/
int	start_game(t_game *g)
{
	g->win = mlx_new_window(g->mlx, g->map_width * RESOLUTION,
			g->map_height * RESOLUTION, "so_long");
	if (!g->win)
		error_exit("mlx window\n", g);
	if (!load_textures(g))
		error_exit("textures\n", g);
	render_map(g);
	mlx_hook(g->win, 17, 0, close_game, g);
	mlx_key_hook(g->win, handle_key, g);
	mlx_loop(g->mlx);
	return (0);
}
