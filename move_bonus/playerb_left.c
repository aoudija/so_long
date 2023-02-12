/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playerb_left.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:47:31 by aoudija           #+#    #+#             */
/*   Updated: 2023/02/10 13:28:15 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	morty_is_here(t_data *data, int count, int len)
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

static int	morty_is_here2(t_data *data, int count, int len)
{
	int	i;

	i = -1;
	while (data->map[++i])
	{
		if (i == len && data->map[len] == 'T'
			&& !pickle_exist(data->map))
		{
			data->map[i] = 'T';
			++count;
			write(1, "\ncongrats\n", 10);
			exit (0);
		}
		else if (i == len && data->map[len] == 'F'
			&& !pickle_exist(data->map))
		{
			data->map[i] = 'F';
			++count;
			write(1, "\ncongrats\n", 10);
			exit (0);
		}
	}
	return (count);
}

int	escp_norm(t_data *data, int hold_p, int count)
{
	int	i;

	count = morty_is_here(data, count, hold_p - 1);
	count = morty_is_here2(data, count, hold_p - 1);
	i = -1;
	while (data->map[++i])
	{
		if (i == hold_p - 1 && (data->map[hold_p - 1] == 'E'
				|| data->map[hold_p - 1] == 'F'
				|| data->map[hold_p - 1] == 'T') && pickle_exist(data->map))
			data->map[hold_p] = 'P';
		else if (i == hold_p - 1 && data->map[hold_p - 1] != '1')
		{
			data->map[i] = 'P';
			++count;
		}
		else if (i == hold_p - 1 && data->map[hold_p - 1] == '1')
			data->map[hold_p] = 'P';
	}
	return (count);
}

int	playerb_left(t_data *data, int count)
{
	int	i;
	int	hold_p;

	i = -1;
	while (data->map[++i])
	{
		if (data->map[i] == 'P')
		{
			hold_p = i;
			data->map[i] = '0';
		}
	}
	count = escp_norm(data, hold_p, count);
	return (count);
}
