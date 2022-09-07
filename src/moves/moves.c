#include "../../includes/cub_3d.h"

void	ft_forward(t_game *game, t_raycast	*raycast)
{
	printf("test move forward\n");
	if (game->mv_forward == 1)
	{
		printf("test\n");
		printf("(int)(raycast->charpos_x_2: %d\n", (int)raycast->charpos_x_2);
		printf("raycast->dirx: %d\n", (int)raycast->dirx);
		printf("raycast->movespeed: %d\n", (int)raycast->movespeed);
		printf("(int)raycast->charpos_y_2: %d\n", (int)raycast->charpos_y_2);

		printf("res array: %c\n", game->array[2 + (0 * 0 * 2)][1]);

		if (game->array[(int)(raycast->charpos_x_2 + (raycast->dirx *
					raycast->movespeed * 2))][(int)raycast->charpos_y_2] == '0')
		{
			printf("i m in\n");
			raycast->charpos_x_2 += raycast->dirx * raycast->movespeed;
		}	
		if (game->array[(int)(raycast->charpos_x_2)][(int)(raycast->charpos_y_2 +
							(raycast->diry * raycast->movespeed * 2))] == '0')
		{
			printf("i m in 2\n");
			raycast->charpos_y_2 += raycast->diry * raycast->movespeed;
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