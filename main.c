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
	game.array = fill_array(argv[1], &game);

	// il faudra réajuster la map en ajoutant des 1 a la place des espaces 
	// exterieurs pour allouer correctement + allouer en fonction de la + grande size.

	ft_print_map(game.array);
	ft_init(&game);
	return (0);
}