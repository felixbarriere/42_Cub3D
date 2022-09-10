/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarrier <fbarrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 17:08:56 by fbarrier          #+#    #+#             */
/*   Updated: 2022/09/09 17:08:56 by fbarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub_3d.h"

void	ft_forward_back(t_game *game, t_raycast	*raycast)
{
	if (game->mv_forward == 1)
	{
		if (game->array[(int)(raycast->charpos_x_2 + (raycast->dirx
					* raycast->movespeed * 2))]
					[(int)raycast->charpos_y_2] == '0')
			raycast->charpos_x_2 += raycast->dirx * raycast->movespeed;
		if (game->array[(int)(raycast->charpos_x_2)]
					[(int)(raycast->charpos_y_2
					+ (raycast->diry * raycast->movespeed * 2))] == '0')
			raycast->charpos_y_2 += raycast->diry * raycast->movespeed;
	}
	else if (game->mv_back == 1)
	{
		if (game->array[(int)(raycast->charpos_x_2 - (raycast->dirx
					* raycast->movespeed * 2))]
					[(int)raycast->charpos_y_2] == '0')
			raycast->charpos_x_2 -= raycast->dirx * raycast->movespeed;
		if (game->array[(int)(raycast->charpos_x_2)]
					[(int)(raycast->charpos_y_2
					- (raycast->diry * raycast->movespeed * 2))] == '0')
			raycast->charpos_y_2 -= raycast->diry * raycast->movespeed;
	}
}

void	ft_left_right(t_game *game, t_raycast	*raycast)
{
	if (game->mv_right == 1)
	{
		if (game->array[(int)(raycast->charpos_x_2 + (raycast->diry
					* raycast->movespeed * 2))]
					[(int)raycast->charpos_y_2] == '0')
			raycast->charpos_x_2 += raycast->diry * raycast->movespeed;
		if (game->array[(int)(raycast->charpos_x_2)]
					[(int)(raycast->charpos_y_2
					- (raycast->dirx * raycast->movespeed * 2))] == '0')
			raycast->charpos_y_2 -= raycast->dirx * raycast->movespeed;
	}
	if (game->mv_left == 1)
	{
		if (game->array[(int)(raycast->charpos_x_2 - (raycast->diry
					* raycast->movespeed * 2))]
					[(int)raycast->charpos_y_2] == '0')
			raycast->charpos_x_2 -= raycast->diry * raycast->movespeed;
		if (game->array[(int)(raycast->charpos_x_2)]
					[(int)(raycast->charpos_y_2
					+ (raycast->dirx * raycast->movespeed * 2))] == '0')
			raycast->charpos_y_2 += raycast->dirx * raycast->movespeed;
	}
}

void	ft_rot_right(t_game *game, t_raycast	*raycast)
{
	double	old_dir_x;
	double	old_plane_x;

	if (game->rot_right == 1)
	{
		old_dir_x = raycast->dirx;
		raycast->dirx = raycast->dirx * cos(-raycast->rotspeed) - raycast->diry
			* sin(-raycast->rotspeed);
		raycast->diry = old_dir_x * sin(-raycast->rotspeed) + raycast->diry
			* cos(-raycast->rotspeed);
		old_plane_x = raycast->planx;
		raycast->planx = raycast->planx * cos(-raycast->rotspeed)
			- raycast->plany * sin(-raycast->rotspeed);
		raycast->plany = old_plane_x * sin(-raycast->rotspeed) + raycast->plany
			* cos(-raycast->rotspeed);
	}
}

void	ft_rot_left(t_game *game, t_raycast	*raycast)
{
	double	old_dir_x;
	double	old_plane_x;

	if (game->rot_left == 1)
	{
		old_dir_x = raycast->dirx;
		raycast->dirx = raycast->dirx * cos(raycast->rotspeed) - raycast->diry
			* sin(raycast->rotspeed);
		raycast->diry = old_dir_x * sin(raycast->rotspeed) + raycast->diry
			* cos(raycast->rotspeed);
		old_plane_x = raycast->planx;
		raycast->planx = raycast->planx * cos(raycast->rotspeed)
			- raycast->plany * sin(raycast->rotspeed);
		raycast->plany = old_plane_x * sin(raycast->rotspeed) + raycast->plany
			* cos(raycast->rotspeed);
	}
}
