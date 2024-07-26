/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbadalia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 08:16:06 by nbadalia          #+#    #+#             */
/*   Updated: 2024/05/25 08:16:08 by nbadalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

float	ft_abs(float num)
{
	if (num < 0)
		return (-num);
	return (num);
}

char	*get_correct_arg(char *ptr)
{
	int		i;
	int		j;
	char	*new_arg;

	new_arg = malloc(sizeof(char) * (ft_strlen(ptr) + 1));
	i = 0;
	j = 0;
	while (ptr[i])
	{
		if (ptr[i] != ' ' && ptr[i] != '\t')
		{
			new_arg[j] = ptr[i];
			j++;
		}
		i++;
	}
	new_arg[j] = '\0';
	return (new_arg);
}
