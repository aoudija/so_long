/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:26:12 by aoudija           #+#    #+#             */
/*   Updated: 2023/02/04 18:21:49 by aoudija          ###   ########.fr       */
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

char	*get_next_line(int fd)
{
	char	*line;
	int		len;
	int		i;

	i = -1;
	line = malloc(10000);
	while (line[i++] != '\n')
	{
		len = read(fd, &line[i], 1);
		if (i > 0 && len == 0)
			return (line);
		if (len <= 0)
			return (free(line), NULL);
	}
	line[i] = 0;
	return (line);
}
