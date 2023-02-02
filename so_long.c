/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:01:44 by aoudija           #+#    #+#             */
/*   Updated: 2023/02/02 14:24:56 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int ac, char *av[]
int	main()
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*img2;
	void	*img3;
	void	*floor_img;
	int		img_width;
	int		img_height;
	int		x;
	int		y;

	x = 0;
	y = 0;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 1200, 720, "Window");
	img = mlx_xpm_file_to_image(mlx, "images/R_L.xpm", &img_width, &img_height);
	img2 = mlx_xpm_file_to_image(mlx, "images/R_R.xpm", &img_width, &img_height);
	img3 = mlx_xpm_file_to_image(mlx, "images/g_h.xpm", &img_width, &img_height);
	floor_img = mlx_xpm_file_to_image(mlx, "images/floor.xpm", &img_width, &img_height);
	while (y < 720)
	{
		while (x < 1201)
		{
			mlx_put_image_to_window(mlx, win, floor_img, x, y);
			x += 120;
		}
		x = 0;
		y += 80;
	}
	// 120 120 120 120 *10
	//floor w 120 ;h 15
	mlx_put_image_to_window(mlx, win, img, 0, 5);
	mlx_put_image_to_window(mlx, win, img2, 60, 5);
	mlx_put_image_to_window(mlx, win, img3, 120, 0);
	mlx_loop(mlx);
	return (0);
}
