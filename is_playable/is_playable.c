/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_playable.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 19:17:14 by aoudija           #+#    #+#             */
/*   Updated: 2023/02/13 13:37:26 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	fill_p(char **s, int i, int j)
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

int	p_c(int p, int c)
{
	if (p == 1 || c > 0)
	{
		write(1, "Erorr\n", 6);
		write(1, "path err\n", 9);
		return (0);
	}
	return (1);
}

int	still_p_c(char **str)
{
	int	i;
	int	j;
	int	p;
	int	c;

	i = -1;
	p = 1;
	c = 0;
	while (str[++i])
	{
		j = -1;
		while (str[i][++j])
		{
			if (str[i][j] == 'C')
				c++;
			if (str[i][j] == 'P')
				p++;
		}
	}
	if (!p_c(p, c))
		return (ft_free(str), 0);
	return (1);
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
			if (str[x][y] == 'E' && (str[x + 1][y] != 'P'
				&& str[x - 1][y] != 'P' && str[x][y + 1] != 'P'
				&& str[x][y - 1] != 'P'))
			{
				write(1, "Erorr\npath err\n", 15);
				return (ft_free(str), free(map), 0);
			}
		}
	}
	if (!still_p_c(str))
		return (free(map), 0);
	return (ft_free(str), free(map), 1);
}
