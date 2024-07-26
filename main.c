/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbadalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:25:23 by nbadalia          #+#    #+#             */
/*   Updated: 2024/05/25 12:25:25 by nbadalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	main(int argc, char **argv)
{
	t_addres	addres;
	char		**map;
	t_map		map_struct;

	if (argc == 2)
	{
		addres.cub = malloc(sizeof(t_cub));
		fd_check(argv[1]);
		map = getmap(argv[1]);
		if (!map)
			handle_empty_map();
		main_h(&map_struct, map, addres.cub, argv);
		init_structs(&addres);
		addres.data = data_collector(*addres.cub, map_struct);
		initializer(&addres);
		init_win(&addres);
		mlx_hook(addres.game->win, 17, 1L << 0, close_game, &addres);
		mlx_hook(addres.game->win, 2, 1L << 0, key_manager, &addres);
		mlx_loop(addres.game->mlx);
	}
	else
		ft_error("Not valid arguments count\n");
	return (0);
}
