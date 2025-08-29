/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giblee <abc@abc.com>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 10:00:33 by giblee            #+#    #+#             */
/*   Updated: 2025/08/29 11:13:10 by giblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"
#include <stdio.h>

/**********************************************************************
 * do_move: Attempts to move the player to a new position.
 * - g: Pointer to the game state structure.
 * - nx: New X coordinate for the player.
 * - ny: New Y coordinate for the player.
 *
 * This function:
 * - Ignores movement into walls ('1').
 * - Handles stepping on an exit ('E'):
 *     - If collectibles remain, player cannot exit.
 *     - If all collectibles are collected, increments move counter
 *       and exits the game successfully.
 * - Decrements collectible count when stepping on a collectible ('C').
 * - Updates the map by setting the old player position to '0'
 *   and the new position to 'P'.
 * - Updates player coordinates and increments move counter.
 * - Prints the current move count to stdout.
 *
 * Assumes:
 * - nx, ny are within map bounds.
 * - g->map is loaded and valid.
 * - render_map() will be called afterwards to update graphics.
 **********************************************************************/
static void	do_move(t_game *g, int nx, int ny)
{
	char	tile;

	tile = g->map[ny][nx];
	if (tile == '1')
		return ;
	if (tile == 'E')
	{
		if (g->collectibles == 0)
		{
			g->moves++;
			printf("Moves: %d\n", g->moves);
			exit(0);
		}
		return ;
	}
	if (tile == 'C')
		g->collectibles--;
	g->map[g->player_y][g->player_x] = '0';
	g->player_x = nx;
	g->player_y = ny;
	g->map[ny][nx] = 'P';
	g->moves++;
	printf("Moves: %d\n", g->moves);
}

/**********************************************************************
 * handle_key: Handles keyboard input for player movement and exit.
 * - key: Keycode of the pressed key.
 * - g: Pointer to the game state structure.
 *
 * This function:
 * - Exits the game cleanly if ESC is pressed.
 * - Moves the player up (W), down (S), left (A), or right (D)
 *   by calling do_move() with updated coordinates.
 * - Calls render_map() after movement to redraw the game state.
 *
 * Returns:
 * - Always returns 0 (as required by mlx_key_hook).
 *
 * Assumes:
 * - Keycodes are defined correctly depending on platform
 *   (Linux vs macOS).
 * - do_move() updates the game state correctly.
 **********************************************************************/
int	handle_key(int key, t_game *g)
{
	if (key == KEY_ESC)
		return (close_game(g));
	if (key == KEY_W || key == KEY_UP)
		do_move(g, g->player_x, g->player_y - 1);
	if (key == KEY_S || key == KEY_DOWN)
		do_move(g, g->player_x, g->player_y + 1);
	if (key == KEY_A || key == KEY_LEFT)
		do_move(g, g->player_x - 1, g->player_y);
	if (key == KEY_D || key == KEY_RIGHT)
		do_move(g, g->player_x + 1, g->player_y);
	render_map(g);
	return (0);
}