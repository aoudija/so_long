/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bitems.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:36:07 by aoudija           #+#    #+#             */
/*   Updated: 2023/02/12 17:31:20 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	is_item(char *map)
{
	int	i;

	i = -1;
	while (map[++i])
	{
		if (map[i] != '1' && map[i] != '0' && map[i] != 'P'
			&& map[i] != 'E' && map[i] != 'C' && map[i] != '\n'
			&& map[i] != 'M')
			return (0);
	}
	return (1);
}

int	check_bitems(char *map)
{
	int	i;
	int	p;
	int	c;
	int	e;

	p = 0;
	e = 0;
	c = 0;
	i = -1;
	while (map[++i])
	{
		if (map[i] == 'P')
			p++;
		if (map[i] == 'C')
			c++;
		if (map[i] == 'E')
			e++;
	}
	if (!is_item(map) || p == 0 || p > 1 || e == 0 || e > 1 || c < 1)
		return (0);
	free(map);
	return (1);
}
