/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_left.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:47:31 by aoudija           #+#    #+#             */
/*   Updated: 2023/02/10 09:11:25 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	morty_is_here(char *map, int count, int len)
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

static int	morty_is_here2(char *map, int count, int len)
{
	int	i;

	i = -1;
	while (map[++i])
	{
		if (i == len && map[len] == 'T'
			&& !pickle_exist(map))
		{
			map[i] = 'T';
			ft_putnbr_fd(++count, 1);
			write(1, "\ncongrats\n", 10);
			exit (0);
		}
		else if (i == len && map[len] == 'F'
			&& !pickle_exist(map))
		{
			map[i] = 'F';
			ft_putnbr_fd(++count, 1);
			write(1, "\ncongrats\n", 10);
			exit (0);
		}
	}
	return (count);
}

int	escp_norm(char *map, int hold_p, int count)
{
	int	i;

	count = morty_is_here(map, count, hold_p - 1);
	count = morty_is_here2(map, count, hold_p - 1);
	i = -1;
	while (map[++i])
	{
		if (i == hold_p - 1 && (map[hold_p - 1] == 'E' || map[hold_p - 1] == 'F'
				|| map[hold_p - 1] == 'T') && pickle_exist(map))
			map[hold_p] = 'P';
		else if (i == hold_p - 1 && map[hold_p - 1] != '1')
		{
			map[i] = 'P';
			ft_putnbr_fd(++count, 1);
			ft_putchar_fd('\n', 1);
		}
		else if (i == hold_p - 1 && map[hold_p - 1] == '1')
			map[hold_p] = 'P';
	}
	return (count);
}

int	player_left(char *map, int count)
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
	count = escp_norm(map, hold_p, count);
	return (count);
}
