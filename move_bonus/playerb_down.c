/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playerb_down.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:57:18 by aoudija           #+#    #+#             */
/*   Updated: 2023/02/10 13:25:50 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	morty_is_here2(t_data *data, int count, int len)
{
	int	i;

	i = -1;
	while (data->map[++i])
	{
		if (i == len && data->map[len] == 'F'
			&& !pickle_exist(data->map))
		{
			data->map[i] = 'F';
			++count;
			write(1, "\ncongrats\n", 10);
			exit (0);
		}
		else if (i == len && data->map[len] == 'T'
			&& !pickle_exist(data->map))
		{
			data->map[i] = 'T';
			++count;
			write(1, "\ncongrats\n", 10);
			exit (0);
		}
	}
	return (count);
}

static int	morty_is_here1(t_data *data, int count, int len)
{
	int	i;

	i = -1;
	while (data->map[++i])
	{
		if (i == len && data->map[len] == 'E'
			&& !pickle_exist(data->map))
		{
			data->map[i] = 'E';
			++count;
			write(1, "\ncongrats\n", 10);
			exit (0);
		}
		else if (i == len && data->map[len] == 'M')
		{
			data->map[i] = 'M';
			++count;
			write(1, "\nlost\n", 6);
			exit (0);
		}
	}
	return (count);
}

int	escape_norma(t_data *data, int hold_p, int hold_n, int count)
{
	int	i;

	i = -1;
	count = morty_is_here1(data, count, hold_p + hold_n + 1);
	count = morty_is_here2(data, count, hold_p + hold_n + 1);
	while (data->map[++i])
	{
		if (i == hold_p + hold_n + 1 && (data->map[hold_p + hold_n + 1] == 'E'
				|| data->map[hold_p + hold_n + 1] == 'F'
				|| data->map[hold_p + hold_n + 1] == 'T')
			&& pickle_exist(data->map))
				data->map[hold_p] = 'P';
		else if (i == hold_p + hold_n + 1
			&& data->map[hold_p + hold_n + 1] != '1')
		{
			data->map[i] = 'P';
			++count;
		}
		else if (i == hold_p + hold_n + 1
			&& data->map[hold_p + hold_n + 1] == '1')
			data->map[hold_p] = 'P';
	}
	return (count);
}

int	playerb_down(t_data *data, int count)
{
	int	i;
	int	hold_p;
	int	hold_n;

	i = -1;
	while (data->map[++i])
	{
		if (data->map[i] == 'P')
		{
			hold_p = i;
			data->map[i] = '0';
		}
	}
	hold_n = -1;
	while (data->map[++hold_n] != '\n')
		;
	count = escape_norma(data, hold_p, hold_n, count);
	return (count);
}
