/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziharuty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:05:15 by ziharuty          #+#    #+#             */
/*   Updated: 2024/05/21 14:05:18 by ziharuty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	create_trgb(int r, int g, int b)
{
	int	t;

	t = 0;
	return (*(int *)(unsigned char [4]){b, g, r, t});
}

void	initializer(t_addres *address)
{
	address->game->mlx = mlx_init();
	address->game->win = mlx_new_window(address->game->mlx, WIDTH, \
	HEIGHT, "IT IS MY cub3D!");
	address->game->no = mlx_xpm_file_to_image(address->game->mlx, \
	address->cub->no, &address->img[1].width, &address->img[1].height);
	address->game->so = mlx_xpm_file_to_image(address->game->mlx, \
	address->cub->so, &address->img[2].width, &address->img[2].height);
	address->game->ea = mlx_xpm_file_to_image(address->game->mlx, \
	address->cub->ea, &address->img[3].width, &address->img[3].height);
	address->game->we = mlx_xpm_file_to_image(address->game->mlx, \
	address->cub->we, &address->img[4].width, &address->img[4].height);
	address->game->c_color = create_trgb(153, 204, 255);
	address->game->f_color = create_trgb(96, 96, 96);
	if (address->game->mlx == NULL || address->game->win == NULL)
		close_game(address);
	if (address->game->no == NULL || address->game->so == NULL)
		close_game(address);
	if (address->game->we == NULL || address->game->ea == NULL)
		close_game(address);
}
