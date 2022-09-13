/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_identifiers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarrier <fbarrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 17:09:24 by fbarrier          #+#    #+#             */
/*   Updated: 2022/09/09 17:09:24 by fbarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub_3d.h"

char	*get_identifier_3(char *line, int i)
{
	while (line[i] != '.')
			i++;
	return (ft_substr(line, i, (ft_strlen(line) - i - 1)));
}

char	*get_identifier_2(char *line, int i)
{
	while (line[i] < '0' || line[i] > '9')
			i++;
	return (ft_substr(line, i, (ft_strlen(line) - i + 1)));
}

void	get_identifier(char	*line, t_game	*game)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] == 'F')
		game->floor_id = get_identifier_2(line, i);
	else if (line[i] == 'C')
		game->ceilling_id = get_identifier_2(line, i);
	else if (line[i] == 'N')
		game->north_id = get_identifier_3(line, i);
	else if (line[i] == 'S')
		game->south_id = get_identifier_3(line, i);
	else if (line[i] == 'W')
		game->west_id = get_identifier_3(line, i);
	else if (line[i] == 'E')
		game->east_id = get_identifier_3(line, i);
}
