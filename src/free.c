#include "../includes/cub_3d.h"

void	ft_free_array(char **array)
{
	int	i;

	i = 0;
	while(array[i])
	{
		free(array[i]);
		i++;
	}
	free(array[i]);
	free(array);
}

void	ft_free_all(t_game	*game)
{
		ft_free_array(game->array);
		free(game->floor_id);
		free(game->ceilling_id);
		free(game->north_id);
		free(game->south_id);
		free(game->west_id);
		free(game->east_id);
}