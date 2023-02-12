/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 11:00:02 by aoudija           #+#    #+#             */
/*   Updated: 2023/02/10 19:10:59 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	key_press(int keycode, t_data *data)
{
	static int	count;

	if (keycode == 53)
		exit (0);
	if (keycode == 13)
	{
		count = player_up(data->map, count);
		mapping(*data);
	}
	if (keycode == 1)
	{
		count = player_down(data->map, count);
		mapping(*data);
	}
	if (keycode == 0)
	{
		count = player_left(data->map, count);
		mapping(*data);
	}
	if (keycode == 0x02)
	{
		count = player_right(data->map, count);
		mapping(*data);
	}
	return (0);
}
