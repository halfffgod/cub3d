/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziharuty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:09:55 by ziharuty          #+#    #+#             */
/*   Updated: 2024/05/21 14:09:56 by ziharuty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

size_t	ft_strlen2(const char *c)
{
	int	i;

	i = 0;
	while (c[i])
		i++;
	return (i);
}
