/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_down.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:57:18 by aoudija           #+#    #+#             */
/*   Updated: 2023/02/06 16:20:15 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*player_down(char *map)
{
	int	i;
	int	hold_p;
	int	hold_n;

	i = -1;
	while (map[++i])
	{
		if (map[i] == 'P')
		{
			hold_p = i;
			map[i] = '0';
		}
	}
	hold_n = -1;
	while (map[++hold_n] != '\n')
		;
	i = -1;
	while (map[++i])
	{
		if (i == hold_p + hold_n + 1 && map[hold_p + hold_n + 1] != '1')
			map[i] = 'P';
		else if (i == hold_p + hold_n + 1 && map[hold_p + hold_n + 1] == '1')
			map[hold_p] = 'P';
	}
	return (map);
}
