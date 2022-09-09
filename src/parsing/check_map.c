/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarrier <fbarrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:08:39 by hcherpre          #+#    #+#             */
/*   Updated: 2022/09/09 16:17:40 by fbarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub_3d.h"

int    ft_check_map(t_game *game)
{
    if (!ft_check_map_2(game) || !ft_check_player(game))
        return (0);
    return (1);
}

int    ft_check_map_2(t_game *game)
{
    int    i;
    int    j;

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
                if (!ft_check_wall(game, i, j))
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

int    ft_check_wall(t_game *game, int i, int j)
{
    int    b;

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
    if (game->file[i][b] == '1')
        if (!ft_check_wall_2(game, i, j))
            return (0);
    return (1);
}
int    ft_check_wall_2(t_game *game, int i, int j)
{
    int    a;

    a = i;
    while (game->file[a][j])
    {
        if (game->file[a][j] == '1' || game->file[a][j] == ' ')
            break ;
        a++;
    }
    if (game->file[a][j] == ' ' || !game->file[a][j])
        return (0);
    a = i;
    while (a >= game->element.index)
    {
        if (game->file[a][j] == '1' || game->file[a][j] == ' ')
            break ;
        a--;
    }
    if (game->file[a][j] == ' ' || !game->file[a][j])
        return (0);
    return (1);
}

int    ft_check_player(t_game *game)
{
    int        i;
    int        j;
    int        count;

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