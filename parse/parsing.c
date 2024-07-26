/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziharuty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:02:35 by ziharuty          #+#    #+#             */
/*   Updated: 2024/05/21 14:03:07 by ziharuty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t len)
{
	int		res;
	size_t	i;

	i = 0;
	res = ft_strlen((char *)src);
	if (len == 0)
		return (res);
	while (i < len - 1 && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	if (len > i)
		dest[i] = 0;
	return (res);
}

int	tab_count(char	*str)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (str[++i])
		if (str[i] == '\t')
			count++;
	return (count);
}

char	*open_tabs(char *str, int count)
{
	char	*line;
	int		len;
	int		i;
	int		j;

	len = ft_strlen(str);
	line = (char *)malloc(sizeof(char) * ((count * 3) + len) + 1);
	i = -1;
	j = -1;
	while (str[++i])
	{
		if (str[i] == '\t')
		{
			line[++j] = ' ';
			line[++j] = ' ';
			line[++j] = ' ';
			line[++j] = ' ';
		}
		else
			line[++j] = str[i];
	}
	line[++j] = '\0';
	return (line);
}

char	*reset_tabs(char *str)
{
	char	*line;
	int		count;

	if (!str)
		return (NULL);
	count = tab_count(str);
	if (count == 0)
		return (ft_strdup(str));
	line = open_tabs(str, count);
	return (line);
}

void	clean_tabs(char **map)
{
	int		i;
	char	*ptr;

	i = 0;
	while (map[i])
	{
		ptr = map[i];
		map[i] = reset_tabs(ptr);
		free(ptr);
		i++;
	}
}
