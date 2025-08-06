# **************************************************************************** #
#                                  MAKEFILE                                    #
# **************************************************************************** #

# Project name
NAME		= so_long

# Compiler and flags
CC			= cc
CFLAGS		= -Wall -Wextra -Werror

# Directories
SRC_DIR		= .
OBJ_DIR		= objs
LIBFT_DIR	= libft

# Sources and Objects
SRCS		= 	main.c \
				map.c \
				game.c \
				render.c \
				player.c \
				hooks.c \
				validate_format.c \
				validate_path.c
				
OBJS		= $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

# Libft
LIBFT		= $(LIBFT_DIR)/libft.a
LIBFT_INC	= -I$(LIBFT_DIR)

# MiniLibX (macOS) - change if using Linux
# MLX_FLAGS	= -lmlx -framework OpenGL -framework AppKit
MLX_DIR    = minilibx-linux
MLX        = $(MLX_DIR)/libmlx.a
MLX_FLAGS  = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lbsd
INCLUDES   = -I. -I$(MLX_DIR)

# Includes
INCLUDES	= -I. $(LIBFT_INC)

# Default target
all: $(NAME)

# Compile final binary
$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

# Create obj dir if not exists, then build .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Make sure obj dir exists
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Build libft
$(LIBFT):
	make -C $(LIBFT_DIR)

# Bonus rule
bonus: all

# Clean object files
clean:
	rm -rf $(OBJ_DIR)
	make clean -C $(LIBFT_DIR)

# Clean everything
fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

# Rebuild
re: fclean all

.PHONY: all clean fclean re bonus
