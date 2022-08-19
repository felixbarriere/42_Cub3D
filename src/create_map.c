#include "../includes/cub_3d.h"

void	*ft_img(void *mlx, char *path)
{
	int		x;
	int		y;
	void	*test;

	x = 0;
	y = 0;
	test = mlx_xpm_file_to_image(mlx, path, &x, &y);
	return (test);
}

void	ft_fill_flo(t_game	*game, int x, int y, char **tab)
{
	int	k;
	int	l;

	k = 0;
	while (k < y)
	{
		l = 0;
		while (l < x)
		{
			if (tab[k] && tab[k][l] && (tab[k][l] == '1' || tab[k][l] == ' '))
			{
				mlx_put_image_to_window(game->mlx, game->mlx_win,
					game->image.wall, l * 64, k * 64);
			}
			else if (tab[k] && tab[k][l] && tab[k][l] == '0')
				mlx_put_image_to_window(game->mlx, game->mlx_win,
					game->image.floor, l * 64, k * 64);
			l++;
		}
		k++;
	}
}
