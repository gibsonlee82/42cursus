#include "so_long.h"

/*****************************************************************
 Entry point of the game.
 Initializes the game and enters the MLX loop.
******************************************************************/
int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		write(2, "Error\nUsage: ./so_long map.ber\n", 31);
		return (1);
	}
	init_game(&game, argv[1]);
	mlx_loop(game.mlx);
	return (0);
}
