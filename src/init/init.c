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

/* https://stackoverflow.com/questions/19277010/bit-shift-and-bitwise-operations-to-encode-rgb-values
int code = (blue * 256 * 256) + (green * 256) + red */

int		ft_convert_color(char *str)
{
	char	**rgb;
	// int		i;
	int		res;

	rgb = ft_split(str, ',');
	// i = 0;
	// while (rgb[i])
	// {
	// 	if (i > 2)
	// 		return (0);
	// 	i++;
	// }
	// i = 0;
	res = (ft_atoi(rgb[0]) * 256 * 256) + (ft_atoi(rgb[1]) * 256) + ft_atoi(rgb[2]);
	ft_free_array (rgb);
	return (res);
}

// void	ft_fill_dir_plane(int	dir_zero, int	neg_one, int	one, int plan_zero)   //sert a rien
// {
// 	dir_zero = 0;
// 	neg_one = -1;
// 	one = 1;
// 	plan_zero = 0;
// 	(void)dir_zero;
// 	(void)neg_one;
// 	(void)one;
// 	(void)plan_zero;
// }

void		ft_vector_dir(t_raycast	*raycast, char	**array)
{
	if (array[raycast->char_pos_x][raycast->char_pos_y] == 'N')
	{
		// ft_fill_dir_plane(raycast->diry, raycast->dirx, 1, raycast->planx);
		raycast->plany = 0.66;
		raycast->dirx = -1;
	}
	else if (array[raycast->char_pos_x][raycast->char_pos_y] == 'S')
	{
		// ft_fill_dir_plane(raycast->diry, -1, raycast->dirx, raycast->planx);
		raycast->plany = -0.66;
		raycast->dirx = 1;
	}
	else if (array[raycast->char_pos_x][raycast->char_pos_y] == 'W')
	{
		// ft_fill_dir_plane(raycast->dirx, raycast->diry, 1, raycast->plany);
		raycast->planx = -0.66;
		raycast->diry = -1;
	}
	else if (array[raycast->char_pos_x][raycast->char_pos_y] == 'E')
	{
		// ft_fill_dir_plane(raycast->dirx, -1, raycast->diry, raycast->plany);
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
	game->floor_RGB = 0;
	game->ceilling_RGB = 0;
	game->mlx = mlx_init();
	game->floor_RGB = ft_convert_color(game->floor_id);  //attention il manque le calcul principal
	game->ceilling_RGB = ft_convert_color(game->ceilling_id);
	mlx_get_screen_size(game->mlx, &game->res_x, &game->res_y);
	game->res_x = game->res_x / 2;
	game->res_y = game->res_y / 2;
	// attention: worldMap[mapWidth][mapHeight] (inverser x et y);
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