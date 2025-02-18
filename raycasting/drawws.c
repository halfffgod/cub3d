/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_win_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziharuty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:05:47 by ziharuty          #+#    #+#             */
/*   Updated: 2024/05/25 08:14:54 by nbadalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	draw_floor_and_celling(t_addres *data, char *dest)
{
	int	i;

	i = -1;
	while (++i < HEIGHT / 2)
	{
		dest = data->img[0].img + (i * data->img[0].size_line + \
		data->game->index * data->img[0].bpp / 8);
		*(int *)dest = data->game->c_color;
	}
	while (++i < HEIGHT)
	{
		dest = data->img[0].img + (i * data->img[0].size_line + \
		data->game->index * data->img[0].bpp / 8);
		*(int *)dest = data->game->f_color;
	}
}

int	ft_texx(t_addres *address, int n)
{
	int		texx;
	double	wallx;

	wallx = 0.0;
	if (address->rcasting->side == 0)
		wallx = address->rcasting->posy + address->rcasting->perpwalldist \
		* address->rcasting->raydiry;
	else
		wallx = address->rcasting->posx + address->rcasting->perpwalldist \
		* address->rcasting->raydirx;
	wallx -= floor(wallx);
	texx = (int)(wallx * (double)address->img[n].width);
	if (address->rcasting->side == 0 && address->rcasting->raydirx > 0)
		texx = address->img[n].width - texx - 1;
	if (address->rcasting->side == 1 && address->rcasting->raydiry < 0)
		texx = address->img[n].width - texx - 1;
	return (texx);
}

int	draw_walls(t_addres *address, char *dest, char *dest_2, int texx)
{
	double	step;
	double	texpos;
	int		texy;
	int		i;
	int		n;

	n = check_nwse(address);
	i = address->rcasting->drawstart;
	texx = (int)ft_texx(address, n);
	step = 1.0 * address->img[n].width / address->rcasting->lineheight;
	texpos = (address->rcasting->drawstart - HEIGHT / 2 + \
	address->rcasting->lineheight / 2) * step;
	while (i < address->rcasting->drawend)
	{
		texy = (int)texpos & address->img[n].height;
		texpos += step;
		dest = address->img[0].img + (i * address->img[0].size_line + \
		address->game->index * (address->img[0].bpp / 8));
		dest_2 = address->img[n].img + (texy * address->img[n].size_line + \
		texx * (address->img[n].bpp / 8));
		*(int *)dest = *(int *)dest_2;
		i++;
	}
	return (0);
}
