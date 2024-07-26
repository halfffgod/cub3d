/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziharuty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:03:50 by ziharuty          #+#    #+#             */
/*   Updated: 2024/05/21 14:03:51 by ziharuty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	ft_isspace(int c)
{
	c = (unsigned char)c;
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
		|| c == ' ')
		return (1);
	return (0);
}

void	get_textures(char **map, t_map *mapp)
{
	int	i;

	i = 0;
	if (texture_count(map) < 6)
		ft_errorwithexit("Invalid textures count");
	mapp->texture = (char **)malloc(sizeof(char *) * 7);
	while (i < 6)
	{
		mapp->texture[i] = map[i];
		i++;
	}
	mapp->texture[i] = NULL;
}

int	is_empty_string(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isspace(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	get_playfield(char **map, t_map *mapp)
{
	int	i;
	int	j;

	j = 0;
	i = 6;
	mapp->playfield = (char **)malloc(sizeof(char *) * (arr_length(map) - 5));
	while (map[i])
	{
		if (is_empty_string(map[i]))
		{
			write(2, "Error: Empty line \n", 19);
			exit(1);
		}
		mapp->playfield[j] = map[i];
		i++;
		j++;
	}
	mapp->playfield[j] = NULL;
}

int	arr_length(char **array)
{
	int	length;

	length = 0;
	if (array == NULL)
		return (length);
	while (*array != NULL)
	{
		length++;
		array++;
	}
	return (length);
}
