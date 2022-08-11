#include "includes/cub_3d.h"


int	ft_is_map(char	*str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '1')
		return (1);
	else
		return (0);
}

static int	ft_count_lines(char *file)
{
	int		i;
	char	*line;
	int		fd;

	i = 0;
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (line && (ft_is_map(line) == 0))
	{
		free(line);
		line = get_next_line(fd);
	}
	while (line)
	{
		free(line);
		i++;
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (i);
}

char	**fill_array(char	*file)
{
	char	**tab;
	int		i;
	int		size;
	char	*line;
	int		fd;

	i = 0;
	size = ft_count_lines(file);
	tab = malloc((size + 1) * sizeof(char *));
	if (!(tab))
		return (NULL);
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (line && (ft_is_map(line) == 0))
	{
		// printf("ft_map == 0: %s", line);
		free(line);
		line = get_next_line(fd);
	}
	while (line != 0)
	{
		tab[i] = line;
		i++;
		line = get_next_line(fd);
	}
	tab[i] = NULL;
	free(line);
	close(fd);
	return (tab);
}

// char	*ft_strcpy2(char *dst, char *src)
// {
// 	int	i;

// 	i = 0;
// 	while (src[i])
// 	{
// 		dst[i] = src[i];
// 		i++;
// 	}
// 	dst[i] = '\0';
// 	return (dst);
// }



