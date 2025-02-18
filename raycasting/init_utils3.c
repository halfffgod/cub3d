/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_win_4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziharuty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:06:01 by ziharuty          #+#    #+#             */
/*   Updated: 2024/05/21 14:06:03 by ziharuty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	ft_get_data_addr(t_addres *address)
{
	address->img[1].img = mlx_get_data_addr \
	(address->game->no, &address->img[1].bpp, \
	&address->img[1].size_line, &address->img[1].endian);
	address->img[2].img = mlx_get_data_addr \
	(address->game->so, &address->img[2].bpp, \
	&address->img[2].size_line, &address->img[2].endian);
	address->img[3].img = mlx_get_data_addr \
	(address->game->ea, &address->img[3].bpp, \
	&address->img[3].size_line, &address->img[3].endian);
	address->img[4].img = mlx_get_data_addr \
	(address->game->we, &address->img[4].bpp, \
	&address->img[4].size_line, &address->img[4].endian);
}

int	check_nwse(t_addres *address)
{
	int	n;

	n = 1;
	if (address->rcasting->side == 1 && address->rcasting->raydiry < 0)
		n = 3;
	else if (address->rcasting->side == 1 && address->rcasting->raydiry > 0)
		n = 4;
	else if (address->rcasting->side == 0 && address->rcasting->raydirx > 0)
		n = 2;
	else if (address->rcasting->side == 0 && address->rcasting->raydirx < 0)
		n = 1;
	return (n);
}
