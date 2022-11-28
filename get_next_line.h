/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: cbijman <cbijman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/07 18:51:27 by cbijman       #+#    #+#                 */
/*   Updated: 2022/11/28 18:21:30 by cbijman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <stddef.h>

char	*get_next_line(int fd);

size_t	ft_strlen_limiter(const char *str, char limiter);
char	*ft_strdup(const char *str);
char	*ft_calloc(int count, int type);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(const char *str, int start, size_t len);

#endif