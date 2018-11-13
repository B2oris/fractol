# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: beborch <beborch@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/12 23:21:48 by beborch           #+#    #+#              #
#    Updated: 2018/10/12 23:38:16 by beborch          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fractol

SRC =  srcs/main.c srcs/mandelbrot.c srcs/burning_ship.c srcs/color.c srcs/julia.c srcs/hook.c

OBJ = $(SRC:.c=.o)

FLAGS := -Wall -Werror -Wextra 

INCLUDES := -I./libft/

MLX := -lmlx -framework OpenGL -framework AppKit

LIBS := -Llibft/ -lft

all : $(NAME)

$(NAME) : $(OBJ)
	make -C mlx/
	make -C libft/
	gcc $(INCLUDES) $(FLAGS) -g $(LIBS) $(OBJ) $(MLX) -o $(NAME)

%.o: %.c ./includes/fractol.h
	gcc -g $(INCLUDES) -o $@ -c $< 

clean :
	make -C libft/ clean
	make -C mlx/ clean
	rm -rf $(OBJ)

fclean : clean
	make -C libft/ fclean
	rm -rf $(NAME)

re : fclean all

.PHONY = $(NAME) all clean fclean re
