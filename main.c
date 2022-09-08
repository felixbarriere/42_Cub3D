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
	else if (keycode == 119)  //linux QWERTY: 119, linux AZERTY: 122
	{
		// printf("W = forward\n");
		game->mv_forward = 1;
		// ft_forward(game, &game->raycast);
		// game->img_2 = mlx_new_image(game->mlx, game->res_x, game->res_y);
		// game->address_2 = (int *)mlx_get_data_addr(game->img_2, &game->bits_per_pixel,
		// 						&game->line_length, &game->endian);
		// ft_swap_img(game);
		ft_forward_back(game, &game->raycast);
		ft_raycasting(game, &game->raycast);
	}
	else if (keycode == 115)
	{
		printf("S = back\n");
		game->mv_back = 1;
		ft_forward_back(game, &game->raycast);
		ft_raycasting(game, &game->raycast);
	}
	else if (keycode == 100)
	{
		printf("D = right\n");
		game->mv_right = 1;
		ft_left_right(game, &game->raycast);
		ft_raycasting(game, &game->raycast);
	}
	else if (keycode == 97)  //linux QWERTY: 97, linux AZERTY: 113
	{
		printf("A = left\n");
		game->mv_left = 1;
		ft_left_right(game, &game->raycast);
		ft_raycasting(game, &game->raycast);
	}
	else if (keycode == XK_Right)
	{
		printf("rotate right\n");
		game->rot_right = 1;
	}
	else if (keycode == XK_Left)
	{
		printf("rotate left\n");
		game->rot_left = 1;
	}
	return (0);
}

int	ft_keys_release(int	keycode, t_game	*game)
{
	if (keycode == 119)  //linux QWERTY: 119, linux AZERTY: 122
	{
		printf("forward released\n");
		game->mv_forward = 0;
	}
	else if (keycode == 115)
	{
		printf("S = back released\n");
		game->mv_back = 0;
	}
	else if (keycode == 100)
	{
		printf("D = right released\n");
		game->mv_right = 0;
	}
	else if (keycode == 97)  //linux QWERTY: 97, linux AZERTY: 113
	{
		printf("A = left released\n");
		game->mv_left = 0;
	}
	else if (keycode == 65363)
	{
		printf("release rotate right\n");
		game->rot_right = 0;
	}
	else if (keycode == 65361)
	{
		printf("release rotate left\n");
		game->rot_left = 0;
	}
	return (0);
}

void	ft_loop_hook(t_game	*game)
{
	mlx_hook(game->mlx_win, 17, 0L, ft_close_cross, game);
	mlx_hook(game->mlx_win, 2, 1L << 0, ft_keys, game);
	mlx_hook(game->mlx_win, 3, 1L << 1, ft_keys_release, game);  //remet mv a 0;
	mlx_loop(game->mlx);
}

void	ft_start(t_game	*game)
{
	game->mlx_win = mlx_new_window(game->mlx, game->res_x,
								game->res_y, "Cub3D");
	game->img = mlx_new_image(game->mlx, game->res_x, game->res_y);
	game->address = (int *)mlx_get_data_addr(game->img, &game->bits_per_pixel,
								&game->line_length, &game->endian);
	
	ft_raycasting(game, &game->raycast);
	ft_loop_hook(game);

	// game->img_2 = mlx_new_image(game->mlx, game->res_x, game->res_y);
	// game->address_2 = (int *)mlx_get_data_addr(game->img_2, &game->bits_per_pixel,
	// 							&game->line_length, &game->endian);
}

int	main(int	argc, char **argv)
{
	t_game	game;

	(void)argc;   //a faire
	game.array = NULL;
	game.floor_id = NULL;
	game.ceilling_id = NULL;
	game.file = fill_file(argv[1], &game);
	ft_print_map(game.file);
	ft_init_elem(&game);

	if (!check_file_name(argv[1]))   //marche pas, segfault a checker
		return (0);
	if(!ft_check_elem(&game) || !ft_check_map(&game))
    {
        printf("Error\nIncorrect Map!\n");
        ft_free_array(game.array);
        return (0);
    }
	game.array = fill_array(argv[1], &game);
	ft_print_map(game.array);
    ft_space(&game);
	ft_init(&game.raycast);
	ft_init_2(&game);
	
	game.array = ft_fill_map_2(game.array);  // remplace la lettre du perso par '0'
	ft_print_map(game.array);


	ft_get_texture(&game);
	ft_start(&game);
	return (0);
}
