#include "../../includes/cub_3d.h"

void	ft_forward(t_game *game, t_raycast	*raycast)
{
	(void)game;
	if (game->mv_forward == 1)
		printf("move forward");
	if (game->mv_forward == 1)
	{
		if (game->array[(int)(raycast->charpos_x_2 + (raycast->dirx * raycast->
							movespeed * 2))][(int)raycast->charpos_y_2] == '0')
			raycast->charpos_x_2 += raycast->dirx * raycast->movespeed;
		if (game->array[(int)(raycast->charpos_x_2)][(int)(raycast->charpos_y_2 +
							(raycast->diry * raycast->movespeed * 2))] == '0')
			raycast->charpos_y_2 += raycast->diry * raycast->movespeed;
	}
}

void	ft_swap_img(t_game	*game)
{
	void	*temp;

	temp = game->img;
	game->img = game->img_2;
	game->img_2 = temp;
	temp = game->address;
	game->address = game->address_2;
	game->address_2 = temp;
}