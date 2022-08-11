/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarrier <fbarrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:30:31 by fbarrier          #+#    #+#             */
/*   Updated: 2021/12/01 15:30:31 by fbarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

char	*get_next_line(int fd);
char	*ft_cut_with_leftovers(int fd, char *left_str);
int		ft_strchr_gnl(char *s, int c);
char	*ft_strjoin_gnl(char *left_str, char *buff);
int		ft_strlen(char *s);
char	*ft_get_line(char *left_str);
char	*ft_reset_cursor(char *left_str);

#endif