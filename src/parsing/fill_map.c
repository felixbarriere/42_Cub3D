/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarrier <fbarrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:08:47 by hcherpre          #+#    #+#             */
/*   Updated: 2022/09/10 16:42:05 by fbarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub_3d.h"

/*********remplace les espaces par des '1'*****************/

void    ft_space(t_game *game)
{
    int    i;
    int    j;
    int    count;

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

void    ft_fill_map(t_game *game, int count)
{
    int        i;
    int        j;
    int        k;
    char    **tab;

    i = game->element.index;
    while (game->file[i])
        i++;
    tab = malloc(sizeof(char *) * ((i - game->element.index) + 1));
    if (!tab)
        return ;
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
        if (j < count)
        {
            while (j < count)
            {
                tab[k][j] = '1';
                j++;
            }
        }
        tab[k][j] = '\0';
        i++;
        k++;
    }
    tab[k] = NULL;

	ft_free_array(game->file);
    ft_free_array(game->array);
    game->array = tab;
}


/***************cree un char ** contenant tout le fichier ****************/


void    gnl(t_game *game, char *file)
{
    char    *str;
    int        fd;

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

char    **fill_file(char *file, t_game *game)
{
    int        i;
    int        fd;
    char    **tab;
    char    *str;

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

int    check_file_name(char *file)
{
    if (open(file, O_RDONLY) == -1)
    {
        write(2, "Error\nCan't find file\n",
                        ft_strlen("Error\nCan't find file\n"));
        return (0);
    }
    if (ft_strlen(file) < 5)
    {
        write(2, "Error\nIncorrect file\n", 21);
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