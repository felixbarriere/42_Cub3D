#include "../../includes/cub_3d.h"

void	ft_init_raycast(t_game	*game, t_raycast	*raycast)
{
	raycast->hit = 0;
	raycast->perpwalldist = 0;
	// printf("raycast->x init: %d\n", raycast->x);
	// printf("(double)game->res_x init: %f\n", (double)game->res_x);

	raycast->camerax = 2 * raycast->x / (double)game->res_x - 1;
	// printf("raycast->raydiry init: %f\n", raycast->raydiry);
	// printf("raycast->raydirx init: %f\n",raycast->raydirx);
	// printf("raycast->planx: %f\n",raycast->planx);
	// printf("raycast->plany: %f\n", raycast->plany);
	// printf("raycast->camerax: %f\n", raycast->camerax);
	raycast->raydirx = raycast->dirx + raycast->planx * raycast->camerax;
	raycast->raydiry = raycast->diry + raycast->plany * raycast->camerax;
	// printf("raycast->raydiry : %f\n", raycast->raydiry);
	// printf("raycast->raydirx : %f\n",raycast->raydirx);
	// raycast->movespeed = 0.1;		//a refaire
	// raycast->rotspeed = 0.033 * 1.8; //a refaire
	raycast->mapx = (int)raycast->charpos_x_2;
	raycast->mapy = (int)raycast->charpos_y_2;
	// printf("(double)raycast->mapx init: %f\n", (double)raycast->mapx);
	// printf("(double)raycast->mapy init: %f\n", (double)raycast->mapy);
	if (raycast->raydiry == 0)
		raycast->deltadistx = 0;
	else if (raycast->raydirx == 0)
		raycast->deltadistx = 1;
	else
		raycast->deltadistx = sqrt(1 + (raycast->raydiry
			* raycast->raydiry) / (raycast->raydirx *
			raycast->raydirx));
	if (raycast->raydirx == 0)
		raycast->deltadisty = 0;
	else if (raycast->raydiry == 0)
		raycast->deltadisty = 1;
	else
		raycast->deltadisty = sqrt(1 + (raycast->raydirx
			* raycast->raydirx) / (raycast->raydiry *
			raycast->raydiry));
}

void	ft_calculate_height(t_game	*game, t_raycast	*raycast)
{
	// perpwalldist est perpendiculaire au plane et s'arrrete lors d'un hit.
	// Il permet d'eviter d'utiliser la distance euclidienne et l'effet fisheye.
	// printf("(double)raycast->mapx init: %f\n", (double)raycast->mapx);
	// printf("raycast->charpos_x_2: %f\n", raycast->charpos_x_2);
	// printf("(double)raycast->stepx init: %f\n", (double)raycast->stepx);
	// printf("raycast->raydirx: %f\n", raycast->raydirx); //KO
	if (raycast->side == 0)
		raycast->perpwalldist = ((double)raycast->mapx - raycast->charpos_x_2
					+ (1 - (double)raycast->stepx) / 2) / raycast->raydirx;
	else
		raycast->perpwalldist = ((double)raycast->mapy - raycast->charpos_y_2
					+ (1 - (double)raycast->stepy) / 2) / raycast->raydiry;
	// printf("raycast->perpwalldist apres calcul: %f\n", raycast->perpwalldist);
	// calcul de la taille de la colonne
	raycast->lineheight = (int)(game->res_y / raycast->perpwalldist);
	raycast->drawstart = -raycast->lineheight / 2
			+ game->res_y / 2;
	if (raycast->drawstart < 0)
		raycast->drawstart = 0;
	raycast->drawend = raycast->lineheight / 2 + game->res_y / 2;
	if (raycast->drawend >= game->res_y || raycast->drawend < 0)
		raycast->drawend = game->res_y - 1;
	// printf("raycast->lineheight: %d\n", raycast->lineheight);
	// printf("raycast->drawend: %d\n", raycast->drawend);
	// printf("raycast->drawstart: %d\n", raycast->drawstart);
}

