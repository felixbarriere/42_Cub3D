#include "includes/cub_3d.h"

void	ft_init(t_game	*game)
{
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, 960, 540, "Cub3D");
	mlx_loop(game->mlx);
	game->img = mlx_new_image(game->mlx, 960, 540);
	// (void)game->mlx;
	// (void)game->mlx_win;
	free(game->mlx);
	free(game->mlx_win);
}