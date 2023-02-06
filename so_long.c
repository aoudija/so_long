/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:01:44 by aoudija           #+#    #+#             */
/*   Updated: 2023/02/06 15:48:38 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mapping(t_data data)
{
	fill(data, '1', wall_img(data.mlx));
	fill(data, '0', floor_img(data.mlx));
	fill(data, 'C', pickle_img(data.mlx));
	fill(data, 'P', rick_img(data.mlx));
	fill(data, 'E', hole_img(data.mlx));
}

char	*put_map(char *path)
{
	char	*map;
	char	*line;
	int		fd;

	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	map = malloc(ft_strlen(line) * heightt(path) + 1);
	while (line)
	{
		map = ft_strjoin(map, line);
		free(line);
		line = get_next_line(fd);
	}
	return (map);
}

int	main(int ac, char *av[])
{
	t_data	data;
	int		fd;
	char	*line;

	data.map = put_map(av[ac - 1]);
	fd = open(av[ac - 1], O_RDONLY);
	line = get_next_line(fd);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, ft_strlen(line) * 100 - 100,
			heightt(av[ac - 1]) * 100, "Window");
	mapping(data);
	mlx_key_hook(data.win, key_press, &data);
	mlx_loop(data.mlx);
	return (0);
}
