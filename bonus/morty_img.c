/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   morty_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 10:41:08 by aoudija           #+#    #+#             */
/*   Updated: 2023/02/09 20:22:35 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	*morty_img(void *mlx)
{
	void	*morty_img;
	int		i;

	i = 50;
	morty_img = mlx_xpm_file_to_image(mlx, "images/morty.xpm", &i, &i);
	return (morty_img);
}

void	*hole_img2(void *mlx)
{
	void	*img2;
	int		i;

	i = 50;
	img2 = mlx_xpm_file_to_image(mlx, "images/hole_img2.xpm", &i, &i);
	return (img2);
}

void	*hole_img3(void *mlx)
{
	void	*img3;
	int		i;

	i = 50;
	img3 = mlx_xpm_file_to_image(mlx, "images/hole_img3.xpm", &i, &i);
	return (img3);
}
