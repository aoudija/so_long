/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_playable.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 19:17:14 by aoudija           #+#    #+#             */
/*   Updated: 2023/02/12 14:33:37 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void fill_p(char **s, int i, int j)
{
	if (s[i + 1][j] == '0' || s[i + 1][j] == 'C')
	{
		s[i + 1][j] = 'P';	
		fill_p(s, i + 1, j);
	}
	if (s[i - 1][j] == '0' || s[i - 1][j] == 'C')
	{
		s[i - 1][j] = 'P';	
		fill_p(s, i - 1, j);
	}
	if (s[i][j + 1] == '0' || s[i][j + 1] == 'C')
	{
		s[i][j + 1] = 'P';	
		fill_p(s, i, j + 1);
	}
	if (s[i][j - 1] == '0' || s[i][j - 1] == 'C')
	{
		s[i][j - 1] = 'P';	
		fill_p(s, i, j - 1);
	}
}

int	still_p_e(char **str)
{
	int	i;
	int	j;
	int	e;
	int	p;

	i = -1;
	e = 0;
	p = 1;
	while (str[++i])
	{
		j = -1;
		while (str[i][++j])
		{
			if (str[i][j] == 'C')
				return (ft_free(str), 0);
			if (str[i][j] == 'E')
				e++;
			if (str[i][j] == 'P')
				p++;
		}
	}
	if (e > 1 || p == 1)
		return (0);
	return(1);
}

int	is_playable(char *map)
{
	int		x;
	int		y;
	char	**str;

	str = ft_split(map, '\n');
	fill_p(str, player_i(str), player_j(str));
	x = -1;
	while (str[++x])
	{
		y = -1;
		while (str[x][++y])
		{
			if (str[x][y] == 'E')
			{
				if (str[x + 1][y] != 'P' && str[x - 1][y] != 'P'
					&& str[x][y + 1] != 'P' && str[x][y - 1] != 'P')
					return (ft_free(str), free(map), 0);
			}
		}
	}
	if (!still_p_e(str))
		return (free(map), 0);
	return (ft_free(str), free(map), 1);
}
// free(map), ft_free(str),