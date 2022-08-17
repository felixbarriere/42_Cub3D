#include "../includes/cub_3d.h"


void	my_mlx_pixel_put(t_game *game, int x, int y, int color)
{
  char    *dst;

  dst = game->address + (y * game->line_length + x * (game->bits_per_pixel / 8));
  *(unsigned int*)dst = color;
}

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

void	*ft_img(void *mlx, char *path)
{
	int		x;
	int		y;
	void	*test;

	x = 0;
	y = 0;
	test = mlx_xpm_file_to_image(mlx, path, &x, &y);
	return (test);
}

// void	ft_init_2(t_game	game)
// {
// 	game.mlx = NULL;
// 	game.img = NULL;
// 	game.address = NULL;
// 	game.wall_img = NULL;
// 	game.mlx_win = NULL;
// 	(void)game;
// }

void	ft_init(t_game	*game)
{
	// ft_init_2(game);
	game->mlx = mlx_init();
	game->image.wall = ft_img(game->mlx, "../img/wall.xpm");
	game->mlx_win = mlx_new_window(game->mlx, 1500, 800, "Cub3D");
	game->img = mlx_new_image(game->mlx, 1500, 800);
	game->address = mlx_get_data_addr(game->img, &game->bits_per_pixel,
							&game->line_length, &game->endian);

	mlx_put_image_to_window(game->mlx, game->mlx_win,
					game->image.wall, 0, 0);


	// ft_fill_flo(game, 11, 3, game->array);

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