/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 12:47:31 by aoudija           #+#    #+#             */
/*   Updated: 2023/02/04 20:53:12 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>

char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
int		heightt(char *path);
void	fill_floor(void *mlx, void *win, int fd);
void	fill_wall(void *mlx, void *win, int fd);
void	fill_RICK(void *mlx, void *win, int fd);


#endif