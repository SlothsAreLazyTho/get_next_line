/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: cbijman <cbijman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 10:47:07 by cbijman       #+#    #+#                 */
/*   Updated: 2022/11/08 15:59:50 by cbijman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

char	*get_next_line(int fd)
{
	int		can_read;
	char	*line;
	static int	i;
	

	//Basic protections.
	if (fd == -1 || !fd)
		return (NULL);

	i = 0;
	line = malloc(BUFFER_SIZE * sizeof(char));
	if(!line)
		return (NULL);
	
	printf("%d", is_newline(&line[i]));
	while(is_newline(&line[i]) != 1)
	{
		if (i < BUFFER_SIZE)
		{
			can_read = read(fd, &line[i], BUFFER_SIZE);
			printf("Line: %s", &line[i]);
		}
	}
	return (line);
}


int main(void)
{
	int		fd = open("./assets/test01.txt", O_RDONLY);
	char	*line;
	line = get_next_line(fd);
	free(line);
	return (0);
}
