/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: cbijman <cbijman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/09 17:50:08 by cbijman       #+#    #+#                 */
/*   Updated: 2022/12/12 12:11:46 by cbijman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*newstr;
	size_t	i;
	size_t	j;

	if (!s1 && !s2)
		return (NULL);
	newstr = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!newstr)
		return (free(s1), NULL);
	i = 0;
	j = 0;
	while (s1[i])
		newstr[j++] = s1[i++];
	i = 0;
	while (s2[i])
		newstr[j++] = s2[i++];
	newstr[j] = '\0';
	free(s1);
	return (newstr);
}

char	*ft_strcpy(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	if (!s2)
		return (NULL);
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

char	*ft_strrchr(const char *s1, char c)
{
	int	len;

	len = ft_strlen(s1);
	if (s1[len] == (char) c)
		return ((char *)&s1[len]);
	while (len--)
		if (s1[len] == (char) c)
			return ((char *)&s1[len]);
	return (0);
}

char	*ft_empty_string(void)
{
	char	*str;

	str = malloc(1);
	if (!str)
		return (NULL);
	str[0] = '\0';
	return (str);
}
