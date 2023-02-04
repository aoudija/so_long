/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_floor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 18:22:51 by aoudija           #+#    #+#             */
/*   Updated: 2023/02/04 21:36:31 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	return (height);
}

void	*floor_imgg(void *mlx)
{
	void	*floor_img;
	int		i;

	i = 50;
	floor_img = mlx_xpm_file_to_image(mlx, "images/floor.xpm", &i, &i);
	return (floor_img);
}

void	fill_floor(void *mlx, void *win, int fd)
{
	char	*line;
	int		x;
	int		y;
	int		i;

	line = get_next_line(fd);
	y = 100;
	while (line)
	{
		i = -1;
		x = 0;
		while (line[++i])
		{
			if (line[i] == '0')
			{
				x = i * 100;
				mlx_put_image_to_window(mlx, win, floor_imgg(mlx), x, y);
			}
		}
		free(line);
		line = get_next_line(fd);
		y += 100;
	}
	free(line);
}
