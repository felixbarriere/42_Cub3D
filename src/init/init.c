#include "../../includes/cub_3d.h"

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

void	ft_fill_dir_plane(int	dir_zero, int	neg_one, int	one, int plan_zero)
{
	dir_zero = 0;
	neg_one = -1;
	one = 1;
	plan_zero = 0;
	(void)dir_zero;
	(void)neg_one;
	(void)one;
	(void)plan_zero;
}

void		ft_vector_dir(t_game	*game, char	**array)
{
	if (array[game->raycast.char_pos_y][game->raycast.char_pos_x] == 'N')
	{
		ft_fill_dir_plane(game->raycast.diry, game->raycast.dirx, 1,
									game->raycast.planx);
		game->raycast.plany = 0.66;
	}
	else if (array[game->raycast.char_pos_y][game->raycast.char_pos_x] == 'S')
	{
		ft_fill_dir_plane(game->raycast.diry, -1, game->raycast.dirx,
									game->raycast.planx);
		game->raycast.plany = -0.66;
	}
	else if (array[game->raycast.char_pos_y][game->raycast.char_pos_x] == 'W')
	{
		ft_fill_dir_plane(game->raycast.dirx, game->raycast.diry, 1,
									game->raycast.plany);
		game->raycast.planx = -0.66;
	}
	else if (array[game->raycast.char_pos_y][game->raycast.char_pos_x] == 'E')
	{
		ft_fill_dir_plane(game->raycast.dirx, -1, game->raycast.diry,
									game->raycast.plany);
		game->raycast.planx = 0.66;
	}
}

void	ft_init_global(t_game	*game)
{
	game->x_size = ft_get_max_x(game->array);
	game->y_size = ft_get_max_y(game->array);
	game->res_x = game->x_size * 64;
	game->res_y = game->y_size * 64;
	game->raycast.char_pos_x = ft_elt_pos_x(game->array);
	game->raycast.char_pos_y = ft_elt_pos_y(game->array);
	printf("char_pos_x: %d\n", game->raycast.char_pos_x);
	printf("char_pos_y: %d\n", game->raycast.char_pos_y);
	ft_vector_dir(game, game->array);

	game->mlx = mlx_init();
	game->image.wall = ft_img(game->mlx, "img/wall.xpm");
	game->image.floor = ft_img(game->mlx, "img/floor.xpm");
	game->mlx_win = mlx_new_window(game->mlx, game->res_x,
						game->res_y, "Cub3D");
	game->img = mlx_new_image(game->mlx, game->res_x, game->res_y);
	game->address = mlx_get_data_addr(game->img, &game->bits_per_pixel,
							&game->line_length, &game->endian);
}

void	ft_init(t_game	*game)
{
	ft_init_global(game);

	ft_raycasting(game, &game->raycast);
	// ft_fill_flo(game,  game->x_size,  game->y_size, game->array); // a enlever avant la 3D
	
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