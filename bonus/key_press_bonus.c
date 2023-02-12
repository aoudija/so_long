/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 10:55:28 by aoudija           #+#    #+#             */
/*   Updated: 2023/02/12 20:40:27 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void draw_moves(t_data *data, int keycode, int *count)
{
	if (keycode == 0)
	{
		*count = playerb_left(data, *count);
		mapping_bonus(*data);
	}
	if (keycode == 2)
	{
		*count = playerb_right(data, *count);
		mapping_bonus(*data);
	}
}

int	key_press_bonus(int keycode, t_data *data)
{
	static int	count;

	if (keycode == 53)
		exit (0);
	if (keycode == 13)
	{
		count = playerb_up(data, count);
		mapping_bonus(*data);
	}
	if (keycode == 1)
	{
		count = playerb_down(data, count);
		mapping_bonus(*data);
	}
	draw_moves(data, keycode, &count);
	data->count = count;
	return (0);
}
