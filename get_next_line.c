/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: cbijman <cbijman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 10:47:07 by cbijman       #+#    #+#                 */
/*   Updated: 2022/11/28 18:15:04 by cbijman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>

int	has_newline(const char *s)
{
	size_t	i;

	i = ft_strlen_limiter(s, 0) - 1;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i--;
	}
	return (0);
}

char	*read_line(int fd, char *line)
{
	char	buff[BUFFER_SIZE + 1];
	int		can_read;

	while (can_read > 0 && !has_newline(buff))
	{
		can_read = read(fd, buff, BUFFER_SIZE);
		buff[can_read] = '\0';
		line = ft_strjoin(line, buff);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*buff;
	size_t		i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!line)
		line = ft_strdup("\0");
	i = 0;
	line = read_line(fd, line);
	printf("Original: %s\n", line);
	//buff = ft_substr(line, 0, ft_strlen_limiter(line, '\n'));
	//line = ft_substr(line, ft_strlen_limiter(line, '\n'), ft_strlen_limiter(buff, 0)); //Take left overs!
	//printf("Line: %s\tLeft: %s\n", buff, line);
	return (line);
}

int	main(void)
{
	int		fd = open("./assets/test01.txt", O_RDONLY);
	char	*line;
	for(int i = 0; i < 4; i++)
	{
		line = get_next_line(fd);
		//printf("Line: %s\n", line);
		//free(line);	
	}

	return (0);
}
