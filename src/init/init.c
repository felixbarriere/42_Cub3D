/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarrier <fbarrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 17:09:28 by fbarrier          #+#    #+#             */
/*   Updated: 2022/09/09 17:09:28 by fbarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub_3d.h"

/* int code = (blue * 256 * 256) + (green * 256) + red */

int	ft_convert_color(char *str)
{
	char	**rgb;
	int		res;

	rgb = ft_split(str, ',');
	res = (ft_atoi(rgb[0]) * 256 * 256) + (ft_atoi(rgb[1]) * 256)
		+ ft_atoi(rgb[2]);
	ft_free_array (rgb);
	return (res);
}

void	ft_vector_dir(t_raycast	*raycast, char	**array)
{
	if (array[raycast->char_pos_x][raycast->char_pos_y] == 'N')
	{
		raycast->plany = 0.66;
		raycast->dirx = -1;
	}
	else if (array[raycast->char_pos_x][raycast->char_pos_y] == 'S')
	{
		raycast->plany = -0.66;
		raycast->dirx = 1;
	}
	else if (array[raycast->char_pos_x][raycast->char_pos_y] == 'W')
	{
		raycast->planx = -0.66;
		raycast->diry = -1;
	}
	else if (array[raycast->char_pos_x][raycast->char_pos_y] == 'E')
	{
		raycast->planx = 0.66;
		raycast->diry = 1;
	}
}

void	ft_init_2(t_game	*game)
{
	game->mv_forward = 0;
	game->mv_back = 0;
	game->mv_left = 0;
	game->mv_right = 0;
	game->rot_left = 0;
	game->rot_right = 0;
	game->floor_rgb = 0;
	game->ceilling_rgb = 0;
	game->mlx = mlx_init();
	game->floor_rgb = ft_convert_color(game->floor_id);
	game->ceilling_rgb = ft_convert_color(game->ceilling_id);
	mlx_get_screen_size(game->mlx, &game->res_x, &game->res_y);
	game->res_x = game->res_x / 1.8;
	game->res_y = game->res_y / 1.8;
	game->raycast.char_pos_y = ft_elt_pos_x(game->array);
	game->raycast.char_pos_x = ft_elt_pos_y(game->array);
	game->raycast.charpos_x_2 = (double)game->raycast.char_pos_x + 0.5;
	game->raycast.charpos_y_2 = (double)game->raycast.char_pos_y + 0.5;
	game->raycast.mapx = (int)game->raycast.charpos_x_2;
	game->raycast.mapy = (int)game->raycast.charpos_y_2;
	ft_vector_dir(&game->raycast, game->array);
	game->mlx_win = NULL;
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
	raycast->x = 0;
}
