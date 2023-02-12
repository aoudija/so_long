/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 07:32:21 by aoudija           #+#    #+#             */
/*   Updated: 2023/02/12 20:23:27 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	frame(t_data *data)
{
	int		i;
	char	*map;
	char	*str;

	i = -1;
	map = data->map;
	while (map[++i])
	{
		if (map[i] == 'E' || map[i] == 'T'
			|| map[i] == 'F')
			break ;
	}
	if (data->map[i] == 'E')
		data->map[i] = 'T';
	else if (data->map[i] == 'F')
		data->map[i] = 'E';
	else if (data->map[i] == 'T')
		data->map[i] = 'F';
	mapping_bonus(*data);
	str = ft_itoa(data->count);
	mlx_string_put(data->mlx, data->win, 5, 5, 0xFF000, str);
	free(str);
	evil_morty(data);
	usleep(150000);
	return (0);
}
