#include "../../includes/cub_3d.h"

void	ft_get_texture_add(t_game	*game)
{
	// game->texture[0].address = NULL;
	// if (game->texture[0].img)
	// 	printf("img OK\n");
	// else
	// 	printf("img KO 2\n");
	// printf("game->north_id: %s", game->north_id);
	
	game->texture[0].address = mlx_get_data_addr(game->texture[0].img,
			&(game->texture[0].bits_per_pixel),
			&(game->texture[0].line_length), &(game->texture[0].endian));
	game->texture[1].address = mlx_get_data_addr(game->texture[1].img,
			&game->texture[1].bits_per_pixel,
			&game->texture[1].line_length, &game->texture[1].endian);
	game->texture[2].address = mlx_get_data_addr(game->texture[2].img,
			&game->texture[2].bits_per_pixel,
			&game->texture[2].line_length, &game->texture[2].endian);
	game->texture[3].address = mlx_get_data_addr(game->texture[3].img,
			&game->texture[3].bits_per_pixel,
			&game->texture[3].line_length, &game->texture[3].endian);
}

void	ft_init_texture_2(t_game	*game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		game->texture[i].img = NULL;
		game->texture[i].width = 0;
		game->texture[i].height = 0;
		game->texture[i].bits_per_pixel = 0;
		game->texture[i].line_length = 0;
		game->texture[i].endian = 0;
		i++;
	}
}

void	ft_get_texture(t_game	*game)
{
	ft_init_texture_2(game);

	// printf("game->texture[0].width:%d\n", game->texture[0].width);
	// printf("game->texture[0].height:%d\n", game->texture[0].height);
	if (!(game->texture[0].img = mlx_xpm_file_to_image(game->mlx,
					game->north_id, &(game->texture[0].width),
					&(game->texture[0].height))))
		printf("img NO KO\n");



	if (!(game->texture[1].img = mlx_xpm_file_to_image(game->mlx,
					"./img/wall.xpm", &game->texture[1].width,
					&game->texture[1].height)))
		printf("img SO KO\n");
	game->texture[2].img = mlx_xpm_file_to_image(game->mlx,
					game->west_id, &game->texture[2].width,
					&game->texture[2].height);
	game->texture[3].img = mlx_xpm_file_to_image(game->mlx,
					game->east_id, &game->texture[3].width,
					&game->texture[3].height);
	//mettre "&" dans les parentheses?
	ft_get_texture_add(game);
}