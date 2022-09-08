#include "../../includes/cub_3d.h"

void	ft_forward_back(t_game *game, t_raycast	*raycast)
{
	if (game->mv_forward == 1)
	{
		if (game->array[(int)(raycast->charpos_x_2 + (raycast->dirx *
					raycast->movespeed * 2))][(int)raycast->charpos_y_2] == '0')
		{
			raycast->charpos_x_2 += raycast->dirx * raycast->movespeed;
		}	
		if (game->array[(int)(raycast->charpos_x_2)][(int)(raycast->charpos_y_2 +
							(raycast->diry * raycast->movespeed * 2))] == '0')
		{
			raycast->charpos_y_2 += raycast->diry * raycast->movespeed;
		}
	}
	else if (game->mv_back == 1)
	{
		if (game->array[(int)(raycast->charpos_x_2 - (raycast->dirx *
					raycast->movespeed * 2))][(int)raycast->charpos_y_2] == '0')
		{
			raycast->charpos_x_2 -= raycast->dirx * raycast->movespeed;
		}	
		if (game->array[(int)(raycast->charpos_x_2)][(int)(raycast->charpos_y_2 -
							(raycast->diry * raycast->movespeed * 2))] == '0')
		{
			raycast->charpos_y_2 -= raycast->diry * raycast->movespeed;
		}
	}
}

void	ft_left_right(t_game *game, t_raycast	*raycast)
{
	if (game->mv_right == 1)
	{
		if (game->array[(int)(raycast->charpos_x_2 + (raycast->diry *
					raycast->movespeed * 2))][(int)raycast->charpos_y_2] == '0')
		{
			raycast->charpos_x_2 += raycast->diry * raycast->movespeed;
		}	
		if (game->array[(int)(raycast->charpos_x_2)][(int)(raycast->charpos_y_2 -
							(raycast->dirx * raycast->movespeed * 2))] == '0')
		{
			raycast->charpos_y_2 += raycast->dirx * raycast->movespeed;
		}
	}
	else if (game->mv_left == 1)
	{
		if (game->array[(int)(raycast->charpos_x_2 - (raycast->diry *
					raycast->movespeed * 2))][(int)raycast->charpos_y_2] == '0')
		{
			raycast->charpos_x_2 -= raycast->diry * raycast->movespeed;
		}	
		if (game->array[(int)(raycast->charpos_x_2)][(int)(raycast->charpos_y_2 +
							(raycast->dirx * raycast->movespeed * 2))] == '0')
		{
			raycast->charpos_y_2 -= raycast->dirx * raycast->movespeed;
		}
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