/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: bowie <cbijman@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/08 17:01:38 by cbijman       #+#    #+#                 */
/*   Updated: 2022/12/09 13:19:41 by bowie         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(int fd, char *line)
{
	char	buffer[BUFFER_SIZE + 1];
	int		s;

	s = 1;
	while (s != 0 && !strchr(buffer, '\n'))
	{
		s = read(fd, buffer, BUFFER_SIZE);
		if (s < 0)
			return (free(line), NULL);
		buffer[s] = '\0';
		line = ft_strjoin_free(line, buffer);
		if (!line)
			return (NULL);
	}
	return (line);
}

//Take string takes a complete string and convert it. Because we have to 
//Remember to copy our newline to the string we must check if the string
//have a new line, if not we just add 1 for the zero-terminator.
char	*take_string(char *str)
{
	size_t	i;
	size_t	len;
	char	*nstr;

	i = 0;
	len = 0;
	while (str[len] != '\n' && str[len])
		len++;
	if (str[len] == '\n')
		len += 2;
	else
		len += 1;
	nstr = malloc(len);
	if (!nstr)
		return (NULL);
	while (str[i] != '\n' && str[i])
	{
		nstr[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		nstr[i++] = '\n';
	nstr[i] = '\0';
	return (nstr);
}

//Takes the left overs from the complete string. Everything after the newline
//should be copied to a new string and the old leftover string should be freed
//correctly.
char	*take_left(char *str)
{
	size_t	i;
	size_t	len;
	char	*nstr;

	i = 0;
	len = 0;
	while (str[i] != '\n' && str[i]) //Changing index to end of newline.
		i++;
	if (str[i] == '\0')
		return (NULL);
	i++;
	len = ft_strlen(&str[i]);
	nstr = malloc(len + 1);
	if (!nstr)
		return (NULL);
	strcpy(nstr, str + i); //Write simple strcpy method.
	free(str);
	return (nstr);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*buff;

	if (fd < 0 || BUFFER_SIZE < 0 || BUFFER_SIZE > __INT_MAX__)
		return (NULL);
	if (!line)
		line = ft_empty_string();
	line = read_line(fd, line);
	if (!line)
		return (NULL);
	buff = take_string(line);
	if (!buff)
		return (free(line), NULL);
	line = take_left(line);
	return (buff);
}

//int	main(int argc, char const *argv[])
//{
//	int		fd;
//	char	*line;

//	fd = open("./assets/test01.txt", O_RDONLY);
//	for (int i = 0; i < 2; i++)
//	{
//		line = get_next_line(fd);
//		printf("Line: %s", line);
//		if (!line)
//			printf("\n");
//		free(line);
//	}
//	close(fd);
//	return (0);
//}
