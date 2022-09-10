/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarrier <fbarrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 17:08:41 by fbarrier          #+#    #+#             */
/*   Updated: 2022/09/09 17:08:41 by fbarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub_3d.h"

void	ft_init_texture(t_game	*game, t_raycast	*raycast)
{
	if (raycast->side == 0 && raycast->raydirx < 0)
		game->t.tex_dir = 0;
	if (raycast->side == 0 && raycast->raydirx >= 0)
		game->t.tex_dir = 1;
	if (raycast->side == 1 && raycast->raydiry < 0)
		game->t.tex_dir = 2;
	if (raycast->side == 1 && raycast->raydiry >= 0)
		game->t.tex_dir = 3;
	if (raycast->side == 0)
		game->t.wall_x = raycast->charpos_y_2 + raycast->perpwalldist
			* raycast->raydiry;
	else
		game->t.wall_x = raycast->charpos_x_2 + raycast->perpwalldist
			* raycast->raydirx;
	game->t.wall_x -= floor((game->t.wall_x));
}

void	ft_draw_texture(t_game *game, t_raycast *raycast, int x, int y)
{
	y = raycast->drawstart - 1;
	ft_init_texture(game, raycast);
	game->t.step = 1.0 * game->texture[0].height / raycast->lineheight;
	game->t.tex_x = (int)(game->t.wall_x * (double)game->texture
		[game->t.tex_dir].width);
	if (raycast->side == 0 && raycast->raydirx > 0)
		game->t.tex_x = game->texture[game->t.tex_dir].width
			- game->t.tex_x - 1;
	if (raycast->side == 1 && raycast->raydiry < 0)
		game->t.tex_x = game->texture[game->t.tex_dir].width
			- game->t.tex_x - 1;
	game->t.tex_pos = (raycast->drawstart - game->res_y / 2
			+ raycast->lineheight / 2) * game->t.step;
	while (++y <= raycast->drawend)
	{
		game->t.tex_y = (int)game->t.tex_pos
			&(game->texture[game->t.tex_dir].height - 1);
		game->t.tex_pos += game->t.step;
		if (y < game->res_y && x < game->res_x)
			game->address[y * game->line_length / 4 + x]
				= game->texture[game->t.tex_dir].address[game->t.tex_y
				* game->texture[game->t.tex_dir].line_length
				/ 4 + game->t.tex_x];
	}
}

/* on part du ceilling jusqu'à la colonne, puis de la colonne jusqu'au floor
en envoyant les couleurs(C/F)/textures(murs) correspondantes */

void	ft_put_color(t_game	*game, t_raycast	*raycast)
{
	int	j;
	int	i;

	j = -1;
	raycast->drawend = game->res_y - raycast->drawstart;
	i = raycast->drawend;
	while (++j < raycast->drawstart)
		game->address[j * game->line_length / 4 + raycast->x]
			= game->ceilling_rgb;
	if (j <= raycast->drawend)
		ft_draw_texture(game, raycast, raycast->x, j);
	j = i;
	while (++j < game->res_y)
		game->address[j * game->line_length / 4 + raycast->x]
			= game->floor_rgb;
}
