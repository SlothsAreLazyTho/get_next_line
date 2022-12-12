/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: cbijman <cbijman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/07 18:51:27 by cbijman       #+#    #+#                 */
/*   Updated: 2022/12/12 12:37:16 by cbijman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

/// @brief Write a function that returns a line read from a file descriptor
/// @param fd: The file descriptor to read from
/// @return Read line: correct behavior
/// and NULL if there is nothing else to read, or an error occurred
char	*get_next_line(int fd);
char	*ft_strjoin_free(char *s1, char *s2);

//Returns an empty string with 1 byte that only has the zero-terminator.
char	*ft_empty_string(void);
char	*ft_strrchr(const char *s1, char c);
char	*ft_strcpy(char *s1, char *s2);
size_t	ft_strlen(const char *str);

#endif