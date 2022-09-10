/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarrier <fbarrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 17:10:02 by fbarrier          #+#    #+#             */
/*   Updated: 2022/09/09 17:10:02 by fbarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub_3d.h"

int	ft_elt_pos_x(char	**array)
{
	int	i;
	int	j;

	i = 0;
	while (array[i])
	{
		j = 0;
		while (array[i][j])
		{
			if (array[i][j] == 'N' || array[i][j] == 'S'
				|| array[i][j] == 'E' || array[i][j] == 'W')
				return (j);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_elt_pos_y(char	**array)
{
	int	i;
	int	j;

	i = 0;
	while (array[i])
	{
		j = 0;
		while (array[i][j])
		{
			if (array[i][j] == 'N' || array[i][j] == 'S'
				|| array[i][j] == 'E' || array[i][j] == 'W')
				return (i);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_get_max_y(char	**array)
{
	int	y;
	int	x;
	int	max_y;

	y = 0;
	x = 0;
	max_y = 0;
	while (array[y][x])
	{
		while (array[y] && array[y][x] != '\0' && array[y][x] != ' ')
			y++;
		if (y >= max_y)
			max_y = y;
		y = 0;
		x++;
	}
	printf("maxy_y/ %d\n", max_y);
	return (max_y);
}

int	ft_get_max_x(char	**array)
{
	int	y;
	int	x;
	int	max_x;

	y = 0;
	x = 0;
	max_x = 0;
	while (array[y] && array[y][x])
	{
		if ((ft_strlen(array[y]) - 1) >= max_x)
			max_x = (ft_strlen(array[y]) - 1);
		y++;
	}
	printf("max_x: %d\n", max_x);
	return (max_x);
}
