/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 10:06:11 by aoudija           #+#    #+#             */
/*   Updated: 2023/02/13 13:21:18 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	mapping_bonus(t_data data)
{
	mlx_clear_window(data.mlx, data.win);
	fill(data, '1', data.wall);
	fill(data, '0', data.floor);
	fill(data, 'C', data.pickle);
	fill(data, 'E', data.exit);
	fill(data, 'T', data.exit_t);
	fill(data, 'F', data.exit_f);
	fill(data, 'P', data.rick);
	fill(data, 'M', data.morty);
}

char	*put_map(char *path)
{
	char	*map;
	char	*line;
	int		fd;

	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	map = 0;
	while (line)
	{
		map = ft_strjoin(map, line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
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
	{
		write(1, "Erorr\n", 6);
		write(1, ".ber\n", 5);
		return (0);
	}
	return (1);
}

static int	error(char *path)
{
	if (!is_brr(path) || !check_bitems(put_map(path))
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
			return (0);
		data.map = put_map(av[ac - 1]);
		fd = open(av[ac - 1], O_RDONLY);
		line = get_next_line(fd);
		data.mlx = mlx_init();
		filler(&data);
		data.win = mlx_new_window(data.mlx, ft_strlen(line) * 100 - 100,
				heightt(av[ac - 1]) * 100, "Window");
		free(line);
		mapping_bonus(data);
		mlx_hook(data.win, 2, 0, key_press_bonus, &data);
		mlx_hook(data.win, 17, 0, on_close, NULL);
		mlx_loop_hook(data.mlx, frame, &data);
		mlx_loop(data.mlx);
	}
	return (0);
}
