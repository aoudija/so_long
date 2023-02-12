/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:42:19 by aoudija           #+#    #+#             */
/*   Updated: 2023/02/12 16:34:19 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	normi(char *line)
{
	int	j;

	j = 0;
	while (j < (int)ft_strlen(line) - 1)
	{
		if (line[j] != '1')
			return (0);
		j++;
	}
	return (1);
}

int	norma(char *line)
{
	int	j;

	j = -1;
	while (line[++j])
	{
		if (line[0] != '1'
			|| line[ft_strlen(line) - 2] != '1')
			return (0);
	}
	return (1);
}

int	chekck_walls(char *path)
{
	int		i;
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	i = heightt(path);
	while (line)
	{
		if (i == 1 || i == heightt(path))
		{
			if (!normi(line))
				return (free(line), 0);
		}
		if (i != 1 && i != heightt(path))
		{
			if (!norma(line))
				return (free(line), 0);
		}
		free(line);
		line = get_next_line(fd);
		i--;
	}
	free(line);
	return (1);
}
