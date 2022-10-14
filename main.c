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

int	ft_close_cross(t_game	*game)
{
	printf ("Closing game\n");
	mlx_destroy_window(game->mlx, game->mlx_win);
	mlx_destroy_image(game->mlx, game->img);
	mlx_destroy_image(game->mlx, game->texture[0].img);
	mlx_destroy_image(game->mlx, game->texture[1].img);
	mlx_destroy_image(game->mlx, game->texture[2].img);
	mlx_destroy_image(game->mlx, game->texture[3].img);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	ft_free_array(game->array);
	free(game->north_id);
	free(game->south_id);
	free(game->west_id);
	free(game->east_id);
	free(game->ceilling_id);
	free(game->floor_id);
	exit(0);
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

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		write(2, "Error\nIncorrect arguments number!\n", 35);
		return (0);
	}
	if (!check_file_name(argv[1]))
		return (0);
	game.file = fill_file(argv[1], &game);
	ft_init_elem(&game);
	if (!ft_check_elem(&game) || !ft_check_map(&game))
	{
		ft_free_array(game.file);
		return (0);
	}
	game.array = fill_array(argv[1], &game);
	ft_space(&game);
	ft_init(&game.raycast);
	ft_init_2(&game);
	game.array = ft_fill_map_2(game.array);
	ft_get_texture(&game);
	ft_start(&game);
	return (0);
}
