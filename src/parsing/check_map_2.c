/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherpre <hcherpre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 16:32:19 by hcherpre          #+#    #+#             */
/*   Updated: 2022/09/14 16:32:37 by hcherpre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub_3d.h"

int	ft_check_player(t_game *game)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = game->element.index;
	while (game->file[i])
	{
		j = 0;
		while (game->file[i][j])
		{
			if (game->file[i][j] == 'N' || game->file[i][j] == 'S'
			|| game->file[i][j] == 'W' || game->file[i][j] == 'E')
			{
				game->element.pos = game->file[i][j];
				count++;
			}
			j++;
		}
		i++;
	}
	if (count == 1)
		return (1);
	return (0);
}
