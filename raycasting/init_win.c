/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziharuty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:05:39 by ziharuty          #+#    #+#             */
/*   Updated: 2024/05/21 14:05:41 by ziharuty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	init_win(t_addres *address)
{
	int	i;

	i = 0;
	find_pos_player(address);
	free(address->img[0].ptr);
	free(address->img[0].img);
	address->img[0].ptr = mlx_new_image(address->game->mlx, WIDTH, HEIGHT);
	address->img[0].img = mlx_get_data_addr(address->img[0].ptr, \
	&address->img[0].bpp, &address->img[0].size_line, &address->img[0].endian);
	ft_get_data_addr(address);
	while (i < WIDTH)
	{
		address->game->index = i;
		address->rcasting->camerax = 2 * i / (double)WIDTH - 1;
		address->rcasting->raydirx = address->rcasting->dirx + \
		address->rcasting->planex * address->rcasting->camerax;
		address->rcasting->raydiry = address->rcasting->diry + \
		address->rcasting->planey * address->rcasting->camerax;
		address->rcasting->mapx = (int)address->rcasting->posx;
		address->rcasting->mapy = (int)address->rcasting->posy;
		continue_init_win(address);
		i++;
	}
	mlx_put_image_to_window(address->game->mlx, address->game->win, \
	address->img[0].ptr, 0, 0);
}
