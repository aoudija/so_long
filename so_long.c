/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:01:44 by aoudija           #+#    #+#             */
/*   Updated: 2023/02/05 17:15:06 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mapping(t_data m_w, char *map)
{
	fill(m_w ,map, '1', wall_img(m_w.mlx));
	fill(m_w ,map, '0', floor_img(m_w.mlx));
	fill(m_w ,map, 'C', pickle_img(m_w.mlx));
	fill(m_w ,map, 'P', rick_img(m_w.mlx));
	fill(m_w ,map, 'E', hole_img(m_w.mlx));
}

char	*mapp(char *path)
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
	t_data	m_w;
	int		fd;
	char	*line;
	char	*map;

	map = mapp(av[ac - 1]);
	fd = open(av[ac - 1], O_RDONLY);
	line = get_next_line(fd);
	m_w.mlx = mlx_init();
	m_w.win = mlx_new_window(m_w.mlx, ft_strlen(line) * 100 - 100,
			heightt(av[ac - 1]) * 100, "Window");
	mapping(m_w ,map);
	mlx_loop(m_w.mlx);
	return (0);
}
