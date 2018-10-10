NAME := fractol

SRC =  main.c

OBJ = $(SRC:.c=.o)

FLAGS := -Wall -Werror -Wextra 

INCLUDES := -I./libft/

MLX := -lmlx -framework OpenGL -framework AppKit

LIBS := -Llibft/ -lft

all : $(NAME)
# penser a remettre les flags
$(NAME) : $(OBJ)
	make -C mlx/
	make -C libft/
	gcc $(INCLUDES) -g $(LIBS) $(OBJ) $(MLX) -o $(NAME)

%.o: %.c ./fractol.h
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