/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziharuty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:04:01 by ziharuty          #+#    #+#             */
/*   Updated: 2024/05/21 14:04:02 by ziharuty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	map_symbols(char **map, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (*map)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				count++;
			j++;
		}
		map++;
	}
	return (count);
}

int	dirs(char **map)
{
	int	n;
	int	s;
	int	e;
	int	w;

	n = map_symbols(map, 'N');
	w = map_symbols(map, 'W');
	e = map_symbols(map, 'E');
	s = map_symbols(map, 'S');
	if ((n + s + w + e) != 1)
		return (ft_error("Error: wrong player count or map\n"));
	return (1);
}

int	is_map_symb(char **map)
{
	int	i;

	i = 0;
	while (*map)
	{
		if (*map[i] != '0' && *map[i] != '1' && *map[i] != ' ' && \
		*map[i] != 'N' && *map[i] != 'S' && *map[i] != 'E' && *map[i] != 'W')
			return (ft_error("not valid symbol exist in map\n"));
		map++;
	}
	return (1);
}

int	check_the_char(char c)
{
	if (c && (c == ' '))
		return (0);
	return (1);
}

int	is_empty_line(char **playfield)
{
	int	len;
	int	i;

	len = arr_length(playfield);
	i = 0;
	while (playfield[i])
	{
		if ((playfield[i] == NULL || \
		!ft_strcmp(playfield[i], "")) && i != len - 1)
			return (ft_error("Error: Empty line\n"));
		i++;
	}
	return (1);
}
