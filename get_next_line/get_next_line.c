/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarrier <fbarrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:29:23 by fbarrier          #+#    #+#             */
/*   Updated: 2021/12/01 15:29:23 by fbarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

char	*ft_get_line(char *str)
{
	int		i;
	char	*str2;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	str2 = (char *)malloc(sizeof(char) * (i + 2));
	if (!str2)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		str2[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		str2[i] = str[i];
		i++;
	}
	str2[i] = '\0';
	return (str2);
}

char	*ft_reset_cursor(char *str)
{
	int		i;
	int		j;
	char	*str2;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	str2 = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!str2)
		return (NULL);
	i++;
	j = 0;
	while (str[i])
		str2[j++] = str[i++];
	str2[j] = '\0';
	free(str);
	return (str2);
}

char	*ft_cut_with_leftovers(int fd, char *str)
{
	char	*buff;
	int		read_bytes_number;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	read_bytes_number = 1;
	while (!ft_strchr_gnl(str, '\n') && read_bytes_number != 0)
	{
		read_bytes_number = read(fd, buff, BUFFER_SIZE);
		if (read_bytes_number == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[read_bytes_number] = '\0';
		str = ft_strjoin_gnl(str, buff);
	}
	free(buff);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*cursor = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	cursor = ft_cut_with_leftovers(fd, cursor);
	if (!cursor)
		return (0);
	line = ft_get_line(cursor);
	cursor = ft_reset_cursor(cursor);
	return (line);
}

/* int	main(void)
{
	char	*line;
	int		i;
	int		fd1;

	fd1 = open("../maps/test4.ber", O_RDONLY);
	i = 1;
	line = get_next_line(fd1);
	printf("line %d: %s", i++, line);
	while (line != 0)
	{
		printf("line %d: %s", i++, line);
		free(line);
		line = get_next_line(fd1);
	}
	close(fd1);
	return (0);
} */
