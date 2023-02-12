/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 16:18:00 by aoudija           #+#    #+#             */
/*   Updated: 2023/02/12 19:36:30 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	heightt(char *path)
{
	int		height;
	char	*line;
	int		fd;

	height = 0;
	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (height);
}

void	fill(t_data data, char c, void *img_ptr)
{
	int		x;
	int		y;
	int		j;
	int		i;

	y = 0;
	i = -1;
	j = 1;
	x = 0;
	while (data.map[++i])
	{
		if (data.map[i] == c)
		{
			x = (j - 1) * 100;
			mlx_put_image_to_window(data.mlx, data.win, img_ptr, x, y);
		}
		if (data.map[i] == '\n')
		{
			y += 100;
			j = 0;
		}
		j++;
	}
}
