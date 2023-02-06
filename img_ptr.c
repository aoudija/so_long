/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_ptr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 16:20:23 by aoudija           #+#    #+#             */
/*   Updated: 2023/02/06 13:33:17 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*pickle_img(void *mlx)
{
	void	*r_r;
	int		i;

	i = 50;
	r_r = mlx_xpm_file_to_image(mlx, "images/Pickle_Rick.xpm", &i, &i);
	return (r_r);
}

void	*floor_img(void *mlx)
{
	void	*floor_img;
	int		i;

	i = 50;
	floor_img = mlx_xpm_file_to_image(mlx, "images/floor.xpm", &i, &i);
	return (floor_img);
}

void	*hole_img(void *mlx)
{
	void	*r_r;
	int		i;

	i = 50;
	r_r = mlx_xpm_file_to_image(mlx, "images/green_hole.xpm", &i, &i);
	return (r_r);
}

void	*wall_img(void *mlx)
{
	void	*wall_img;
	int		i;

	i = 50;
	wall_img = mlx_xpm_file_to_image(mlx, "images/wall.xpm", &i, &i);
	return (wall_img);
}

void	*rick_img(void *mlx)
{
	void	*r_r;
	int		i;

	i = 50;
	r_r = mlx_xpm_file_to_image(mlx, "images/r_r.xpm", &i, &i);
	return (r_r);
}
