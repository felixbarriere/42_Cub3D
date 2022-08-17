#ifndef CUB_3D_H
# define CUB_3D_H

#include <unistd.h>
#include <stdio.h> //à enlever
#include <stdlib.h>
#include <fcntl.h>
# include <string.h>
#include <fcntl.h>
#include "../mlx/mlx.h"
#include "../get_next_line/get_next_line.h"

typedef struct s_image
{
	void		*wall;
}	t_image;

typedef struct s_game {
	char		*address;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	char		**array;
	int			y_size;
	void		*mlx;
	void		*mlx_win;
	void		*img;
	char		*north_id;
	char		*south_id;
	char		*east_id;
	char		*west_id;
	char		*floor_id;
	char		*ceilling_id;
	// void		*wall_img;
	t_image		image;
}				t_game;


char	**fill_array(char	*file, t_game	*game);
void	ft_init(t_game	*game);
void	get_identifier(char	*line, t_game	*game);
void	ft_fill_flo(t_game	*game, int x, int y, char **tab);

void	ft_free_array(char **array);
void	ft_free_all(t_game	*game);

/*********** LIBFT ***********/
char	*ft_strdup(char *src);
int		ft_strncmp(char *s1, char *s2, int n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero( void *pointer, size_t count );
// int	ft_strlen(char *str);

#endif