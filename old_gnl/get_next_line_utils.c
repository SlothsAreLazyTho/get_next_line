/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: cbijman <cbijman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 11:01:14 by cbijman       #+#    #+#                 */
/*   Updated: 2022/12/05 11:44:19 by cbijman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdlib.h>
#include <string.h>

size_t	ft_strlen_limiter(const char *str, char limiter)
{
	size_t	size;

	size = 0;
	if (!limiter)
		limiter = '\0';
	while (str[size] != limiter && str[size])
		size++;
	if (str[size] == '\n')
		size++;
	return (size);
}

char	*ft_calloc(int count, int type)
{
	char	*str;

	str = (char *)malloc(count * type);
	if (!str)
		return (NULL);
	while (count--)
		str[count] = 0;
	return (str);
}

//S1 is the left string and s2 the buffer.
char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;
	
	i = 0;
	j = 0;
	str = ft_calloc((ft_strlen_limiter(s1, '\0')
				+ ft_strlen_limiter(s2, '\0') + 1), sizeof(char));
	if (!str)
		return (NULL);
	while (s1[i])
		str[j++] = s1[i++];
	i = 0;
	while (s2[i])
		str[j++] = s2[i++];
	str[j] = '\0';
	free(s1);
	return (str);
}

char	*ft_strdup(const char *str)
{
	char	*nstr;
	size_t	i;
	size_t	len;

	if (!str)
		return (NULL);
	len = 0;
	i = -1;
	while (str[len])
		len++;
	nstr = ft_calloc(len + 1, sizeof(char));
	if (!nstr)
		return (NULL);
	while (str[++i])
		nstr[i] = str[i];
	return (nstr);
}