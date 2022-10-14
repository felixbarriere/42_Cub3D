SRCS = 	main.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c \
		src/parsing/check_elem.c \
		src/parsing/check_elem_2.c \
		src/parsing/check_map.c \
		src/parsing/check_map_2.c \
		src/parsing/fill_map.c \
		src/parsing/fill_file.c \
		src/init/fill_array.c \
		src/init/fill_identifiers.c \
		src/init/init.c \
		src/raycasting/raycasting.c \
		src/raycasting/raycasting_2.c \
		src/raycasting/raycasting_utils.c \
		src/moves/moves.c \
		src/moves/hooks.c \
		src/utils/free.c \
		src/utils/utils.c\
		libft/libft_1.c \
		libft/libft_2.c \
		libft/libft_3.c \


OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra 
#pour checker les leaks:
# valgrind ou
#-fsanitize=leaks -fsanitize=undefined  -fsanitize=address -g3

NAME = cub3D
HEADER = CUB3D.h

.c.o:
		${CC} ${CFLAGS} -I/usr/include -I ./mlx -c $< -o ${<:.c=.o}

$(NAME):	$(OBJS)
		${CC} ${CFLAGS} $(OBJS) -L./mlx -lmlx -lXext -lX11 -lm -Lget_next_line -o $(NAME)

# pour faire tourner le programme sur Linux, ajouter -Lmlx
MLX_DIR = mlx
MLX_MAKE = Makefile
MLX_PATH = ${MLX_DIR}/libmlx.a

all:		$(NAME)

get_next_line:
	make -C

clean:
		rm -f $(OBJS)

fclean:
	rm -f $(OBJS) $(NAME)

re: fclean all

.PHONY: all clean fclean re
