NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = pipex.c utils.c
OBJS = $(SRCS:.c=.o)
LIBFT = ./libft/libft.a

all: $(NAME)

$(LIBFT):
	$(MAKE) -C ./libft

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	rm -f $(OBJS)
	$(MAKE) clean -C ./libft

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C ./libft

re: fclean all
