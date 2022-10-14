/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarrier <fbarrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 17:08:44 by fbarrier          #+#    #+#             */
/*   Updated: 2022/09/09 17:08:44 by fbarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CUB_3D_H
# define CUB_3D_H

# include <unistd.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <fcntl.h>
# include <X11/keysym.h>
# include "../mlx/mlx.h"
# include "../get_next_line/get_next_line.h"

typedef struct s_image
{
	void		*wall;
	void		*floor;
}	t_image;

typedef struct s_raycast
{
	int			char_pos_x;
	int			char_pos_y;
	double		charpos_x_2;
	double		charpos_y_2;
	double		dirx;
	double		diry;
	double		planx;
	double		plany;
	double		raydirx;
	double		raydiry;
	double		camerax;
	int			mapx;
	int			mapy;
	double		sidedistx;
	double		sidedisty;
	double		deltadistx;
	double		deltadisty;
	int			stepx;
	int			stepy;
	int			hit;
	int			side;
	double		perpwalldist;
	int			lineheight;
	int			drawstart;
	int			drawend;
	double		movespeed;
	double		rotspeed;
	int			x;
}	t_raycast;

typedef struct s_texture
{
	int				tex_dir;
	double			wall_x;
	int				tex_x;
	int				tex_y;
	double			step;
	double			tex_pos;
}					t_texture;

typedef struct s_game_2
{
	int			*address;
	int			line_length;
	int			bits_per_pixel;
	int			endian;
	int			height;
	int			width;
	void		*img;
}		t_game_2;

typedef struct s_element
{
	int		index;
	char	pos;
	int		north;
	int		south;
	int		west;
	int		east;
	int		floor;
	int		ceilling;
}		t_element;

typedef struct s_game {
	int			*address;
	int			*address_2;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			line;
	void		*mlx;
	void		*mlx_win;
	void		*img;
	void		*img_2;
	char		**file;
	char		**array;
	int			x_size;
	int			y_size;
	int			res_x;
	int			res_y;
	char		*north_id;
	char		*south_id;
	char		*east_id;
	char		*west_id;
	char		*floor_id;
	char		*ceilling_id;
	int			floor_rgb;
	int			ceilling_rgb;
	int			mv_forward;
	int			mv_back;
	int			mv_right;
	int			mv_left;
	int			rot_right;
	int			rot_left;
	t_image		image;
	t_raycast	raycast;
	t_game_2	texture[4];
	t_texture	t;
	t_element	element;
}				t_game;

/*********** FREE ***********/
void	ft_free_array(char **array);
void	ft_free_all(t_game	*game);

/*********** UTILS ***********/
int		ft_elt_pos_x(char	**array);
int		ft_elt_pos_y(char	**array);
int		ft_get_max_y(char	**array);
int		ft_get_max_x(char	**array);
int		ft_close_cross(t_game	*game);
int		ft_close_esc(int keycode, t_game *game);
int		ft_atoi_color(char *str);

/*********** LIBFT ***********/
char	*ft_strdup(char *src);
int		ft_strncmp(char *s1, char *s2, int n);
char	*ft_substr(char *s, int start, int len);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero( void *pointer, size_t count );
char	**ft_split(char *s, char c);
int		ft_atoi(char *str);
int		ft_strcmp(char *s1, char *s2);
int		ft_isdigit(char *str);

/*********** PARSING ***********/
int		ft_check_elem(t_game *game);
int		ft_check_elem_2(char **tab);
int		ft_is_elem_correct(char **tab, t_game *game, int count);
int		ft_is_elem_correct_2(char **tab, t_game *game);
void	ft_init_elem(t_game *game);
int		ft_check_color(char *array);
int		ft_file_correct(char **tab);
int		ft_check_map(t_game *game);
int		ft_check_map_2(t_game *game);
int		ft_check_wall_2(t_game *game, int i, int j);
int		ft_check_wall(t_game *game, int i, int j, int b);
int		ft_check_player(t_game *game);
void	ft_space(t_game *game);
char	**fill_file(char *file, t_game *game);
void	ft_fill_map(t_game *game, int count);
int		check_file_name(char *file);
char	**ft_malloc_map(t_game *game);
void	ft_check_fill_map(char	**tab, int count, int *k, int *j);
void	ft_free_map(t_game *game, char **tab);
int		ft_is_xpm(char **tab);
int		ft_check_wall_3(t_game *game, int i, int j);

/************* INIT ************/
void	ft_init(t_raycast	*raycast);
void	ft_init_2(t_game	*game);
char	**ft_fill_map_2(char	**map);
char	**fill_array(char	*file, t_game	*game);
void	ft_start(t_game	*game);
void	get_identifier(char	*line, t_game	*game);

/********* RAYCASTING *********/
int		ft_raycasting(t_game	*game, t_raycast	*raycast);
void	ft_put_color(t_game	*game, t_raycast	*raycast);
void	ft_get_texture(t_game	*game);

/*********** MOVES ***********/
void	ft_forward_back(t_game *game, t_raycast	*raycast);
void	ft_left_right(t_game *game, t_raycast	*raycast);
void	ft_swap_img(t_game	*game);
void	ft_rot_right(t_game *game, t_raycast	*raycast);
void	ft_rot_left(t_game *game, t_raycast	*raycast);
void	ft_loop_hook(t_game	*game);
void	ft_print_map(char	**map);

#endif