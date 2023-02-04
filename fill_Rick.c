/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_Rick.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 19:47:33 by aoudija           #+#    #+#             */
/*   Updated: 2023/02/04 21:40:51 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*Rick_img(void *mlx)
{
	void	*R_R;
	int		i;

	i = 50;
	R_R = mlx_xpm_file_to_image(mlx, "images/R_R.xpm", &i, &i);
	return (R_R);
}

void	fill_RICK(void *mlx, void *win, int fd)
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
			if (line[i] == 'P')
				mlx_put_image_to_window(mlx, win, Rick_img(mlx), x, y);
		}
		free(line);
		line = get_next_line(fd);
		y += 100;
	}
	free(line);
}
