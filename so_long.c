/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:01:44 by aoudija           #+#    #+#             */
/*   Updated: 2023/02/04 21:18:19 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char *av[])
{
	void	*mlx;
	void	*win;
	int		fd;
	char	*line;

	fd = open(av[ac - 1], O_RDONLY);
	mlx = mlx_init();
	line = get_next_line(fd);
	win = mlx_new_window(mlx, ft_strlen(line) * 100 - 100,
			heightt(av[ac - 1]) * 100, "Window");
	fill_floor(mlx, win, fd);
	fd = open(av[ac - 1], O_RDONLY);
	fill_wall(mlx, win, fd);
	fd = open(av[ac - 1], O_RDONLY);
	fill_RICK(mlx, win, fd);
	mlx_loop(mlx);
	return (0);
}
