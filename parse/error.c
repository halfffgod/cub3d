/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziharuty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:00:06 by ziharuty          #+#    #+#             */
/*   Updated: 2024/05/21 14:00:08 by ziharuty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	ft_error(char *str)
{
	write(2, str, ft_strlen(str));
	return (0);
}

void	ft_errorwithexit(char *str)
{
	write(2, str, ft_strlen(str));
	exit(1);
}

int	file_exists(char *filename)
{
	int	file;

	file = open(filename, O_RDONLY);
	if (file != -1)
	{
		close(file);
		return (1);
	}
	return (0);
}

int	texture_count(char **array)
{
	int	textr_length;

	textr_length = 0;
	while (*array && (*array[0] != '1' || *array[0] != 'N' || \
	*array[0] != 'E' || *array[0] != 'W' || *array[0] != 'S' || \
	*array[0] != 'F' || *array[0] != 'C'))
	{
		textr_length++;
		array++;
	}
	return (textr_length);
}
