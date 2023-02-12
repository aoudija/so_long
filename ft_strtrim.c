/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 12:51:33 by aoudija           #+#    #+#             */
/*   Updated: 2023/02/11 13:40:40 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	index_start(char*s1, char*set)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(s1);
	while (i < j)
	{
		if (ft_strchr(set, s1[i]) == 0)
			break ;
		i++;
	}
	return (i);
}

int	index_end(char*s1, char*set)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(s1);
	while (i < j)
	{
		if (ft_strchr(set, s1[j - i - 1]) == 0)
			break ;
		i++;
	}
	return (j - i);
}

char	*ft_strtrim(char *s1, char *set)
{
	int		i;
	int		j;
	char	*tr;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1));
	i = index_start(s1, set);
	j = index_end(s1, set);
	if (i >= j)
		return (ft_strdup(""));
	tr = malloc(j - i + 1);
	if (tr == NULL)
		return (NULL);
	ft_strlcpy(tr, s1 + i, j - i + 1);
	return (tr);
}
