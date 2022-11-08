/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: cbijman <cbijman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 11:01:14 by cbijman       #+#    #+#                 */
/*   Updated: 2022/11/08 15:47:30 by cbijman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen_limiter(char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

int	is_newline(char *s)
{
	int	i;
	
	while(s[i] == '\n' && s[i] != '\0')
		return (1);
	return (0);
}
