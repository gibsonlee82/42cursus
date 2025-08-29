NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -I.
SRCS = main.c utils.c map.c path.c render.c game.c events.c
OBJS = $(SRCS:.c=.o)
LIBFT = ./libft/libft.a
MLX = ./mlx/libmlx.a

%.o: %.c so_long.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) -lXext -lX11 -lm -o $(NAME)

$(LIBFT):
	$(MAKE) -C libft

$(MLX):
	$(MAKE) -C mlx

all: $(NAME)

clean:
	rm -f $(OBJS)
	$(MAKE) -C libft clean
	$(MAKE) -C mlx clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean
	$(MAKE) -C mlx clean

re: fclean all

.PHONY: all clean fclean re
