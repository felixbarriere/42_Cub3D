/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherpre <hcherpre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:08:24 by hcherpre          #+#    #+#             */
/*   Updated: 2022/09/12 14:39:57 by hcherpre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub_3d.h"

int	ft_check_elem(t_game *game)
{
	int		count;
	int		i;
	char	**tab;

	i = 0;
	count = 0;
	while (game->file[i])
	{
		if (game->file[i][0] != '\n')
		{
			tab = ft_split(game->file[i], ' ');
			if (!ft_is_elem_correct(tab, game, count) || !ft_is_xpm(tab))
			{
				ft_free_array(tab);
				return (0);
			}
			ft_free_array(tab);
			count++;
		}
		if (count == 7)
			break ;
		i++;
	}
	game->element.index = i;
	return (1);
}

int	ft_is_elem_correct(char **tab, t_game *game, int count)
{
	if (count == 6)
	{
		if (ft_file_correct(tab))
			return (1);
	}
	else
	{
		if (!ft_check_elem_2(tab))
			return (0);
		else if (ft_is_elem_correct_2(tab, game))
			return (1);
		else
			return (0);
		return (1);
	}
	return (0);
}

int	ft_is_elem_correct_2(char **tab, t_game *game)
{
	if ((!ft_strcmp(tab[0], "NO") || !ft_strcmp(tab[0], "N"))
		&& !game->element.north)
		game->element.north += 1;
	else if ((!ft_strcmp(tab[0], "SO") || !ft_strcmp(tab[0], "S"))
		&& !game->element.south)
		game->element.south += 1;
	else if ((!ft_strcmp(tab[0], "WE") || !ft_strcmp(tab[0], "E"))
		&& !game->element.west)
		game->element.west += 1;
	else if ((!ft_strcmp(tab[0], "EA") || !ft_strcmp(tab[0], "E"))
		&& !game->element.east)
		game->element.east += 1;
	else if (!ft_strcmp(tab[0], "F") && !game->element.floor)
		game->element.floor += 1;
	else if (!ft_strcmp(tab[0], "C") && !game->element.ceilling)
		game->element.ceilling += 1;
	else
	{
		write(2, "Error\nTexture Identifier Incorrect!\n", 36);
		return (0);
	}
	return (1);
}

int	ft_check_elem_2(char **tab)
{
	if (tab[0][0] == 'N' || tab[0][0] == 'S'
		|| tab[0][0] == 'W' || tab[0][0] == 'E'
		|| tab[0][0] == 'F' || tab[0][0] == 'C')
	{
		if (tab[2] != NULL || tab[1] == NULL)
		{
			write(2, "Error\nToo much Elements!\n", 25);
			return (0);
		}
	}
	if (tab[0][0] == 'N' || tab[0][0] == 'S'
		|| tab[0][0] == 'W' || tab[0][0] == 'E')
	{
		tab[1][ft_strlen(tab[1]) - 1] = '\0';
		if (open(tab[1], O_RDONLY) == -1)
		{
			write(2, "Error\nFile Texture Invalid!\n", 28);
			return (0);
		}
	}
	else if (tab[0][0] == 'F' || tab[0][0] == 'C')
		if (!ft_check_color(tab[1]))
			return (0);
	return (1);
}

int	ft_is_xpm(char **tab)
{
	if (tab[0][0] == 'N' || tab[0][0] == 'S'
		|| tab[0][0] == 'W' || tab[0][0] == 'E')
	{
		if (tab[1][ft_strlen(tab[1]) - 1] != 'm'
			|| tab[1][ft_strlen(tab[1]) - 2] != 'p'
			|| tab[1][ft_strlen(tab[1]) - 3] != 'x'
			|| tab[1][ft_strlen(tab[1]) - 4] != '.')
		{
			write(2, "Error\nIncorrect texture extention\n",
				ft_strlen("Error\nIncorrect texture extention\n"));
			return (0);
		}
	}
	return (1);
}
