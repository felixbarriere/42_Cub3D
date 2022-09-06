#include "includes/cub_3d.h"

void	ft_print_map(char	**map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		printf("map[i]: %s", map[i]);
		i++;
	}
}

int	ft_close_cross(t_game	*game)
{
	printf ("Closing game");
	mlx_destroy_window(game->mlx, game->mlx_win);
	exit(0);
}

int	ft_keys(int	keycode, t_game	*game)
{
	if (keycode == 65307) // trouver le bon keycode pour linux
	{
		printf ("Closing game");
		mlx_destroy_window (game->mlx, game->mlx_win);
		exit(0);
	}
	else if (keycode == 122)  //linux QWERTY: 119, linux AZERTY: 122
	{
		printf("Z = forward\n");
		game->mv_forward = 1;
	}
	else if (keycode == 115)
	{
		printf("S = back\n");
		game->mv_back = 1;
	}
	else if (keycode == 100)
	{
		printf("D = right\n");
		game->mv_right = 1;
	}
	else if (keycode == 113)  //linux QWERTY: 97, linux AZERTY: 113
	{
		printf("Q = left\n");
		game->mv_left = 1;
	}
	return (0);
}

int	ft_keys_release(int	keycode, t_game	*game)
{
	if (keycode == 122)  //linux QWERTY: 119, linux AZERTY: 122
	{
		printf("Z = forward\n");
		game->mv_forward = 0;
	}
	else if (keycode == 115)
	{
		printf("S = back\n");
		game->mv_back = 0;
	}
	else if (keycode == 100)
	{
		printf("D = right\n");
		game->mv_right = 0;
	}
	else if (keycode == 113)  //linux QWERTY: 97, linux AZERTY: 113
	{
		printf("Q = left\n");
		game->mv_left = 0;
	}
	return (0);
}

void	ft_start(t_game	*game)
{
	ft_init(&game->raycast);
	ft_init_2(game);
	ft_get_texture(game);
	game->img = mlx_new_image(game->mlx, game->res_x, game->res_y);
	game->address = (int *)mlx_get_data_addr(game->img, &game->bits_per_pixel,
					&game->line_length, &game->endian);
	game->mlx_win = mlx_new_window(game->mlx, game->res_x,
						game->res_y, "Cub3D");
	ft_raycasting(game, &game->raycast);

	game->img_2 = mlx_new_image(game->mlx,  game->res_x, game->res_y);
	game->address_2 = (int *)mlx_get_data_addr(game->img_2, &game->bits_per_pixel,
					&game->line_length, &game->endian);
	mlx_hook(game->mlx_win, 17, 0L, ft_close_cross, game);
	mlx_hook(game->mlx_win, 2, 1L << 0, ft_keys, game);
	// mlx_loop_hook(game->mlx, ft_raycasting, game); //segfault a cause des init
	// mlx_hook(game->mlx_win, 3, 1L << 1, ft_keys_release, game);
	mlx_loop(game->mlx);

	
}

int	main(int	argc, char **argv)
{
	t_game	game;

	(void)argc;
	game.array = NULL;
	game.floor_id = NULL;
	game.ceilling_id = NULL;
	game.array = fill_array(argv[1], &game);


	// il faudra réajuster la map en ajoutant des 1 a la place des espaces 
	// exterieurs pour allouer correctement.

	ft_print_map(game.array);
	ft_start(&game);
	return (0);
}