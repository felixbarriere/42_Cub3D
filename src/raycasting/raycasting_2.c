#include "../../includes/cub_3d.h"

void	ft_init_texture(t_game	*game, t_raycast	*raycast)
{
	// game->t.step = 0;
	// game->t.tex_x = 0;
	// game->t.tex_y = 0;
	// game->t.tex_pos = 0;
	if (raycast->side == 0 && raycast->raydirx < 0)
		game->t.tex_dir = 0;
	if (raycast->side == 0 && raycast->raydirx >= 0)
		game->t.tex_dir = 1;
	if (raycast->side == 1 && raycast->raydiry < 0)
		game->t.tex_dir = 2;
	if (raycast->side == 1 && raycast->raydiry >= 0)
		game->t.tex_dir = 3;
	// printf("raycast->charpos_y_2: %f\n", raycast->charpos_y_2); //OK
	// printf("raycast->charpos_x_2: %f\n", raycast->charpos_x_2); //OK
	// printf("raycast->perpwalldist init: %f\n", raycast->perpwalldist);  //KO pas du tout 
	// printf("raycast->raydiry init: %f\n", raycast->raydiry);
	// printf("raycast->raydirx init: %f\n",raycast->raydirx);
	if (raycast->side == 0)
		game->t.wall_x = raycast->charpos_y_2 + raycast->perpwalldist \
						* raycast->raydiry;
	else
		game->t.wall_x =  raycast->charpos_x_2 +  raycast->perpwalldist \
						*  raycast->raydirx;
	game->t.wall_x -= floor((game->t.wall_x));
	// printf("game->t.wall_x: %f\n", game->t.wall_x);
	game->t.step = 0;
}

void	ft_draw_texture(t_game	*game, t_raycast	*raycast, int	x, int	y)
{
	// (void)x;
	y = raycast->drawstart - 1;
	// (void)y;
	ft_init_texture(game, raycast);
	// printf("game->t.tex_x : %d\n",game->t.tex_x);
	// printf("game->t.tex_dir : %d\n", game->t.tex_dir); //1
	// printf("game->texture[game->t.tex_dir].width : %d\n", game->texture[game->t.tex_dir].width); //ok
	// printf("game->t.wall_x: %f\n", game->t.wall_x);  //KO trouver l'erreur de calcul
	game->t.step = 1.0 * game->texture[0].height / raycast->lineheight;
	game->t.tex_x = (int)(game->t.wall_x * (double)game->texture
			[game->t.tex_dir].width);
	if (raycast->side == 0 && raycast->raydirx > 0)
		game->t.tex_x = game->texture[game->t.tex_dir].width -
			game->t.tex_x - 1;
	if (raycast->side == 1 && raycast->raydiry < 0)   // a integrer dans la condition d'avant
		game->t.tex_x = game->texture[game->t.tex_dir].width -
			game->t.tex_x - 1;
	game->t.tex_pos = (raycast->drawstart - game->res_y / 2 +
			raycast->lineheight / 2) * game->t.step;
	// printf("game->t.tex_x2 : %d\n",game->t.tex_x);
	while (++y <= raycast->drawend)
	{
		game->t.tex_y = (int)game->t.tex_pos &
			(game->texture[game->t.tex_dir].height - 1);
		game->t.tex_pos += game->t.step;
		if (y < game->res_y && x < game->res_x)
			game->address[y * game->line_length / 4 + x] =
				game->texture[game->t.tex_dir].address[game->t.tex_y *
					game->texture[game->t.tex_dir].line_length /
					4 + game->t.tex_x];
	}
}

void	ft_put_color(t_game	*game, t_raycast	*raycast)
{
	// printf("put color\n");
	int j;
	int i;

	// on part du ceilling jusqu'à la colonne, puis de la colonne jusqu'au floor
	// en envoyant les couleurs(C/F)/textures(murs) correspondantes

	//creer une fonction renvoyant un nombre unique pour les couleurs floor et ceiling
	// transformer le char * en un int (en concatenant + enlever espaces et virg)
	
	// printf("game->floor_RGB: %d\n", game->floor_RGB);
	// printf("game->ceilling_RGB: %d\n", game->ceilling_RGB);
	
	j = -1;
	raycast->drawend = game->res_y - raycast->drawstart;
	i = raycast->drawend;
	while (++j < raycast->drawstart)
		game->address[j * game->line_length / 4 + raycast->x]
								= game->ceilling_RGB;
	if (j <= raycast->drawend)
		ft_draw_texture(game, raycast, raycast->x, j);
	j = i;
	while (++j < game->res_y)
		game->address[j * game->line_length / 4 + raycast->x]
								= game->floor_RGB;
}