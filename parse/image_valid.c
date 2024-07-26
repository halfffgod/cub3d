/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziharuty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:01:34 by ziharuty          #+#    #+#             */
/*   Updated: 2024/05/25 08:07:46 by nbadalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

//printing error for not valid extension
void	extens_err(char *str)
{
	if (ft_strlen(str) != 4)
	{
		write(2, "Error: Not valid file extension\n", 32);
		exit(1);
	}
}

//finds extension in filename for .cub and .xpm
int	extension_compare(char *str, char *to_find)
{
	int	i;

	i = 0;
	extens_err(str);
	while (to_find[i])
	{
		if (to_find[i] != str[i])
			return (0);
		i++;
	}
	if (str[i] == '\0')
		return (1);
	return (0);
}

void	isimagevalid(char *file_line)
{
	while (*file_line)
	{
		if (*file_line == '.')
		{
			if (extension_compare(file_line, ".xpm"))
			{
				return ;
			}
		}
		file_line++;
	}
	write(2, "Error: Image is not valid", 26);
	exit(1);
}
