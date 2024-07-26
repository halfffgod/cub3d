/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziharuty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:02:04 by ziharuty          #+#    #+#             */
/*   Updated: 2024/05/25 08:08:46 by nbadalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_exit(t_map *v)
{
	int	x;

	x = 0;
	while (v->map[x])
	{
		free(v->map[x]);
		x++;
	}
	free(v->map);
	mlx_destroy_window(v->mlx, v->win);
	exit(1);
}

t_data	data_collector(t_cub cub, t_map map)
{
	t_data	data;

	(void)cub;
	data.map = map.playfield;
	data.x = -1;
	data.y = -1;
	return (data);
}

void	fd_check(char *filename)
{
	if (open(filename, O_RDONLY) == -1)
	{
		write(1, "Error: Not valid file\n", 22);
		exit(1);
	}
}

void	main_h(t_map *map_struct, char **map, t_cub *cub, char **argv)
{
	main_helper(map_struct, map, argv);
	main_helper2(map_struct);
	init_cub(map_struct, cub);
}

void	handle_empty_map(void)
{
	write(1, "Error: Map is empty\n", 20);
	exit(1);
}
