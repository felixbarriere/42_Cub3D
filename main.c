#include "includes/cub_3d.h"

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
	game.array = NULL;
	game.floor_id = NULL;
	game.ceilling_id = NULL;
	game.array = fill_array(argv[1], &game);

	// pk la MLX ne prend pas north_id?
	printf("game->north_id: %s", game.north_id);
	printf("lenght game->north_id: %d", ft_strlen(game.north_id));
	// il faudra réajuster la map en ajoutant des 1 a la place des espaces 
	// exterieurs pour allouer correctement.

	ft_print_map(game.array);
	ft_start(&game);
	return (0);
}