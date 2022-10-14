/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherpre <hcherpre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:08:39 by hcherpre          #+#    #+#             */
/*   Updated: 2022/09/14 16:37:25 by hcherpre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub_3d.h"

int	ft_check_map(t_game *game)
{
	if (!ft_check_map_2(game) || !ft_check_player(game))
	{
		write (2, "Error\nIncorrect Map!\n", 21);
		return (0);
	}
	return (1);
}

int	ft_check_map_2(t_game *game)
{
	int	i;
	int	j;

	i = game->element.index;
	while (game->file[i])
	{
		j = 0;
		while (game->file[i][j])
		{
			if (game->file[i][j] == '0' || game->file[i][j] == 'N'
				|| game->file[i][j] == 'S' || game->file[i][j] == 'W'
				|| game->file[i][j] == 'E')
			{
				if (!ft_check_wall(game, i, j, 0))
					return (0);
			}
			else if (game->file[i][j] != '1' && game->file[i][j] != ' '
					&& game->file[i][j] != '\n')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check_wall(t_game *game, int i, int j, int b)
{
	b = j;
	while (game->file[i][b])
	{
		if (game->file[i][b] == '1' || game->file[i][b] == ' ')
			break ;
		b++;
	}
	if (game->file[i][b] == ' ' || game->file[i][b] == '\0')
		return (0);
	b = j;
	while (b > 0)
	{
		if (game->file[i][b] == '1' || game->file[i][b] == ' ')
			break ;
		b--;
	}
	if (game->file[i][0] == '1' || game->file[i][b] == '1')
	{
		if (!ft_check_wall_2(game, i, j))
			return (0);
	}
	else if (game->file[i][0] == '0' || game->file[i][b] == '0'
		|| game->file[i][0] == ' ' || game->file[i][b] == ' ')
		return (0);
	return (1);
}

int	ft_check_wall_2(t_game *game, int i, int j)
{
	int	a;
	int	check;

	a = i;
	check = 0;
	while (game->file[a] && game->file[a][j])
	{
		if (game->file[a][j] == '1' || game->file[a][j] == ' ')
		{
			check += 1;
			break ;
		}
		if (game->file[a + 1] && ft_strlen(game->file[a + 1]) >= j)
			a++;
		else
			break ;
	}
	if (!check || (check == 1 && game->file[a][j] == ' '))
		return (0);
	if (!ft_check_wall_3(game, i, j))
		return (0);
	return (1);
}

int	ft_check_wall_3(t_game *game, int i, int j)
{
	int	a;
	int	check;

	a = i;
	check = 0;
	while (game->file[a] && game->file[a][j] && a >= game->element.index)
	{
		if (game->file[a][j] == '1' || game->file[a][j] == ' ')
		{
			check += 1;
			break ;
		}
		if (game->file[a - 1] && ft_strlen(game->file[a - 1]) >= j)
			a--;
		else
			break ;
	}
	if (!check || (check == 1 && game->file[a][j] == ' '))
		return (0);
	return (1);
}
