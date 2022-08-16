SRCS = 	main.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c \
		src/fill_array.c \
		src/fill_identifiers.c\
		src/init.c \
		src/free.c\
		libft/utils.c \

OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra
MLX = -L minilibx-linux -lmlx -lX11 -lXext -lm #ajouter compilation!

NAME = cub3D
HEADER = Cub_3D.h

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	$(OBJS)
		${CC} ${CFLAGS} $(OBJS) -Lget_next_line -o $(NAME) $(MLX)

all:		$(NAME)

get_next_line:
	make -C

clean:
		rm -f $(OBJS)

fclean:
	rm -f $(OBJS) $(NAME)

re: fclean all

.PHONY: all clean fclean re