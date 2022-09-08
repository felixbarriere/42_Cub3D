#include "../../includes/cub_3d.h"

int    ft_check_elem(t_game *game)
{
    int            count;
    int            i;
    char        **tab;

    i = 0;
    count = 0;
    while (game->file[i])
    {
        if (game->file[i][0] != '\n')
        {
            tab = ft_split(game->file[i], ' ');
            if (!ft_is_elem_correct(tab, game, count))
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

int    ft_is_elem_correct(char **tab, t_game *game, int count)
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

int    ft_is_elem_correct_2(char **tab, t_game *game)
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
        return (0);
    return (1);
}

int    ft_file_correct(char **tab)
{
    int    i;
    int    j;

    i = 0;
    while (tab[i])
    {
        j = 0;
        while (tab[i][j])
        {
            if (tab[i][j] == '1' || tab[i][j] == '\n')
                j++;
            else
                return (0);
        }
        i++;
    }
    return (1);
}

void    ft_init_elem(t_game *game)
{
    game->element.north = 0;
    game->element.south = 0;
    game->element.west = 0;
    game->element.east = 0;
    game->element.floor = 0;
    game->element.ceilling = 0;
    game->element.index = 0;
}

int    ft_check_elem_2(char **tab)
{
    if (tab[0][0] == 'N' || tab[0][0] == 'S'
        || tab[0][0] == 'W' || tab[0][0] == 'E')
    {
        if (tab[2] != NULL || tab[1] == NULL)
            return (0);
        tab[1][ft_strlen(tab[1]) - 1] = '\0';
        if (open(tab[1], O_RDONLY) == -1)
            return (0);
    }
    else if (tab[0][0] == 'F' || tab[0][0] == 'C')
        if (!ft_check_color(tab[1]))
            return (0);
    return (1);
}

int    ft_check_color(char    *array)
{
    char    **tab;
    int        i;

    i = 0;
    tab = ft_split(array, ',');
    while (tab[i])
    {
        if (ft_atoi(tab[i]) >= 0 && ft_atoi(tab[i]) <= 255)
            i++;
        else
        {
            ft_free_array(tab);
            return (0);
        }
    }
    if (i != 3 || (i == 3 && tab[2][0] == '\n'))
    {
        ft_free_array(tab);
        return (0);
    }
    ft_free_array(tab);
    return (1);
}
