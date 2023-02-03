/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:01:44 by aoudija           #+#    #+#             */
/*   Updated: 2023/02/03 15:56:01 by aoudija          ###   ########.fr       */
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
	int		img_width;
	int		img_height;

	floor_img = mlx_xpm_file_to_image(mlx, "images/floor.xpm", &img_width, &img_height);
	return (floor_img);
}

void	fill_floor(void *mlx, void *win, int fd)
{
	void	*floor_img;
	char	*line;
	int		x;
	int		y;
	int		i;

	line = get_next_line(fd);
	printf("why\n");
	printf("@@@@%s\n", line);
	floor_img = floor_imgg(mlx);
	x = 0;
	y = 0;
	while (line)
	{
		i = 0;
		while (line[i])
		{
			printf(">>>>>>>>>>>>>>>>>>>>>%d\n", i);
			if (line[i] == '0')
			{
				x += 100;
				mlx_put_image_to_window(mlx, win, floor_img, x, y);
			}
			i++;
		}
		// free(line);
		line = get_next_line(fd);
		y += 100;
	}
	// free(line);
}

int	main(int ac, char *av[])
{
	void	*mlx;
	void	*win;
	int		fd;
	int		x;
	int		y;

	y = 0;
	fd = open(av[ac - 1], O_RDONLY);
	mlx = mlx_init();
	x = ft_strlen(get_next_line(fd)) * 100 - 100;
	y = heightt(av[ac - 1]) * 100;
	win = mlx_new_window(mlx, x, y, "Window");
	// fd = open(av[ac - 1], O_RDONLY);
	fill_floor(mlx, win, fd);
	mlx_loop(mlx);
	return (0);
}
