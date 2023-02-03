/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:26:12 by aoudija           #+#    #+#             */
/*   Updated: 2023/02/03 15:08:37 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int		i;

	c = (char)c;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == c)
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	int		i;
	char	*buffer;
	char	*join;

	i = 1;
	buffer = malloc(2);
	while (i)
	{
		i = read(fd, buffer, 1);
		if (i == 0)
			break ;
		if (i == -1)
		{
			if (join)
				free(join);
			return (NULL);
		}
		buffer[i] = 0;
		join = ft_strjoin(join, buffer);
		if (ft_strchr(buffer, '\n') != 0)
			break ;
	}
	free(buffer);
	return (join);
}
