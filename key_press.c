/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 11:00:02 by aoudija           #+#    #+#             */
/*   Updated: 2023/02/06 16:29:25 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int keycode, t_data *data)
{
	if (keycode == 13)
	{
		data->map = player_up(data->map);
		mapping(*data);
	}
	if (keycode == 1)
	{
		data->map = player_down(data->map);
		mapping(*data);
	}
	if (keycode == 0)
	{
		data->map = player_left(data->map);
		mapping(*data);
	}
	if (keycode == 0x02)
	{
		data->map = player_right(data->map);
		mapping(*data);
	}
	return (0);
}
