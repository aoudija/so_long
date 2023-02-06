/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 12:47:31 by aoudija           #+#    #+#             */
/*   Updated: 2023/02/06 14:52:12 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>

typedef struct s_data
{
	void	*mlx;
	void	*win;
	char	*map;
}	t_data;

void	fill(t_data data, char c, void *img_ptr);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
int		heightt(char *path);
void	*floor_img(void *mlx);
void	*pickle_img(void *mlx);
void	*hole_img(void *mlx);
void	*wall_img(void *mlx);
void	*rick_img(void *mlx);
char	*ft_strjoin(char *s1, char *s2);
char	*player_up(char *map);
char	*player_down(char *map);
char	*player_left(char *map);
char	*player_right(char *map);
void	mapping(t_data data);
int		key_press(int keycode, t_data *data);

#endif