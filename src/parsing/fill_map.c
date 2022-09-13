/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherpre <hcherpre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:08:47 by hcherpre          #+#    #+#             */
/*   Updated: 2022/09/12 14:02:34 by hcherpre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub_3d.h"

void	ft_space(t_game *game)
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
			if (game->file[i][j] == ' ' || game->file[i][j] == '\n')
				game->file[i][j] = '1';
			j++;
		}
		if (count < j)
			count = j;
		i++;
	}
	ft_fill_map(game, count);
}

void	ft_fill_map(t_game *game, int count)
{
	int		i;
	int		j;
	int		k;
	char	**tab;

	tab = ft_malloc_map(game);
	i = game->element.index;
	k = 0;
	while (game->file[i])
	{
		tab[k] = malloc(sizeof(char) * count + 1);
		if (!tab[k])
			return ;
		j = 0;
		while (game->file[i][j])
		{
			tab[k][j] = game->file[i][j];
			j++;
		}
		ft_check_fill_map(tab, count, &k, &j);
		i++;
	}
	tab[k] = NULL;
	ft_free_map(game, tab);
}

char	**ft_malloc_map(t_game *game)
{
	int		i;
	char	**tab;

	i = game->element.index;
	while (game->file[i])
		i++;
	tab = malloc(sizeof(char *) * ((i - game->element.index) + 1));
	if (!tab)
		return (NULL);
	return (tab);
}

void	ft_check_fill_map(char	**tab, int count, int *k, int *j)
{
	if ((*j) < count)
	{
		while ((*j) < count)
		{
			tab[(*k)][(*j)] = '1';
			(*j)++;
		}
	}
	tab[(*k)][(*j)] = '\0';
	(*k)++;
}

void	ft_free_map(t_game *game, char **tab)
{
	ft_free_array(game->file);
	ft_free_array(game->array);
	game->array = tab;
}
