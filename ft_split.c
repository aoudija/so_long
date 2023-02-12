/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 12:49:59 by aoudija           #+#    #+#             */
/*   Updated: 2023/02/12 13:09:27 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	countc(char *s, char c)
{
	int	i;
	int	ct;

	ct = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c)
			ct++;
		i++;
	}
	return (ct);
}

void	*ft_free(char **table)
{
	int	i;

	i = 0;
	while (table[i])
	{
		free(table[i]);
		i++;
	}
	free(table);
	return (NULL);
}

char	*ft_substring(char *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	sub = malloc(len);
	if (!sub)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			sub[j] = s[i];
			j++;
		}
		i++;
	}
	sub[j] = 0;
	return (sub);
}

char	**ft_optimiz(char **str, char c, char *s)
{
	int	i;
	int	j;
	int	x;

	i = 0;
	j = 0;
	x = 0;
	while (j < (int)ft_strlen(s))
	{
		while (s[j])
		{
			if (s[j] == c)
				break ;
			i++;
			j++;
		}
		str[x++] = ft_substring(s, j - i, i);
		if (!str)
			return (ft_free(str));
		while (s[j] == c)
			j++;
		i = 0;
	}
	str[x] = NULL;
	return (str);
}

char	**ft_split(char *s, char c)
{
	char	set[2];
	char	*ss;
	char	**strs;
	int		x;

	set[0] = c;
	set[1] = 0;
	ss = ft_strtrim(s, set);
	if (ss == NULL)
		return (NULL);
	x = countc(ss, c);
	strs = malloc(sizeof(char *) * (x + 2));
	if (!(strs))
	{
		free(ss);
		return (NULL);
	}
	strs = ft_optimiz(strs, c, ss);
	free (ss);
	return (strs);
}
