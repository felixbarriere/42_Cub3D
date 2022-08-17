#include "../includes/cub_3d.h"

// void	*ft_img(void *mlx, char *path)
// {
// 	int		x;
// 	int		y;
// 	void	*test;

// 	x = 0;
// 	y = 0;
// 	test = mlx_xpm_file_to_image(mlx, path, &x, &y);
// 	return (test);
// }


// void	ft_fill_flo(t_game	*game, int x, int y, char **tab)
// {
// 	int	k;
// 	int	l;
// 	// (void)tab;
// 	// (void)x;
// 	// (void)y;

// 	k = 0;
// 	game->wall_img = ft_img(game->mlx, "../img/wall.xpm");
// 	while (k < y)
// 	{
// 		l = 0;
// 		while (l < x)
// 		{
// 			if (tab[k][l] == '1')
// 			{
// 				// printf("tab[k][l]: %c\n", tab[k][l]);
// 				// printf("l: %d\n", l);
// 				mlx_put_image_to_window(game->mlx, game->mlx_win,
// 					game->wall_img, l * 64, k * 64);
// 			}
// 			// else if (tab[k][l] == 'P' || tab[k][l] == '0' || tab[k][l] == 'C')
// 			// 	mlx_put_image_to_window(program->image.mlx, program->image.win,
// 			// 		program->image.floor, l * 64, k * 64);
// 			l++;
// 		}
// 		k++;
// 	}
// }