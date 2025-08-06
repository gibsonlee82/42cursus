#include "so_long.h"

/*
** Moves player on the map if the move is valid.
** Updates movement count and collectible count.
*/
void	move_player(t_game *game, int dx, int dy)
{
	int	new_x = game->player_x + dx;
	int	new_y = game->player_y + dy;
	char	tile = game->map[new_y][new_x];

	if (tile == '1')
		return ;
	if (tile == 'C')
		game->collect_count--;
	if (tile == 'E' && game->collect_count == 0)
		close_window(game);
	game->map[game->player_y][game->player_x] = '0';
	game->map[new_y][new_x] = 'P';
	game->player_x = new_x;
	game->player_y = new_y;
	game->moves++;
	ft_printf("Moves: %d\n", game->moves);
	draw_map(game);
}
