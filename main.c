/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarrier <fbarrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 17:08:36 by fbarrier          #+#    #+#             */
/*   Updated: 2022/09/09 17:08:36 by fbarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		game->mv_forward = 1;
		ft_forward_back(game, &game->raycast);
		// ft_raycasting(game, &game->raycast);
	}
	else if (keycode == 115)
	{
		game->mv_back = 1;
		ft_forward_back(game, &game->raycast);
		// ft_raycasting(game, &game->raycast);
	}
	else if (keycode == 100)
	{
		game->mv_right = 1;
		ft_left_right(game, &game->raycast);
		// ft_raycasting(game, &game->raycast);
	}
	else if (keycode == 97)  //linux QWERTY: 97, linux AZERTY: 113
	{
		game->mv_left = 1;
		ft_left_right(game, &game->raycast);
		// ft_raycasting(game, &game->raycast);
	}
	if (keycode == XK_Right)
	{
		game->rot_right = 1;
		ft_rot(game, &game->raycast);
		// ft_raycasting(game, &game->raycast);
	}
	else if (keycode == XK_Left)
	{
		game->rot_left = 1;
		ft_rot(game, &game->raycast);
		// ft_raycasting(game, &game->raycast);
	}
	ft_raycasting(game, &game->raycast);
	return (0);
}

int	ft_keys_release(int	keycode, t_game	*game)
{
	if (keycode == 119)  //linux QWERTY: 119, linux AZERTY: 122
	{
		game->mv_forward = 0;
	}
	else if (keycode == 115)
	{
		game->mv_back = 0;
	}
	else if (keycode == 100)
	{
		game->mv_right = 0;
	}
	else if (keycode == 97)  //linux QWERTY: 97, linux AZERTY: 113
	{
		game->mv_left = 0;
	}
	else if (keycode == XK_Right)
	{
		game->rot_right = 0;
	}
	else if (keycode == XK_Left)
	{
		game->rot_left = 0;
	}
	return (0);
}

void	ft_loop_hook(t_game	*game)
{
	mlx_hook(game->mlx_win, 17, 0L, ft_close_cross, game);
	mlx_hook(game->mlx_win, 2, 1L << 0, ft_keys, game);
	// ft_raycasting(game, &game->raycast);
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
}

int	main(int	argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		printf("Error\nIncorrect arguments number!\n"); //utiliser write (sortie d erreur) 
        return (0);
	}
	if (!check_file_name(argv[1]))
		return (0);
	game.array = NULL;
	game.floor_id = NULL;
	game.ceilling_id = NULL;
	game.file = fill_file(argv[1], &game);
	ft_init_elem(&game);
	if(!ft_check_elem(&game) || !ft_check_map(&game))
    {
        printf("Error\nIncorrect Map!hola\n"); //utiliser write (sortie d erreur)
        ft_free_array(game.file);
        return (0);
    }
	game.array = fill_array(argv[1], &game);
    ft_space(&game);
	ft_init(&game.raycast);
	ft_init_2(&game);
	game.array = ft_fill_map_2(game.array);  // remplace la lettre du perso par '0'
	// ft_print_map(game.array);
	ft_get_texture(&game);
	ft_start(&game);
	return (0);
}
