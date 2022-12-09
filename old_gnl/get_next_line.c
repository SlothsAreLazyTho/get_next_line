/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: cbijman <cbijman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 10:47:07 by cbijman       #+#    #+#                 */
/*   Updated: 2022/12/05 13:49:46 by cbijman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
			return (free(line), NULL);
	}
	return (line);
}

char	*take_string(char *str)
{
	int		i;
	char	*nstr;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\0')
		i++;
	else
		i += 2;
	nstr = ft_calloc(i, sizeof(char));
	if (!nstr)
		return (NULL);
	if (str[i] == '\n')
		nstr[i] = '\n';
	i--;
	while (i--)
		nstr[i] = str[i];
	return (nstr);
}

char	*take_left(char *str)
{
	int		i;
	int		j;
	char	*nstr;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\0')
		return (NULL);
	i++;
	j = ft_strlen_limiter(&str[i], '\0');
	nstr = ft_calloc(j, sizeof(char));
	if (!nstr)
		return (free(nstr), NULL);
	strcpy(nstr, &str[i]);
	return (nstr);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*buff;

	if (fd < 0)
		return (NULL);
	if (!line)
		line = ft_strdup("\0");
	line = read_line(fd, line);
	if (!line)
		return (NULL);
	buff = take_string(line);
	if (!buff)
		return (NULL);
	line = take_left(line);
	if (!line)
		return (free(line), NULL);
	return (buff);
}

//int	main(void)
//{
//	int		fd = open("./assets/test02.txt", O_RDONLY);
//	char	*line;
//	for(int i = 0; i < 10000; i++)
//	{
//		line = get_next_line(fd);
//		printf("Line: %s", line);
//		//free(line);
//	}
//	//system("leaks get_next_line");
//	return (0);
//}
