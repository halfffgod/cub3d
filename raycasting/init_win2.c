/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_win_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziharuty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:05:53 by ziharuty          #+#    #+#             */
/*   Updated: 2024/05/21 14:05:56 by ziharuty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	init_plane(t_addres *address, double i, double j)
{
	address->rcasting->planex = i;
	address->rcasting->planey = j;
}

void	init_dir(t_addres *address, double i, double j)
{
	address->rcasting->dirx = i;
	address->rcasting->diry = j;
}

void	init_player_pos(t_addres *address, int i, int j)
{
	if (address->data.map[i][j] == 'S')
	{
		init_dir(address, 1, 0);
		init_plane(address, 0, -0.66);
	}
	else if (address->data.map[i][j] == 'N')
	{
		init_dir(address, -1, 0);
		init_plane(address, 0, 0.66);
	}
	else if (address->data.map[i][j] == 'E')
	{
		init_dir(address, 0, 1);
		init_plane(address, 0.66, 0);
	}
	else if (address->data.map[i][j] == 'W')
	{
		init_dir(address, 0, -1);
		init_plane(address, -0.66, 0);
	}
}
