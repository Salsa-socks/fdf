# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bnkosi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/22 07:11:59 by bnkosi            #+#    #+#              #
#    Updated: 2019/08/22 07:18:49 by bnkosi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FLAGS = -Wall -Wextra -Werror

FLAGS2 = -L minilibx -lmlx -framework OpenGL -framework AppKit

SRC = fdf.c mlx_opts.c make_window.c draw_box.c draw_boxb.c creategrid.c draw_map.c 

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

