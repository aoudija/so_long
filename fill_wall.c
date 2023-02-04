/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 19:09:01 by aoudija           #+#    #+#             */
/*   Updated: 2023/02/04 19:45:47 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*wall_img(void *mlx)
{
	void	*wall_img;
	int		i;

	i = 50;
	wall_img = mlx_xpm_file_to_image(mlx, "images/wall.xpm", &i, &i);
	return (wall_img);
}

void	fill_wall(void *mlx, void *win, int fd)
{
	char	*line;
	int		x;
	int		y;
	int		i;

	line = get_next_line(fd);
	y = 0;
	while (line)
	{
		i = -1;
		while (line[++i])
		{
			x = i * 100;
			if (line[i] == '1')
				mlx_put_image_to_window(mlx, win, wall_img(mlx), x, y);
		}
		free(line);
		line = get_next_line(fd);
		y += 100;
	}
	free(line);
}
