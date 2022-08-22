#include "../../includes/cub_3d.h"

void	ft_init_raycast(t_game	*game, t_raycast	*raycast)
{
	raycast->camerax = 2 * raycast->x / (double)game->res_x - 1;
	raycast->raydirx = raycast->raydirx + raycast->planx * raycast->camerax;
	raycast->raydiry = raycast->raydiry + raycast->plany * raycast->camerax;
	// raycast->movespeed = 0.1;		//a refaire
	// raycast->rotspeed = 0.033 * 1.8; //a refaire
	if(raycast->raydiry == 0)
		raycast->deltadistx = 0;
	else if(raycast->raydirx == 0)
		raycast->deltadistx = 1;
	else
		raycast->deltadistx = sqrt(1 + (raycast->raydiry
			* raycast->raydiry) / (raycast->raydirx *
			raycast->raydirx));
	if(raycast->raydirx == 0)
		raycast->deltadisty = 0;
	else if(raycast->raydiry == 0)
		raycast->deltadisty = 1;
	else
		raycast->deltadisty = sqrt(1 + (raycast->raydirx
			* raycast->raydirx) / (raycast->raydiry *
			raycast->raydiry));
}

void	ft_raycasting(t_game	*game, t_raycast	*raycast)
{
	(void)game;
	printf("raycasting starts\n");
	raycast->charpos_x_2 = (double)raycast->char_pos_x + 0.5;
	raycast->charpos_y_2 = (double)raycast->char_pos_y + 0.5;
	printf("charpos_x_2: %f\n", raycast->charpos_x_2);
	printf("charpos_y 2: %f\n", raycast->charpos_y_2);
	
	raycast->x = 0;

	while (raycast->x < game->res_x)
	{
		ft_init_raycast(game, raycast);
		raycast->x++;
	}
	mlx_put_image_to_window(game->mlx, game->mlx_win,
					game->image.wall, 0, 0);
}