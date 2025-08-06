#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <minilibx-linux/mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include "../libft/ft_printf.h"

// Keep resolution small
# define IMG_HEIGHT			32
# define IMG_WIDTH			32

// Manual defined chars
# define WALL				'1'
# define FLOOR 				'0'
# define COINS  			'C'
# define PLAYER				'P'
# define MAP_EXIT 		 	'E'

// Keyboard ASCII values
# define KEY_W				119
# define KEY_A				97
# define KEY_S				115
# define KEY_D				100
# define KEY_Q				113

// X11 KeySems
# define KEY_UP  			65362
# define KEY_LEFT  			65361
# define KEY_RIGHT 			65363
# define KEY_DOWN  			65364
# define KEY_ESC  			65307

// Custom facing direction
// # define FRONT				1
// # define LEFT				2
// # define RIGHT				3
// # define BACK				4

// XPM assets
// # define WALL_XPM			"assets/sprites/wall.xpm"
// # define FLOOR_XPM			"assets/sprites/floor.xpm"
// # define COINS_XPM			"assets/sprites/coin-bag.xpm"
// # define PLAYER_FRONT_XPM	"assets/sprites/player/front.xpm"
// # define PLAYER_LEFT_XPM	"assets/sprites/player/left.xpm"
// # define PLAYER_RIGHT_XPM	"assets/sprites/player/right.xpm"
// # define PLAYER_BACK_XPM	"assets/sprites/player/back.xpm"
// # define OPEN_EXIT_XPM		"assets/sprites/open-exit.xpm"
// # define EXIT_CLOSED_XPM	"assets/sprites/exit-closed.xpm"

// | Game Element           | Suggested Color | ANSI Code    | Use case example                   |
// | ---------------------- | --------------- | ------------ | ---------------------------------- |
// | **Player**             | Bright Cyan     | `\033[1;96m` | So the player stands out           |
// | **Wall**               | Bright Blue     | `\033[1;94m` | Strong visual border               |
// | **Floor**              | Grey            | `\033[0;90m` | Neutral background                 |
// | **Coin / Collectible** | Yellow          | `\033[1;33m` | Eye-catching, represents gold      |
// | **Exit (closed)**      | Bright Red      | `\033[1;91m` | Alerts the player that it's locked |
// | **Exit (open)**        | Green           | `\033[0;32m` | Success, safe zone                 |
// | **Text / Messages**    | White (default) | `\033[0m`    | General messages                   |
// | **Errors**             | Bold Red        | `\033[1;31m` | For critical errors or warnings    |
// | **Debug**              | Grey            | `\033[0;90m` | For internal logs or info          |
# define Cyan		"\033[1;96m"
# define Blue		"\033[1;94m"
# define Grey		"\033[0;90m"
# define Yellow		"\033[1;33m"
# define Red		"\033[1;91m"
# define Green		"\033[0;32m"
# define White		"\033[0m"
# define BoldRed	"\033[1;31m"
# define Grey		"\033[0;90m"

// // Colour
// # define GREEN				"\033[0;32m"
// # define RED 				"\033[1;31m"
// # define GREY 				"\033[0;90m"
// # define CYAN				"\033[1;96m"
// # define RESET 				"\033[0m"

// Enum Bool
typedef enum e_bool
{
	false,
	true
}	t_bool;

// Store position of player
typedef struct s_position
{
	int	x;
	int	y;
}	t_positon;

// Store position and xpm_pointer to image
typedef struct s_image
{
	void	*xpm_ptr;
	int		x;
	int		y;
}	t_image;

// Store map parameters
typedef struct s_map
{
	char		**full;
	int			rows;
	int			columns;
	int			coins;
	int			exit;
	int			players;
	t_positon	player;
}	t_map;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			movements;
	int			player_sprite;
	t_map		map;
	t_bool		map_alloc;
	t_image		wall;
	t_image		floor;
	t_image		coins;
	t_image		open_exit;
	t_image		exit_closed;
	t_image		player_front;
	t_image		player_left;
	t_image		player_right;
	t_image		player_back;
}	t_game;

// game.c
void	init_game(t_game *game, char *filename);
void	load_images(t_game *game);

// map.c
int		load_map(t_game *game, char *filename);
int		count_rows(char *filename);
char	**allocate_map(int height);
void	free_map(char **map);

// validate_path.c
int		check_path(t_game *game);

// validate_format.c
int		validate_map(t_game *game);

// render.c
void	draw_map(t_game *game);

// hooks.c
int		handle_key(int keycode, t_game *game);
int		close_window(t_game *game);

// player.c
void	move_player(t_game *game, int dx, int dy);

#endif
