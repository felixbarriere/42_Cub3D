#ifndef CUB_3D_H
# define CUB_3D_H

#include <unistd.h>
#include <stdio.h> //à enlever
#include <stdlib.h>
#include <fcntl.h>
#include "../minilibx-linux/mlx.h"
#include "../get_next_line/get_next_line.h"

typedef struct s_texture {
	char	*north;
	char	*south;
	char	*east;
	char	*west;
	char	*floor;
	char	*ceilling;
}				t_texture;

typedef struct s_game {
	char		**array;
	void		*mlx;
	void		*mlx_win;
	void		*img;
	t_texture	*texture;
}				t_game;


char	**fill_array(char	*file, t_game	*game);
void	ft_init(t_game	*game);

/*********** LIBFT ***********/
char	*ft_strdup(char *src);
int		ft_strncmp(char *s1, char *s2, int n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero( void *pointer, size_t count );
// int	ft_strlen(char *str);

#endif