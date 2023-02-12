/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 20:14:59 by aoudija           #+#    #+#             */
/*   Updated: 2023/02/12 20:41:26 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	filler(t_data *data)
{
	data->floor = floor_img(data->mlx);
	data->wall = wall_img(data->mlx);
	data->pickle = pickle_img(data->mlx);
	data->exit = hole_img(data->mlx);
	data->rick = rick_img(data->mlx);
	data->morty = morty_img(data->mlx);
	data->exit_f = hole_img2(data->mlx);
	data->exit_t = hole_img3(data->mlx);
	data->count = 0;
}
