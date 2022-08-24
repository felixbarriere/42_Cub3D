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

void		ft_vector_dir(t_raycast	*raycast, char	**array)
{
	if (array[raycast->char_pos_x][raycast->char_pos_y] == 'N')
	{
		ft_fill_dir_plane(raycast->diry, raycast->dirx, 1, raycast->planx);
		raycast->plany = 0.66;
		raycast->dirx = -1;
	}
	else if (array[raycast->char_pos_x][raycast->char_pos_y] == 'S')
	{
		ft_fill_dir_plane(raycast->diry, -1, raycast->dirx, raycast->planx);
		raycast->plany = -0.66;
		raycast->dirx = 1;
	}
	else if (array[raycast->char_pos_x][raycast->char_pos_y] == 'W')
	{
		ft_fill_dir_plane(raycast->dirx, raycast->diry, 1, raycast->plany);
		raycast->planx = -0.66;
		raycast->diry = -1;
	}
	else if (array[raycast->char_pos_x][raycast->char_pos_y] == 'E')
	{
		ft_fill_dir_plane(raycast->dirx, -1, raycast->diry, raycast->plany);
		raycast->planx = 0.66;
		raycast->diry = 1;
	}
}

void	ft_init_2(t_game	*game)
{
	game->mlx = mlx_init();
	mlx_get_screen_size(game->mlx, &game->x_size, &game->y_size);
	game->res_x = game->x_size;
	game->res_y = game->y_size;
	// attention: worldMap[mapWidth][mapHeight] (inverser x et y);
	game->raycast.char_pos_y = ft_elt_pos_x(game->array);
	game->raycast.char_pos_x = ft_elt_pos_y(game->array);
	game->raycast.charpos_x_2 = (double)game->raycast.char_pos_x + 0.5;
	game->raycast.charpos_y_2 = (double)game->raycast.char_pos_y + 0.5;	
	game->raycast.mapx = (int)game->raycast.charpos_x_2;
	game->raycast.mapy = (int)game->raycast.charpos_y_2;
	ft_vector_dir(&game->raycast, game->array);

	game->image.wall = ft_img(game->mlx, "img/wall.xpm");
	game->image.floor = ft_img(game->mlx, "img/floor.xpm");
	game->mlx_win = mlx_new_window(game->mlx, game->res_x,
						game->res_y, "Cub3D");
	game->img = mlx_new_image(game->mlx, game->res_x, game->res_y);
	game->address = mlx_get_data_addr(game->img, &game->bits_per_pixel,
							&game->line_length, &game->endian);
}

void	ft_init(t_raycast	*raycast)
{
	raycast->char_pos_x = 0;
	raycast->char_pos_y = 0;
	raycast->dirx = 0;
	raycast->diry = 0;
	raycast->planx = 0;
	raycast->plany = 0;
	raycast->raydirx = 0;
	raycast->raydiry = 0;
	raycast->camerax = 0;
	raycast->sidedistx = 0;
	raycast->sidedisty = 0;
	raycast->stepx = 0;
	raycast->stepy = 0;
	raycast->deltadistx = 0;
	raycast->deltadisty = 0;
	raycast->hit = 0;
	raycast->x = 0;
}

void	ft_start(t_game	*game)
{
	ft_init(&game->raycast);
	ft_init_2(game);

	ft_raycasting(game, &game->raycast);
	// ft_fill_flo(game,  game->x_size,  game->y_size, game->array); // a enlever avant la 3D
	
	mlx_hook(game->mlx_win, 2, 1L << 0, ft_close_esc, game);
	mlx_hook(game->mlx_win, 17, 0L, ft_close_cross, game);
	// mlx_loop_hook(game->mlx, ft_raycasting, game); //segfault
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