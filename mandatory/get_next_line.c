/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:26:12 by aoudija           #+#    #+#             */
/*   Updated: 2023/02/10 14:17:20 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_strchr(char *s, int c)
{
	size_t	i;

	i = 0;
	c = (char) c;
	if (!s)
		return (NULL);
	while (i <= ft_strlen(s))
	{
		if (s[i] == c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_read(int fd, char *buffer, char *t)
{
	int	i;

	i = 1;
	while (i)
	{
		i = read(fd, buffer, 1);
		if (i == -1)
		{
			if (t)
				free(t);
			return (NULL);
		}
		buffer[i] = 0;
		t = ft_strjoin(t, buffer);
		if (!t)
			return (NULL);
		if (ft_strchr(buffer, '\n') != 0)
			break ;
	}
	if (t[0] == 0)
	{
		free(t);
		return (NULL);
	}
	return (t);
}

char	*ft_line(char *str)
{
	int		i;
	char	*line;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\n' && str[i])
		i++;
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i])
	{
		line[i] = str[i];
		i++;
	}
	line[i] = str[i];
	line[i + 1] = 0;
	return (line);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*t;
	char		*line;

	buffer = malloc(1 + 1);
	if (!buffer)
		return (NULL);
	t = ft_read(fd, buffer, t);
	free(buffer);
	line = ft_line(t);
	t = ft_substr(t, ft_strlen(line), ft_strlen(t) - ft_strlen(line) + 1);
	return (line);
}
