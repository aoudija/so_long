/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_rectangular.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:14:48 by aoudija           #+#    #+#             */
/*   Updated: 2023/02/12 16:34:34 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	optim(int width, char *path, int h)
{
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		if (h == 1)
		{
			if ((int)ft_strlen(line) != width - 1)
				return (0);
		}
		else if ((int)ft_strlen(line) != width)
			return (0);
		free(line);
		line = get_next_line(fd);
		h--;
	}
	free(line);
	return (1);
}

int	is_rectangular(char *path)
{
	int		fd;
	int		width;
	char	*line;
	int		h;

	h = heightt(path);
	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	free(line);
	close(fd);
	width = (int)ft_strlen(line);
	if (!optim(width, path, h))
		return (0);
	if (heightt(path) == width - 1)
		return (0);
	return (1);
}
