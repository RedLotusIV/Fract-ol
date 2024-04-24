# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amouhand <amouhand@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/18 00:04:02 by amouhand          #+#    #+#              #
#    Updated: 2024/04/22 00:50:28 by amouhand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = src/main.c src/utils.c src/mandelbrot.c src/julia.c src/parsing.c\
src/display.c src/keyboard_hook.c src/mouse_hook.c src/print_controls.c\
src/math.c src/color.c

NAME = fractol

LIBFT = libft/libft.a

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -g3 -O0

MLX = -Lminilibx-linux -lmlx_Linux -lX11 -lXext

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
$(LIBFT):
	@make -s -C libft/

clean:
	@make -s -C libft clean
	@rm -rf $(OBJ)

fclean: clean
	@make -s -C libft fclean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
