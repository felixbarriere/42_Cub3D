/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elem_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherpre <hcherpre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 11:15:09 by hcherpre          #+#    #+#             */
/*   Updated: 2022/09/13 12:48:44 by hcherpre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub_3d.h"

int	ft_file_correct(char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == '1' || tab[i][j] == '\n')
				j++;
			else
			{
				write(2, "Error\nIncorrect Structure File!\n", 32);
				return (0);
			}
		}
		i++;
	}
	return (1);
}

int	ft_check_color(char *array)
{
	char	**tab;
	int		i;

	i = 0;
	tab = ft_split(array, ',');
	while (tab[i])
	{
		if (ft_isdigit(tab[i]) && (ft_atoi(tab[i]) >= 0
				&& ft_atoi(tab[i]) <= 255))
			i++;
		else
		{
			write(2, "Error\nWrong RGB!\n", 17);
			ft_free_array(tab);
			return (0);
		}
	}
	if (i != 3 || (i == 3 && tab[2][0] == '\n'))
	{
		write(2, "Error\nWrong Elements!\n", 22);
		ft_free_array(tab);
		return (0);
	}
	ft_free_array(tab);
	return (1);
}

void	ft_init_elem(t_game *game)
{
	game->element.north = 0;
	game->element.south = 0;
	game->element.west = 0;
	game->element.east = 0;
	game->element.floor = 0;
	game->element.ceilling = 0;
	game->element.index = 0;
}
