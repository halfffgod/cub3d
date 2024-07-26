/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation51.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziharuty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:04:44 by ziharuty          #+#    #+#             */
/*   Updated: 2024/05/21 14:04:46 by ziharuty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	parse_textures(char **texture, t_map *map)
{
	int		i;
	char	**arr;
	int		flag;

	i = 0;
	flag = 0;
	while (i < 6)
	{
		arr = NULL;
		arr = ft_split(texture[i], ' ');
		parse_textures2(map, arr, i, flag);
		free_mtx(arr);
		i++;
	}
	map->result[i] = NULL;
	map->result2[i] = NULL;
	if (flag)
		return (ft_error("Error: split size is not 2\n"));
	return (1);
}

void	parse_textures2(t_map *map, char **arr, int i, int flag)
{
	if (arr_length(arr) != 2 && (ft_strcmp(arr[0], "NO" ) || \
		ft_strcmp(arr[0], "SO") || ft_strcmp(arr[0], "EA") \
		|| ft_strcmp(arr[0], "WE")))
	{
		flag = 1;
		ft_errorwithexit("Error: Invalid Map");
	}
	map->result[i] = ft_strdup(arr[0]);
	map->result2[i] = ft_strdup(arr[1]);
	if ((!ft_strcmp(map->result[i], "NO") || \
	!ft_strcmp(map->result[i], "SO") || \
	!ft_strcmp(map->result[i], "EA") || \
	!ft_strcmp(map->result[i], "WE")) && \
	!file_exists(map->result2[i]))
		ft_errorwithexit("Error: Invalid .xpm ");
	if (!ft_strcmp("NO", map->result[i]) || \
	!ft_strcmp("SO", map->result[i]) || \
	!ft_strcmp("EA", map->result[i]) || \
	!ft_strcmp("WE", map->result[i]))
		isimagevalid(map->result2[i]);
}

int	substring_one(char **arr, char *sub)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (i < 6)
	{
		if (ft_strcmp(arr[i], sub) == 0)
		{
			count++;
			if (count > 1)
				return (ft_error("Error: substring appears\
				more than once.\n"));
		}
		i++;
	}
	if (count == 0)
		return (ft_error("Error: substring doesnt match\n"));
	return (1);
}

int	helper_val(char **texture, t_map *map, t_valid2 *v)
{
	if (v->count_c != 1 || v->count_f != 1)
		return (ft_error("Error: wrong color arguments\n"));
	if (!(texture[v->index_c][2] >= '0' && texture[v->index_c][2] <= '9'))
		return (ft_error("Error: not valid symbols\n"));
	if (!(texture[v->index_f][2] >= '0' && texture[v->index_f][2] <= '9'))
		return (ft_error("Error: not valid symbols\n"));
	if (!valid_color(texture[v->index_c], map))
		return (0);
	map->c[0] = map->term[0];
	map->c[1] = map->term[1];
	map->c[2] = map->term[2];
	if (!valid_color(texture[v->index_f], map))
		return (0);
	map->f[0] = map->term[0];
	map->f[1] = map->term[1];
	map->f[2] = map->term[2];
	return (1);
}

int	validate_colors(char **texture, t_map *map)
{
	int			i;
	t_valid2	v;

	i = 0;
	init_v2(&v);
	while (i < 6)
	{
		if (texture[i][0] == 'F' && texture[i][1] && ft_isspace(texture[i][1]))
		{
			v.index_f = i;
			v.count_f++;
		}
		if (texture[i][0] == 'C' && texture[i][1] && ft_isspace(texture[i][1]))
		{
			v.index_c = i;
			v.count_c++;
		}
		i++;
	}
	return (helper_val(texture, map, &v));
}
