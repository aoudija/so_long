/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_left.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:47:31 by aoudija           #+#    #+#             */
/*   Updated: 2023/02/06 16:19:27 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*player_left(char *map)
{
	int	i;
	int	hold_p;

	i = -1;
	while (map[++i])
	{
		if (map[i] == 'P')
		{
			hold_p = i;
			map[i] = '0';
		}
	}
	i = -1;
	while (map[++i])
	{
		if (i == hold_p - 1 && map[hold_p - 1] != '1')
			map[i] = 'P';
		else if (i == hold_p - 1 && map[hold_p - 1] == '1')
			map[hold_p] = 'P';
	}
	return (map);
}
