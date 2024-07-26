/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziharuty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:06:26 by ziharuty          #+#    #+#             */
/*   Updated: 2024/05/21 14:06:34 by ziharuty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	close_game(t_addres *address)
{
	mlx_destroy_window(address->game->mlx, address->game->win);
	write(1, "Game closed successfully\n", \
	ft_strlen("Game closed successfully\n"));
	free_all(address);
	exit(0);
}
