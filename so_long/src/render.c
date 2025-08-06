#include "so_long.h"

/*
** Draws the map onto the MLX window using tile images.
*/
void	draw_map(t_game *game)
{
	int		x, y;
	char	tile;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			tile = game->map[y][x];
			mlx_put_image_to_window(game->mlx, game->win,
				game->img_floor, x * TILE_SIZE, y * TILE_SIZE);
			if (tile == '1')
				mlx_put_image_to_window(game->mlx, game->win,
					game->img_wall, x * TILE_SIZE, y * TILE_SIZE);
			else if (tile == 'C')
				mlx_put_image_to_window(game->mlx, game->win,
					game->img_collect, x * TILE_SIZE, y * TILE_SIZE);
			else if (tile == 'E')
				mlx_put_image_to_window(game->mlx, game->win,
					game->img_exit, x * TILE_SIZE, y * TILE_SIZE);
			else if (tile == 'P')
				mlx_put_image_to_window(game->mlx, game->win,
					game->img_player, x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
}
