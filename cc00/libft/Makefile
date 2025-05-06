NAME = libft.a
CFLAGS = -Wall -Wextra -Werror -g
COMPILER = cc
SRCS = ft_putchar.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isalpha.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_isspace.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_atoi.c \
	ft_atoll.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_bzero.c \
	ft_memccpy.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_strlen.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strnstr.c \
	ft_strncmp.c \
	ft_strndup.c \
	ft_strcmp.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_putstr.c \
	ft_putnbr.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_realloc.c \
	ft_itoa.c \
	ft_substr.c \
	ft_strtrim.c \
	ft_strjoin.c \
	ft_split.c \
	ft_split_dlim.c\
	ft_strmapi.c \
	ft_striteri.c \
	ft_count_words.c \
	ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstsize.c \
	ft_lstlast.c \
	ft_lstadd_back.c \
	ft_lstdelone.c \
	ft_lstclear.c \
	ft_lstiter.c \
	ft_lstmap.c \
	./printf/ft_printf.c \
	./printf/putcharf.c \
	./printf/putstrf.c \
	./printf/print_ptr.c \
	./printf/print_ptr_hex.c \
	./printf/ptr_len.c \
	./printf/print_decimal.c \
	./printf/print_unsigned_dec.c \
	./printf/print_dec_width2.c \
	./printf/numlen.c \
	./printf/print_dec_wz.c \
	./printf/print_dec_wp2.c \
	./printf/print_hexa.c \
	./get_next_line/get_next_line.c \
	./get_next_line/get_next_line_utils.c

OBJS = ${SRCS:.c=.o}


${NAME}: ${OBJS}
	@ar rcs ${NAME} ${OBJS}
.c.o:
	@${COMPILER} ${CFLAGS} -c $< -o $@

all: $(NAME)

clean:
	rm -rf *.o

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
