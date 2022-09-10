/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherpre <hcherpre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:08:30 by hcherpre          #+#    #+#             */
/*   Updated: 2022/09/09 14:08:30 by hcherpre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub_3d.h"

void	ft_free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array[i]);
	free(array);
}

void	ft_free_all(t_game	*game)
{
	ft_free_array(game->array);
	if (game->floor_id)
		free(game->floor_id);
	if (game->ceilling_id)
		free(game->ceilling_id);
	if (game->north_id)
		free(game->north_id);
	if (game->south_id)
		free(game->south_id);
	if (game->west_id)
		free(game->west_id);
	if (game->east_id)
		free(game->east_id);
	free(game->mlx);
	free(game->mlx_win);
}
