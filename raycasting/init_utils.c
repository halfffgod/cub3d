/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbadalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 08:15:24 by nbadalia          #+#    #+#             */
/*   Updated: 2024/05/25 08:15:47 by nbadalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	find_pos_player(t_addres *address)
{
	int	i;
	int	j;

	i = 0;
	while (address->data.map[i])
	{
		j = 0;
		while (address->data.map[i][j])
		{
			if (address->data.map[i][j] == 'N' || \
				address->data.map[i][j] == 'S' || \
				address->data.map[i][j] == 'E' || \
				address->data.map[i][j] == 'W')
			{
				init_player_pos(address, i, j);
				address->rcasting->posx = i + 0.5;
				address->rcasting->posy = j + 0.5;
				address->data.map[i][j] = '0';
				return ;
			}
			j++;
		}
		i++;
	}
}

void	norm_init_win_3(t_addres *address)
{
	if (address->rcasting->side == 0)
		address->rcasting->perpwalldist = (address->rcasting->sidedistx - \
		address->rcasting->deltadistx);
	else
		address->rcasting->perpwalldist = (address->rcasting->sidedisty - \
		address->rcasting->deltadisty);
	address->rcasting->lineheight = (int)(HEIGHT / \
	address->rcasting->perpwalldist);
	address->rcasting->drawstart = -address->rcasting->lineheight / \
	2 + HEIGHT / 2;
	if (address->rcasting->drawstart < 0)
		address->rcasting->drawstart = 0;
	address->rcasting->drawend = address->rcasting->lineheight / 2 + HEIGHT / 2;
	if (address->rcasting->drawend >= HEIGHT)
		address->rcasting->drawend = HEIGHT - 1;
	draw_floor_and_celling(address, 0);
	draw_walls(address, 0, 0, 0);
}

void	norm_init_win_2(t_addres *address)
{
	address->rcasting->hit = 0;
	while (address->rcasting->hit == 0)
	{
		if (address->rcasting->sidedistx < address->rcasting->sidedisty)
		{
			address->rcasting->sidedistx += address->rcasting->deltadistx;
			address->rcasting->mapx += address->rcasting->stepx;
			address->rcasting->side = 0;
		}
		else
		{
			address->rcasting->sidedisty += address->rcasting->deltadisty;
			address->rcasting->mapy += address->rcasting->stepy;
			address->rcasting->side = 1;
		}
		if (address->data.map[address->rcasting->mapx] \
		[address->rcasting->mapy] != '0')
			address->rcasting->hit = 1;
	}
	norm_init_win_3(address);
}

void	norm_init_win(t_addres *address)
{
	if (address->rcasting->raydiry < 0)
	{
		address->rcasting->stepy = -1;
		address->rcasting->sidedisty = (address->rcasting->posy - \
		address->rcasting->mapy) * address->rcasting->deltadisty;
	}
	else
	{
		address->rcasting->stepy = 1;
		address->rcasting->sidedisty = (address->rcasting->mapy + 1.0 - \
		address->rcasting->posy) * address->rcasting->deltadisty;
	}
	norm_init_win_2(address);
}

void	continue_init_win(t_addres *address)
{
	if (address->rcasting->raydirx == 0)
		address->rcasting->deltadistx = 1e30;
	else
		address->rcasting->deltadistx = ft_abs(1 / address->rcasting->raydirx);
	if (address->rcasting->raydiry == 0)
		address->rcasting->deltadisty = 1e30;
	else
		address->rcasting->deltadisty = ft_abs(1 / address->rcasting->raydiry);
	if (address->rcasting->raydirx < 0)
	{
		address->rcasting->stepx = -1;
		address->rcasting->sidedistx = (address->rcasting->posx - \
		address->rcasting->mapx) * address->rcasting->deltadistx;
	}
	else
	{
		address->rcasting->stepx = 1;
		address->rcasting->sidedistx = (address->rcasting->mapx + 1.0 - \
		address->rcasting->posx) * address->rcasting->deltadistx;
	}
	norm_init_win(address);
}
