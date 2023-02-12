/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_down.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:57:18 by aoudija           #+#    #+#             */
/*   Updated: 2023/02/10 19:04:09 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	morty_is_here2(char *map, int count, int len)
{
	int	i;

	i = -1;
	while (map[++i])
	{
		if (i == len && map[len] == 'F'
			&& !pickle_exist(map))
		{
			map[i] = 'F';
			ft_putnbr_fd(++count, 1);
			write(1, "\ncongrats\n", 10);
			exit (0);
		}
		else if (i == len && map[len] == 'T'
			&& !pickle_exist(map))
		{
			map[i] = 'T';
			ft_putnbr_fd(++count, 1);
			write(1, "\ncongrats\n", 10);
			exit (0);
		}
	}
	return (count);
}

static int	morty_is_here1(char *map, int count, int len)
{
	int	i;

	i = -1;
	while (map[++i])
	{
		if (i == len && map[len] == 'E'
			&& !pickle_exist(map))
		{
			map[i] = 'E';
			ft_putnbr_fd(++count, 1);
			write(1, "\ncongrats\n", 10);
			exit (0);
		}
		else if (i == len && map[len] == 'M')
		{
			map[i] = 'M';
			ft_putnbr_fd(++count, 1);
			write(1, "\nlost\n", 6);
			exit (0);
		}
	}
	return (count);
}

int	escape_norma(char *map, int hold_p, int hold_n, int count)
{
	int	i;

	i = -1;
	count = morty_is_here1(map, count, hold_p + hold_n + 1);
	count = morty_is_here2(map, count, hold_p + hold_n + 1);
	while (map[++i])
	{
		if (i == hold_p + hold_n + 1 && (map[hold_p + hold_n + 1] == 'E'
				|| map[hold_p + hold_n + 1] == 'F'
				|| map[hold_p + hold_n + 1] == 'T')
			&& pickle_exist(map))
				map[hold_p] = 'P';
		else if (i == hold_p + hold_n + 1 && map[hold_p + hold_n + 1] != '1')
		{
			map[i] = 'P';
			ft_putnbr_fd(++count, 1);
			ft_putchar_fd('\n', 1);
		}
		else if (i == hold_p + hold_n + 1 && map[hold_p + hold_n + 1] == '1')
			map[hold_p] = 'P';
	}
	return (count);
}

int	player_down(char *map, int count)
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
	count = escape_norma(map, hold_p, hold_n, count);
	return (count);
}
