/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giblee <abc@abc.com>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 10:00:33 by giblee            #+#    #+#             */
/*   Updated: 2025/08/29 11:13:10 by giblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// | Map char | Role        | Graphics           |
// | -------- | ----------- | ------------------ |
// | `1`      | Wall        | Brick              |
// | `0`      | Empty space | Plain color        |
// | `P`      | Player      | Owl                |
// | `C`      | Collectible | Mouse              |
// | `E`      | Exit        | Portal             |

#include "so_long.h"

/**********************************************************************
 * load_img: Loads a texture from an XPM file into a game image slot.
 * - g: Pointer to the game state structure.
 * - slot: Pointer to the image slot to populate.
 * - path: Path to the XPM texture file.
 *
 * On success:
 * - The slot->img, slot->w, and slot->h fields are filled by mlx.
 *
 * On failure:
 * - Calls error_exit() with an error message and terminates.
 **********************************************************************/
static void	load_img(t_game *g, t_img *slot, char *path)
{
	slot->img = mlx_xpm_file_to_image(g->mlx, path, &slot->w, &slot->h);
	if (!slot->img)
		error_exit("texture load\n", g);
}

/**********************************************************************
 * load_textures: Loads all required textures for the game.
 * - g: Pointer to the game state structure.
 *
 * Textures loaded:
 * - floor, wall, player, exit, collectible
 *
 * Returns:
 * - Always returns 1 (success).
 *
 * On failure:
 * - Terminates with error_exit().
 **********************************************************************/
int	load_textures(t_game *g)
{
	load_img(g, &g->floor, "textures/floor.xpm");
	load_img(g, &g->wall, "textures/wall.xpm");
	load_img(g, &g->player, "textures/ghost.xpm");
	load_img(g, &g->exit_img, "textures/exit.xpm");
	load_img(g, &g->collect, "textures/pumpkim.xpm");
	return (1);
}

/**********************************************************************
 * put_tile: Renders a single map tile at given coordinates.
 * - g: Pointer to the game state structure.
 * - x: Map X coordinate (tile units).
 * - y: Map Y coordinate (tile units).
 * - c: Map character ('0', '1', 'P', 'E', 'C').
 *
 * Behavior:
 * - Always draws the floor first (background).
 * - Overlays the appropriate tile image based on character type.
 *
 * Assumes:
 * - Textures are already loaded.
 **********************************************************************/
static void	put_tile(t_game *g, int x, int y, char c)
{
	void	*img;

	img = g->floor.img;
	if (c == '1')
		img = g->wall.img;
	if (c == 'P')
		img = g->player.img;
	if (c == 'E')
		img = g->exit_img.img;
	if (c == 'C')
		img = g->collect.img;
	mlx_put_image_to_window(g->mlx, g->win, img,
		x * RESOLUTION, y * RESOLUTION);
}

/**********************************************************************
 * render_map: Renders the entire game map to the window.
 * - g: Pointer to the game state structure.
 *
 * Iterates over all map tiles and calls put_tile() to draw each.
 *
 * Assumes:
 * - g->map is a valid 2D array of characters.
 * - g->map_width and g->map_height are set.
 **********************************************************************/
void	render_map(t_game *g)
{
	int	x;
	int	y;

	y = 0;
	while (y < g->map_height)
	{
		x = 0;
		while (x < g->map_width)
		{
			put_tile(g, x, y, g->map[y][x]);
			x++;
		}
		y++;
	}
}
