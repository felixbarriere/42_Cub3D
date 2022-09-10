/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarrier <fbarrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:09:03 by fbarrier          #+#    #+#             */
/*   Updated: 2022/09/10 17:09:08 by fbarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub_3d.h"

static int	count_words(char *str, char sep)
{
	int	i;
	int	word_nb;

	i = 0;
	word_nb = 0;
	while (*str)
	{
		if (*str != sep && word_nb == 0)
		{
			word_nb = 1;
			i++;
		}
		else if (*str == sep)
			word_nb = 0;
		str++;
	}
	return (i);
}

static char	*word_dup(char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *s, char c)
{
	int		i;
	int		j;
	int		index;
	char	**final;

	final = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!s || !(final))
		return (0);
	i = 0;
	j = 0;
	index = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index == -1)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			final[j++] = word_dup(s, index, i);
			index = -1;
		}
		i++;
	}
	final[j] = 0;
	return (final);
}
