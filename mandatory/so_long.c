/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:01:44 by aoudija           #+#    #+#             */
/*   Updated: 2023/02/12 20:09:09 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	mapping(t_data data)
{
	mlx_clear_window(data.mlx, data.win);
	fill(data, '1', data.wall);
	fill(data, '0', data.floor);
	fill(data, 'C', data.pickle);
	fill(data, 'E', data.exit);
	fill(data, 'P', data.rick);
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
	close(fd);
	return (map);
}

static int	is_brr(char *path)
{
	int	len;
	int	i;

	i = -1;
	len = (int)ft_strlen(path);
	if (len < 5)
		return (0);
	len--;
	if (path[len] != 'r' || path[len - 1] != 'e'
		|| path[len - 2] != 'b' || path[len - 3] != '.')
		return (0);
	return (1);
}

static int	error(char *path)
{
	if (!is_brr(path) || !check_items(put_map(path))
		|| !is_rectangular(path) || !chekck_walls(path)
		|| !is_playable(put_map(path)))
		return (0);
	return (1);
}

int	main(int ac, char *av[])
{
	t_data	data;
	int		fd;
	char	*line;

	if (ac == 2)
	{
		if (!error(av[ac - 1]))
		{
			write(1, "Error!\n", 7);
			return (0);
		}
		data.map = put_map(av[ac - 1]);
		fd = open(av[ac - 1], O_RDONLY);
		line = get_next_line(fd);
		data.mlx = mlx_init();
		data.win = mlx_new_window(data.mlx, ft_strlen(line) * 100 - 100,
				heightt(av[ac - 1]) * 100, "Window");
		free(line);
		close(fd);
		data.floor = floor_img(data.mlx);
		data.wall = wall_img(data.mlx);
		data.pickle = pickle_img(data.mlx);
		data.exit = hole_img(data.mlx);
		data.rick = rick_img(data.mlx);
		mapping(data);
		mlx_hook(data.win, 2, 0, key_press, &data);
		mlx_hook(data.win, 17, 0, on_close, NULL);
		mlx_loop(data.mlx);
	}
	return (0);
}
