/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziharuty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:04:12 by ziharuty          #+#    #+#             */
/*   Updated: 2024/05/21 14:04:15 by ziharuty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	cordinates(char **map, int x, int y)
{
	if (x == 0)
		return (0);
	if (ft_strlen(map[x - 1]) < (size_t)y)
		return (0);
	if (!map[x - 1] || !map[x - 1][y] || \
	(map[x - 1][y] != '1' && map[x - 1][y] != '0' && \
	map[x - 1][y] != 'N' && map[x - 1][y] != 'S' && \
	map[x - 1][y] != 'E' && map[x - 1][y] != 'W'))
		return (0);
	if (!map[x + 1] || !map[x + 1][y] || \
	(map[x + 1][y] != '1' && map[x + 1][y] != '0' && \
	map[x + 1][y] != 'N' && map[x + 1][y] != 'S' && \
	map[x + 1][y] != 'E' && map[x + 1][y] != 'W'))
		return (0);
	if (!map[x] || !map[x][y - 1] || \
	(map[x][y - 1] != '1' && map[x][y - 1] != '0' && \
	map[x][y - 1] != 'N' && map[x][y - 1] != 'S' && \
	map[x][y - 1] != 'E' && map[x][y - 1] != 'W'))
		return (0);
	if (!map[x] || !map[x][y + 1] || \
	(map[x][y + 1] != '1' && map[x][y + 1] != '0' && \
	map[x][y + 1] != 'N' && map[x][y + 1] != 'S' && \
	map[x][y + 1] != 'E' && map[x][y + 1] != 'W'))
		return (0);
	return (1);
}

int	walls_spaces(char **map)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (map[0][i] != '\0')
	{
		if (map[0][i] != '1' && !ft_isspace(map[0][i]))
			return (ft_error("Error while reading walls\
			or spaces or floors or ceiling\n"));
		i++;
	}
	i = 0;
	while (map[++i])
	{
		j = 0;
		while (map[i][j])
		{
			if ((map[i][j] == '0' || map[i][j] == 'W' || map[i][j] == 'S' || \
			map[i][j] == 'E' || map[i][j] == 'N' ) \
			&& (!cordinates(map, i, j)))
				return (ft_error("Error: not valid map\n"));
			j++;
		}
	}
	return (1);
}

int	checking_walls(char **array)
{
	int	i;
	int	j;

	i = 0;
	while (array[6][i])
	{
		if (array[6][i] != '1' && !ft_isspace(array[6][i]))
			return (ft_error("Wall error from teh top\n"));
		i++;
	}
	j = arr_length(array) - 1;
	i = 0;
	while (array[j][i])
	{
		if (array[j][i] != '1' && !ft_isspace(array[j][i]))
			return (ft_error("Wall error from the down\n"));
		i++;
	}
	return (1);
}

void	epur_texture(char **texture)
{
	int	i;

	i = 0;
	while (texture[i])
	{
		texture[i] = epurstr(texture[i]);
		i++;
	}
}
