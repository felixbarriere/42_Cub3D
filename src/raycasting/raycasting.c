#include "../../includes/cub_3d.h"

void	ft_init_raycast(t_game	*game, t_raycast	*raycast)
{
	raycast->perpwalldist = 0;
	raycast->camerax = 2 * raycast->x / (double)game->res_x - 1;
	raycast->raydirx = raycast->dirx + raycast->planx * raycast->camerax;
	raycast->raydiry = raycast->diry + raycast->plany * raycast->camerax;
	// raycast->movespeed = 0.1;		//a refaire
	// raycast->rotspeed = 0.033 * 1.8; //a refaire
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
	if (raycast->side == 0)
		raycast->perpwalldist = ((double)raycast->mapx - raycast->charpos_x_2
					+ (1 - (double)raycast->stepx) / 2) / raycast->raydirx;
	else
		raycast->perpwalldist = ((double)raycast->mapy - raycast->charpos_y_2
					+ (1 - (double)raycast->stepy) / 2) / raycast->raydiry;
	
	// calcul de la taille de la colonne
	raycast->lineheight = (int)(game->res_y / raycast->perpwalldist);
	raycast->drawstart = -raycast->lineheight / 2
			+ game->res_y / 2;
	if (raycast->drawstart < 0)
		raycast->drawstart = 0;
	raycast->drawend = raycast->lineheight / 2 + game->res_y / 2;
	if (raycast->drawend >= game->res_y || raycast->drawend < 0)
		raycast->drawend = game->res_y - 1;
	printf("raycast->lineheight: %d\n", raycast->lineheight);
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
		if (game->array[raycast->mapx][raycast->mapy] == '1')
		{
			// printf("hit\n");
			raycast->hit = 1;
		}
	}
	ft_calculate_height(game, raycast);
}

void	ft_calculate_sidedist(t_game	*game, t_raycast	*raycast)
{
	if (raycast->raydirx < 0)
	{
		raycast->stepx = -1;
		raycast->sidedistx = (raycast->char_pos_x - raycast->mapx)
									* raycast->deltadistx;
	}
	else
	{
		raycast->stepx = 1;
		raycast->sidedistx = (raycast->mapx + 1.0 - raycast->char_pos_x)
									* raycast->deltadistx;
	}
	if (raycast->diry < 0)
	{
		raycast->stepy = -1;
		raycast->sidedisty = (raycast->char_pos_y - raycast->mapy)
									* raycast->deltadisty;
	}
	else
	{
		raycast->stepy = 1;
		raycast->sidedisty = (raycast->mapy + 1 - raycast->char_pos_y)
									* raycast->deltadisty;
	}
	ft_perform_DDA(game, raycast); //incrémente de carré en carré (en direction x ou y) jusqu'à toucher un mur
}

int	ft_raycasting(t_game	*game, t_raycast	*raycast)
{
	printf("raycasting starts\n");
	
	// while (raycast->x < game->res_x)
	while (raycast->x < 3)
	{
		ft_init_raycast(game, raycast); //calcule camerax, raydir et deltadist (distance entre chaque point d'intersection vert/hor) 
		ft_calculate_sidedist(game, raycast); //distance du rayon jusqu'au premier point d'intersection x/y
		raycast->x++;
	}
	mlx_put_image_to_window(game->mlx, game->mlx_win,
					game->img, 0, 0);
	return (0);
}