/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: cbijman <cbijman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/07 18:51:27 by cbijman       #+#    #+#                 */
/*   Updated: 2022/11/08 15:46:01 by cbijman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stddef.h>

typedef struct s_list {
	int				fd;
	void			*content;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);

int	ft_strlen_limiter(char *s, char c);
int	is_newline(char *s);

#endif