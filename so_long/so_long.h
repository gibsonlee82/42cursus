/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giblee <abc@abc.com>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 10:00:33 by giblee            #+#    #+#             */
/*   Updated: 2025/08/29 11:13:10 by giblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "mlx/mlx.h"
# include "libft/libft.h"

// 64 x 64 pixels
# define RESOLUTION 64

# ifdef __linux__
#  define KEY_ESC 	65307
#  define KEY_W   	119
#  define KEY_S   	115
#  define KEY_A   	97
#  define KEY_D   	100
#  define KEY_UP	65362
#  define KEY_DOWN	65364
#  define KEY_LEFT	65361
#  define KEY_RIGHT	65363
# else
#  define KEY_ESC 	53
#  define KEY_W   	13
#  define KEY_S   	1
#  define KEY_A   	0
#  define KEY_D   	2
#  define KEY_UP	126
#  define KEY_DOWN	125
#  define KEY_LEFT	123
#  define KEY_RIGHT	124
# endif

typedef struct s_img
{
	void	*img;
	int		w;
	int		h;
}	t_img;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		map_width;
	int		map_height;
	int		player_x;
	int		player_y;
	int		collectibles;
	int		exit_cnt;
	int		moves;

	t_img	wall;
	t_img	floor;
	t_img	player;
	t_img	exit_img;
	t_img	collect;
}	t_game;

// utils
void	error_exit(char *msg);
char	*sl_read_all(int fd);
// void	free_map(char **map, int height);
void	free_map(char **map);
int	handle_resize(t_game *g);

// map
int		load_map(t_game *g, const char *path);
int		validate_map(t_game *g);

// path
int		validate_path(t_game *g);

// render
int		load_textures(t_game *g);
void	render_map(t_game *g);

// games
int		close_game(t_game *g);
int		handle_key(int key, t_game *g);
int		start_game(t_game *g);

#endif
