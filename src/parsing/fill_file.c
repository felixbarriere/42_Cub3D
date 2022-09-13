/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherpre <hcherpre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:19:29 by hcherpre          #+#    #+#             */
/*   Updated: 2022/09/12 13:37:25 by hcherpre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub_3d.h"

void	gnl(t_game *game, char *file)
{
	char	*str;
	int		fd;

	game->line = 0;
	fd = open(file, O_RDONLY);
	str = get_next_line(fd);
	if (fd < 0 || !str)
	{
		write(2, "Error\nEmpty file\n", ft_strlen("Error\nEmpty file\n"));
		exit (1);
	}
	while (str)
	{
		free(str);
		game->line += 1;
		str = get_next_line(fd);
	}
	free(str);
	close(fd);
}

char	**fill_file(char *file, t_game *game)
{
	int		i;
	int		fd;
	char	**tab;
	char	*str;

	i = 0;
	gnl(game, file);
	fd = open(file, O_RDONLY);
	str = get_next_line(fd);
	if (!str)
		return (NULL);
	tab = malloc(sizeof(char *) * (game->line + 1));
	if (!tab)
		return (NULL);
	while (str)
	{
		tab[i++] = str;
		str = get_next_line(fd);
	}
	tab[i] = NULL;
	free(str);
	close(fd);
	return (tab);
}

int	check_file_name(char *file)
{
	if (open(file, O_RDONLY) == -1)
	{
		write(2, "Error\nCan't find file\n", ft_strlen("Error\nCan't find file\n"));
		return (0);
	}
	if (ft_strlen(file) < 5)
	{
		write(2, "Error\nIncorrect file\n", ft_strlen("Error\nIncorrect file\n"));
		return (0);
	}
	if (file[ft_strlen(file) - 1] != 'b' || file[ft_strlen(file) - 2] != 'u'
		|| file[ft_strlen(file) - 3] != 'c' || file[ft_strlen(file) - 4] != '.')
	{
		write(2, "Error\nIncorrect extention\n",
			ft_strlen("Error\nIncorrect extention\n"));
		return (0);
	}
	if (file[0] == '.')
	{
		write(2, "Error\nIncorrect format\n",
			ft_strlen("Error\nIncorrect format\n"));
		return (0);
	}
	return (1);
}
