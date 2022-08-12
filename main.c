#include "includes/cub_3d.h"

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
		free(game->texture->floor);
		// game->texture->floor = NULL;
}

void	ft_print_map(char	**map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		printf("map[i]: %s", map[i]);
		i++;
	}
}

int	main(int	argc, char **argv)
{
	t_game	game;

	(void)argc;
	game.array = fill_array(argv[1], &game);
	


	ft_print_map(game.array);
	ft_init(&game);

	ft_free_all(&game);
	return (0);
}