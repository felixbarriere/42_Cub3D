#ifndef CUB_3D_H
# define CUB_3D_H

#include <unistd.h>
#include <math.h>
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
	void		*floor;
}	t_image;

typedef struct s_raycast
{
	int			char_pos_x;		//position x du joueur
	int			char_pos_y;		//position y du joueur
	double		charpos_x_2;
	double		charpos_y_2;
	double		dirx; 			//vecteur de direction (commence à -1 pour N, 1 pour S, 0 sinon)
	double		diry; 			//vecteur de direction (commence à -1 pour W, 1 pour E, 0 sinon)
	double		planx;			//vecteur du plan (commence à 0.66 pour E, -0.66 pour W, 0 sinon)
	double		plany; 			//vecteur du plan (commence à 0.66 pour N, -0.66 pour S, 0 sinon)
	double		raydirx;	 	//calcul de direction x du rayon
	double		raydiry; 		//calcul de direction y du rayon
	double		camerax; 		//point x sur la plan camera : Gauche ecran = -1, milieu = 0, droite = 1
	int			mapx;			// coordonée x du carré dans lequel est le rayon
	int			mapy; 			// coordonnée y du carré dans lequel est le rayon
	double		sidedistx;	//distance que le rayon parcours jusqu'au premier point d'intersection x
	double		sidedisty;	//distance que le rayon parcours jusqu'au premier point d'intersection horizontal
	double		deltadistx; //distance que rayon parcours entre chaque point d'intersection vertical
	double		deltadisty; //distance que le rayon parcours entre chaque point d'intersection horizontal
	int			stepx; 		// -1 si doit sauter un carre dans direction x negative, 1 dans la direction x positive
	int			stepy; 		// -1 si doit sauter un carre dans la direction y negative, 1 dans la direction y positive
	int			hit; 		// 1 si un mur a ete touche, 0 sinon
	int			side; 		// 0 si c'est un cote x qui est touche (vertical), 1 si un cote y (horizontal)
	double		perpwalldist; 	// distance du joueur au mur perpendiculaire
	int			lineheight; 	//hauteur de la ligne a dessiner
	int			drawstart;	 //position de debut ou il faut dessiner
	int			drawend; 	//position de fin ou il faut dessiner
	double		movespeed;
	double		rotspeed;
	int			x; 			//permet de parcourir tous les rayons
}	t_raycast;

typedef struct		s_texture
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
	char		*address;
	int			line_length;
	int			bits_per_pixel;
	int			endian;
	int			height;
	int			width;
	void		*img;
	
}		t_game_2;

typedef struct s_game {
	char		*address;
	char		*address_2;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	void		*mlx;
	void		*mlx_win;
	void		*img;
	void		*img_2;
	char		**array;
	int			y_size;
	int			x_size;
	int			res_x;
	int			res_y;
	char		*north_id;
	char		*south_id;
	char		*east_id;
	char		*west_id;
	char		*floor_id;
	char		*ceilling_id;
	int			floor_RGB;
	int			ceilling_RGB;
	// void		*wall_img;
	t_image		image;
	t_raycast	raycast;
	t_game_2	texture[4];
	t_texture	t;
}				t_game;


char	**fill_array(char	*file, t_game	*game);
void	ft_start(t_game	*game);
void	get_identifier(char	*line, t_game	*game);
void	ft_fill_flo(t_game	*game, int x, int y, char **tab);

/*********** FREE ***********/
void	ft_free_array(char **array);
void	ft_free_all(t_game	*game);

/*********** UTILS ***********/
void	*ft_img(void *mlx, char *path);
int		ft_elt_pos_x(char	**array);
int		ft_elt_pos_y(char	**array);
int		ft_get_max_y(char	**array);
int		ft_get_max_x(char	**array);
int		ft_close_cross(t_game	*game);
int		ft_close_esc(int keycode, t_game	*game);
int		ft_atoi_color(char *str);

/*********** LIBFT ***********/
char	*ft_strdup(char *src);
int		ft_strncmp(char *s1, char *s2, int n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero( void *pointer, size_t count );
// int	ft_strlen(char *str);

/********* RAYCASTING *********/
int		ft_raycasting(t_game	*game, t_raycast	*raycast);
void	ft_put_color(t_game	*game, t_raycast	*raycast);
void	ft_get_texture(t_game	*game);

#endif