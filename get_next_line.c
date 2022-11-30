/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: cbijman <cbijman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 10:47:07 by cbijman       #+#    #+#                 */
/*   Updated: 2022/11/30 16:43:40 by cbijman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

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

	can_read = 1;
	while (can_read > 0 && !has_newline(buff))
	{
		can_read = read(fd, buff, BUFFER_SIZE);
		if (can_read < 0)
			return (NULL);
		buff[can_read] = '\0';
		line = ft_strjoin(line, buff);
		if (!line)
			return (NULL);
	}
	return (line);
}

char *take_left(char *str)
{
	int		i;
	char	*nstr;
	while(str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\0')
	{
		printf("Line: %s", str);
		return (NULL);
	}
	i++;
	nstr = ft_strdup(&str[i]);
	if (!nstr)
		return (NULL);
	free(str);
	printf("%s", nstr);
	return (nstr);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*buff;
	size_t		i;

	if (fd < 0)
		return (NULL);
	if (!line)
		line = ft_strdup("\0");
	i = 0;
	buff = read_line(fd, line);
	
	line = take_left(buff);
	//buff = ft_substr(buff, 0, ft_strlen_limiter(buff, '\n'));
	printf("%s\n", buff);
	printf("Left: { %s }", line);
	return (buff);
}

int	main(void)
{
	int		fd = open("./assets/test01.txt", O_RDONLY);
	char	*line;
	for(int i = 0; i < 1; i++)
	{
		line = get_next_line(fd);
		//printf("Line: %s", line);
		free(line);	
	}
	//system("leaks get_next_line");
	return (0);
}
