/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherpre <hcherpre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 14:03:33 by hcherpre          #+#    #+#             */
/*   Updated: 2022/09/12 14:05:56 by hcherpre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub_3d.h"

int	ft_keys_moves_2(int keycode, t_game *game)
{
	if (keycode == XK_Right)
	{
		game->rot_right = 1;
		ft_rot_right(game, &game->raycast);
	}
	else if (keycode == XK_Left)
	{
		game->rot_left = 1;
		ft_rot_left(game, &game->raycast);
	}
	ft_raycasting(game, &game->raycast);
	return (0);
}

int	ft_keys_moves(int keycode, t_game *game)
{
	if (keycode == 119)
	{
		game->mv_forward = 1;
		ft_forward_back(game, &game->raycast);
	}
	else if (keycode == 115)
	{
		game->mv_back = 1;
		ft_forward_back(game, &game->raycast);
	}
	else if (keycode == 100)
	{
		game->mv_right = 1;
		ft_left_right(game, &game->raycast);
	}
	else if (keycode == 97)
	{
		game->mv_left = 1;
		ft_left_right(game, &game->raycast);
	}
	ft_keys_moves_2(keycode, game);
	return (0);
}

int	ft_keys(int keycode, t_game *game)
{
	if (keycode == 65307)
	{
		printf ("Closing game\n");
		mlx_destroy_window (game->mlx, game->mlx_win);
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
	ft_keys_moves(keycode, game);
	return (0);
}

int	ft_keys_release(int keycode, t_game *game)
{
	if (keycode == 119)
		game->mv_forward = 0;
	else if (keycode == 115)
		game->mv_back = 0;
	else if (keycode == 100)
		game->mv_right = 0;
	else if (keycode == 97)
		game->mv_left = 0;
	else if (keycode == XK_Right)
		game->rot_right = 0;
	else if (keycode == XK_Left)
		game->rot_left = 0;
	return (0);
}

void	ft_loop_hook(t_game	*game)
{
	mlx_hook(game->mlx_win, 17, 0L, ft_close_cross, game);
	mlx_hook(game->mlx_win, 2, 1L << 0, ft_keys, game);
	mlx_hook(game->mlx_win, 3, 1L << 1, ft_keys_release, game);
	mlx_loop(game->mlx);
}
