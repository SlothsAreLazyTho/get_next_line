/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: cbijman <cbijman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/07 18:51:27 by cbijman       #+#    #+#                 */
/*   Updated: 2022/11/30 16:32:49 by cbijman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# include <string.h>
# include <stdio.h>

char	*get_next_line(int fd);
char	*ft_strjoin_free(char *s1, char *s2);
size_t	ft_strlcpy(char *dst, char *src, size_t size);
char	*ft_empty_string(void);
size_t	ft_strlen(char *str);

#endif