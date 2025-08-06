#include "so_long.h"

/*
** Handles key presses and moves the player.
*/
int	handle_key(int keycode, t_game *game)
{
	if (keycode == 65307) // ESC
		close_window(game);
	else if (keycode == 'w')
		move_player(game, 0, -1);
	else if (keycode == 's')
		move_player(game, 0, 1);
	else if (keycode == 'a')
		move_player(game, -1, 0);
	else if (keycode == 'd')
		move_player(game, 1, 0);
	return (0);
}

/*
** Properly frees resources and exits.
*/
int	close_window(t_game *game)
{
	free_map(game->map);
	exit(0);
}
