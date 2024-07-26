/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziharuty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:05:22 by ziharuty          #+#    #+#             */
/*   Updated: 2024/05/21 14:05:24 by ziharuty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	free_mtx(char **mtx)
{
	int	i;

	i = -1;
	if (!mtx)
		return ;
	while (mtx[++i])
	{
		free(mtx[i]);
		mtx[i] = NULL;
	}
	free(mtx);
	mtx = NULL;
}

void	free_cub(t_cub map)
{
	free_mtx(map.map);
	free(map.so);
	free(map.no);
	free(map.ea);
	free(map.we);
}

void	free_game(t_game *game)
{
	free(game->no);
	free(game->so);
	free(game->we);
	free(game->ea);
	game->mlx = NULL;
	game->win = NULL;
	game->no = NULL;
	game->so = NULL;
	game->ea = NULL;
	game->we = NULL;
}

void	free_all(t_addres *address)
{
	int	i;

	i = -1;
	free_cub(*(address)->cub);
	free_game(address->game);
	while (++i < 5)
	{
		free((address)->img[i].img);
		free((address)->img[i].ptr);
	}
	free((address)->rcasting);
	free((address)->index);
	free((address)->game);
	free((address)->img);
	free(address->cub);
	(address)->rcasting = NULL;
	(address)->index = NULL;
	(address)->game = NULL;
	(address)->img = NULL;
	(address)->cub = NULL;
}
