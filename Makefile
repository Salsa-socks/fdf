NAME = fdf

CC = clang

FLAGS = -Wall -Wextra -Werror

FLAGS2 = -L minilibx -lmlx -framework OpenGL -framework AppKit

SRC = *.c

LIBFT_DIR = libft
LIBS = libft/libft.a

OBJS = $(SRC:.c=.o)

HEADER = fdf.h

all: $(NAME)

$(LIBS):
	make -C $(LIBFT_DIR)

$(NAME): $(SRC) $(LIBS)
	$(CC) $(FLAGS) $(FLAGS2) $(SRC) $(LIBS) -o fdf

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -rf $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all
