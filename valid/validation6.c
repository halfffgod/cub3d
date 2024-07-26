/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation61.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziharuty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:04:53 by ziharuty          #+#    #+#             */
/*   Updated: 2024/05/21 14:04:55 by ziharuty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	valid_color_helper(t_map *map, char	**arr)
{
	if (arr_length(arr) != 3)
		return (ft_error("Error: not valid symbols\n"));
	map->term[0] = ft_atoi(arr[0]);
	map->term[1] = ft_atoi(arr[1]);
	map->term[2] = ft_atoi(arr[2]);
	free_mtx(arr);
	return (1);
}

int	valid_color(char *str, t_map *map)
{
	char	*nums;
	char	**arr;
	int		i;
	char	*p;

	i = 0;
	while (!ft_isdigit(str[i]))
		i++;
	nums = ft_substr2(str, i, ft_strlen(str) - 2);
	arr = ft_split(nums, ',');
	free(nums);
	i = 0;
	p = NULL;
	while (arr[i])
	{
		p = arr[i];
		arr[i] = ft_strtrim(arr[i], " \r\v\f\t");
		if (!is_digital_str(arr[i]))
			return (ft_error("Error: not valid symbols\n"));
		if (ft_atoi(arr[i]) < 0 || ft_atoi(arr[i]) > 255)
			return (ft_error("Error: not valid color\n"));
		free(p);
		i++;
	}
	return (valid_color_helper(map, arr));
}

int	is_digital_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	free_result(char	**arr)
{
	if (!(!ft_strcmp(arr[0], "NO" ) || !ft_strcmp(arr[0], "SO") \
	|| !ft_strcmp(arr[0], "EA") || !ft_strcmp(arr[0], "WE")))
		free_mtx(arr);
	else
	{
		free(arr);
	}
}

void	init_v2(t_valid2 *v)
{
	v->count_f = 0;
	v->count_c = 0;
	v->index_f = 0;
	v->index_c = 0;
	v->r = 0;
	v->g = 0;
	v->b = 0;
}
