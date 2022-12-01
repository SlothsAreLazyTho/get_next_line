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
#include <string.h>

int		has_newline(const char *s)
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

char	*take_string(char *str)
{
	int		i;
	char	*nstr;

	i = 0;
	while(str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\0')
		return (NULL);
	i++;
	nstr = ft_calloc(i, sizeof(char));
	if (!nstr)
		return (NULL);
	strncpy(nstr, str, i); //Integrate to utils
	free(str);
	return (nstr);
}

char	*take_left(char *str)
{
	int		i;
	int		j;
	char	*nstr;

	i = 0;
	j = 0;
	while(str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\0')
		return (NULL);
	i++;
	nstr = ft_calloc(i, sizeof(char));
	if (!nstr)
		return (NULL);
	strcpy(nstr, &str[i]); //Integrate to utils
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
	if (!buff)
		return (NULL);
	line = take_left(buff);
	buff = take_string(buff);
	return (buff);
}

int	main(void)
{
	int		fd = open("./assets/test01.txt", O_RDONLY);
	char	*line;
	for(int i = 0; i < 5; i++)
	{
		line = get_next_line(fd);
		printf("Line: %s", line);
		free(line);
	}
	//system("leaks get_next_line");
	return (0);
}
