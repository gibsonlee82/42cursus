#include "so_long.h"

/*
 Initializes the game state and starts rendering.
*/
void	init_game(t_game *game, char *filename)
{
	if (!load_map(game, filename))
		exit(write(2, "Error\nFailed to load map.\n", 26));
	if (!validate_map(game))
		exit(write(2, "Error\nInvalid map.\n", 20));
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->width * TILE_SIZE,
			game->height * TILE_SIZE, "so_long");
	load_images(game);
	draw_map(game);
	mlx_key_hook(game->win, handle_key, game);
	mlx_hook(game->win, 17, 0, close_window, game);
}

void	load_images(t_game *game)
{
	int	w, h;

	game->img_wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm", &w, &h);
	game->img_floor = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm", &w, &h);
	game->img_player = mlx_xpm_file_to_image(game->mlx, "textures/player.xpm", &w, &h);
	game->img_collect = mlx_xpm_file_to_image(game->mlx, "textures/collectible.xpm", &w, &h);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm", &w, &h);

	if (!game->img_wall || !game->img_floor || !game->img_player
		|| !game->img_collect || !game->img_exit)
	{
		write(2, "Error\nFailed to load one or more XPM images.\n", 46);
		exit(1);
	}
}