void	ft_perform_DDA(t_game	*game, t_raycast	*raycast)
{
	while (raycast->hit == 0)
	{
		if (raycast->sidedistx < raycast->sidedisty)
		{
			raycast->sidedistx += raycast->deltadistx;
			raycast->mapx += raycast->stepx;
			raycast->side = 0;
		}
		else
		{
			raycast->sidedisty += raycast->deltadisty;
			raycast->mapy += raycast->stepy;
			raycast->side = 1;
		}
		// printf("raycast->stepx: %d\n", raycast->stepx);   //KO!
		// printf("raycast->stepy: %d\n", raycast->stepy);
		// printf("(double)raycast->mapx 2: %f\n", (double)raycast->mapx);
		// printf("(double)raycast->mapy 2: %f\n", (double)raycast->mapy);
		if (game->array[raycast->mapx][raycast->mapy] == '1')
		{
			printf("hit\n");
			raycast->hit = 1;
		}
	}
	ft_calculate_height(game, raycast);
}

void	ft_calculate_sidedist(t_game	*game, t_raycast	*raycast)
{
	// printf("raycast->raydirx: %f\n", raycast->raydirx);
	if (raycast->raydirx < 0)
	{
		raycast->stepx = -1;
		raycast->sidedistx = (raycast->charpos_x_2 - raycast->mapx)
									* raycast->deltadistx;
	}
	else
	{
		raycast->stepx = 1;
		raycast->sidedistx = (raycast->mapx + 1.0 - raycast->charpos_x_2)
									* raycast->deltadistx;
	}
	if (raycast->diry < 0)
	{
		raycast->stepy = -1;
		raycast->sidedisty = (raycast->charpos_y_2 - raycast->mapy)
									* raycast->deltadisty;
	}
	else
	{
		raycast->stepy = 1;
		raycast->sidedisty = (raycast->mapy + 1 - raycast->charpos_y_2)
									* raycast->deltadisty;
	}
	ft_perform_DDA(game, raycast); //incrémente de carré en carré (en direction x ou y) jusqu'à toucher un mur
}

int	ft_raycasting(t_game	*game, t_raycast	*raycast)
{
	// printf("raycasting starts\n");

	// while (raycast->x < 2050)
	while (raycast->x < game->res_x)
	{
		ft_init_raycast(game, raycast); //calcule camerax, raydir et deltadist (distance entre chaque point d'intersection vert/hor) 
		ft_calculate_sidedist(game, raycast); //distance du rayon jusqu'au premier point d'intersection x/y
		ft_put_color(game, raycast);
		// printf("raycast->x: %d\n", raycast->x);
		// printf("raycast->charpos_x_2: %f\n", raycast->charpos_x_2);   //ok
		// printf("raycast->charpos_y_2: %f\n", raycast->charpos_y_2);
		// printf("(double)raycast->mapx final: %f\n", (double)raycast->mapx); //ok
		// printf("(double)raycast->mapy final: %f\n", (double)raycast->mapy);  //ok
		// printf("(double)raycast->stepx): %f\n", (double)raycast->stepx);  //ok
		// printf("raycast->raydiry init: %f\n", raycast->raydiry);   //ok
		// printf("raycast->raydirx init: %f\n",raycast->raydirx);    //ok
		// printf("raycast->camerax: %f\n", raycast->camerax);		   //ok
		// printf("raycast->dirx: %f\n", raycast->dirx);			   //ok
		// printf("raycast->diry: %f\n", raycast->diry);			   //ok
		// printf("raycast->deltadistx: %f\n", raycast->deltadistx);	   //ok
		// printf("raycast->deltadisty: %f\n", raycast->deltadisty);	   //ok
		// printf("game->t.wall_x: %f\n", game->t.wall_x); 				   //ok
		// printf("raycast->perpwalldist apres calcul: %f\n", raycast->perpwalldist);   //ok
		raycast->x++;
	}
	mlx_put_image_to_window(game->mlx, game->mlx_win,
					game->img, 0, 0);
	return (0);
}