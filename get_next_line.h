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

# if BUFFER_SIZE < 0
#  undef BUFFER_SIZE
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <stddef.h>

char	*get_next_line(int fd);

size_t	ft_strlen_limiter(const char *str, char limiter);
char	*ft_strdup(const char *str);
char	*ft_calloc(int count, int type);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(const char *str, int start, int len);

#endif