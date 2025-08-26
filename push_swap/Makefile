NAME = push_swap

SRC =	execute_rotations.c \
		gl_sort2.c \
		ops_push.c \
		ops_rev_rot.c \
		ops_rot.c \
		ops_swap.c \
		parse.c \
		push_back_to_a_sorted.c \
		push_swap.c \
		push_to_b_sorted.c \
		sort_utils.c \
		utils.c

OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re