SRCS = 	main.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c \
		src/fill_array.c \
		src/fill_identifiers.c\
		src/init.c \
		src/create_map.c \
		src/free.c\
		libft/utils.c \

OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra 
#pour checker les leaks:
#-fsanitize=leaks -fsanitize=undefined  -fsanitize=address -g3

NAME = cub_3d
HEADER = cub_3d.h

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
