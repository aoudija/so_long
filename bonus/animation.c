/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:38:07 by aoudija           #+#    #+#             */
/*   Updated: 2023/02/12 14:17:53 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static char	*put_m_o(char *map)
{
	int	i;

	i = -1;
	while (map[++i])
	{
		if (map[i] == 'M' && map[i + 1] == '0')
		{
			map[i] = '0';
			map[i + 1] = 'M';
			i++;
		}
		else if (map[i] == 'M' && map[i - 1] == '0' && map[i + 1] != '0')
		{
			while (map[i - 1] == '0')
			{
				map[i] = '0';
				map[i - 1] = 'M';
				i--;
			}
			i++;
		}
	}
	return (map);
}

void	evil_morty(t_data *data)
{
	data->map = put_m_o(data->map);
}
