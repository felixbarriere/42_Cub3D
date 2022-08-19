#include "../includes/cub_3d.h"

int	ft_close_cross(t_game	*game)
{
	printf ("Closing game");
	mlx_destroy_window(game->mlx, game->mlx_win);
	exit(0);
}

int	ft_close_esc(int keycode, t_game	*game)
{
	if (keycode == 1) // trouver le bon keycode pour linux
	{
		printf ("Closing game");
		mlx_destroy_window (game->mlx, game->mlx_win);
		exit(0);
	}
	return (0);
}

void		ft_vector_dir(t_game	*game, char	**array)
{
	if (array[game->raycast.char_pos_y][game->raycast.char_pos_x] == 'N')
	{
		game->raycast.dirx = 0;
		game->raycast.diry = -1;
		printf("char_orientation: %c\n", array[game->raycast.char_pos_y][game->raycast.char_pos_x]);
	}
	else if (array[game->raycast.char_pos_y][game->raycast.char_pos_x] == 'S')
	{
		game->raycast.dirx = -1;
		game->raycast.diry = 0;
		printf("char_orientation: %c\n", array[game->raycast.char_pos_y][game->raycast.char_pos_x]);
	}
	else if (array[game->raycast.char_pos_y][game->raycast.char_pos_x] == 'W')
	{
		game->raycast.dirx = -1;
		game->raycast.diry = 0;
		printf("char_orientation: %c\n", array[game->raycast.char_pos_y][game->raycast.char_pos_x]);
	}
	else if (array[game->raycast.char_pos_y][game->raycast.char_pos_x] == 'E')
	{
		game->raycast.dirx = 0;
		game->raycast.diry = -1;
		printf("char_orientation: %c\n", array[game->raycast.char_pos_y][game->raycast.char_pos_x]);
	}
}

void	ft_init_global(t_game	*game)
{
	game->y_size = ft_get_max_y(game->array);
	game->x_size = ft_get_max_x(game->array);
	game->raycast.char_pos_x = ft_elt_pos_x(game->array);
	game->raycast.char_pos_y = ft_elt_pos_y(game->array);
	printf("char_pos_x: %d\n", game->raycast.char_pos_x);
	printf("char_pos_y: %d\n", game->raycast.char_pos_y);
	ft_vector_dir(game, game->array);


	game->mlx = mlx_init();
	game->image.wall = ft_img(game->mlx, "img/wall.xpm");
	game->image.floor = ft_img(game->mlx, "img/floor.xpm");
	game->mlx_win = mlx_new_window(game->mlx, game->x_size * 64,
						game->y_size * 64, "Cub3D");
	game->img = mlx_new_image(game->mlx, game->x_size * 64, game->y_size * 64);
	game->address = mlx_get_data_addr(game->img, &game->bits_per_pixel,
							&game->line_length, &game->endian);
}

void	ft_init(t_game	*game)
{
	ft_init_global(game);
	ft_fill_flo(game,  game->x_size,  game->y_size, game->array);

	mlx_hook(game->mlx_win, 2, 1L << 0, ft_close_esc, game);
	mlx_hook(game->mlx_win, 17, 0L, ft_close_cross, game);
	mlx_loop(game->mlx);
	

	free(game->mlx);
	free(game->mlx_win);
}










// my_mlx_pixel_put(game, 44, 44, 0x00FF0000);
// my_mlx_pixel_put(game, 55, 55, 0x00FF0000);
// my_mlx_pixel_put(game, 66, 66, 0x00FF0000);
// mlx_put_image_to_window(game->mlx, game->mlx_win, game->img, 5, 5);
// void	ft_init(t_game	game)
// {
// 	// ft_init_2(game);
// 	game.image.mlx = mlx_init();
// 	game.image.wall_img = ft_img(game.image.mlx, "../wall.xpm");
// 	game.image.mlx_win = mlx_new_window(game.image.mlx, 2000, 1000, "Cub3D");
// 	// game.img = mlx_new_image(game.mlx, 1500, 800);
// 	// game.address = mlx_get_data_addr(game.img, &game.bits_per_pixel,
// 	// 						&game.line_length,&game.endian);

// 	mlx_put_image_to_window(game.image.mlx, game.image.mlx_win,
// 					game.image.wall_img, 1 * 64, 1 * 64);


// 	// ft_fill_flo(game, 11, 3, game->array);

// 	// mlx_hook(game.mlx_win, 2, 1L << 0, ft_close_esc, &game);
// 	// mlx_hook(game.mlx_win, 17, 0L, ft_close_cross, &game);
	
// 	// mlx_loop(game.mlx);

// 	free(game.image.mlx);
// 	free(game.image.mlx_win);
// 	free(game.image.wall_img);
// }