#include "cub_3d.h"

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

int	main(int	argc, char **argv)
{
	t_game	game;
	int	i;

	(void)argc;
	i = 0;
	game.array = fill_array(argv[1]);
	while (game.array[i])
	{
		printf("game.tab[i]: %s", game.array[i]);
		i++;
	}
	ft_free_array(game.array);
	return (0);
}