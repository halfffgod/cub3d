/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getmap2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziharuty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:00:57 by ziharuty          #+#    #+#             */
/*   Updated: 2024/05/25 08:07:34 by nbadalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

//Finds if there is printable in string
int	find_char(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] > 32 && str[i] < 127)
			return (0);
	}
	return (-1);
}

//campareing
int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned const char	*c1;
	unsigned const char	*c2;
	size_t				i;
	size_t				n;

	if (ft_strlen(s1) != ft_strlen(s2))
		return (-1);
	n = ft_strlen(s2);
	c1 = (unsigned const char *)s1;
	c2 = (unsigned const char *)s2;
	i = 0;
	while (i < n)
	{
		if ((c1[i] != c2[i] || s1[i] == 0) || s2[i] == 0)
			return (c1[i] - c2[i]);
		i++;
	}
	return (0);
}

//reads file, stores it like a one line text, 
//splits with new lines and stores in map
char	**getmap(char *file)
{
	int		fd;
	char	*text;
	char	**map;

	fd = open(file, O_RDONLY);
	map = NULL;
	if (fd == -1)
		return (NULL);
	text = read_map(fd);
	if (!text)
		return (NULL);
	map = ft_split(text, '\n');
	free(text);
	close(fd);
	return (map);
}

//if it is printable char or the flag is more than 6
//(I thought it is for 6lines in map), and stores it in text
void	norming_map(char **text, char **singleline, int *flag)
{
	char	*ptr;

	ptr = *text;
	if (find_char(*singleline) == 0 || *flag > 6)
	{
		(*flag)++;
		if (ft_strcmp(*singleline, "\n") == 0)
		{
			free(*singleline);
			*singleline = ft_strdup("    \n");
		}
		if (*text == NULL)
			*text = ft_strdup(*singleline);
		else
			*text = ft_strjoin(ptr, *singleline);
		free(ptr);
	}
}

//reads fd line by line, norms and  goes ahead
char	*read_map(int fd)
{
	char	*singleline;
	char	*text;
	int		flag;

	flag = 0;
	text = NULL;
	singleline = get_next_line(fd);
	while (singleline)
	{
		norming_map(&text, &singleline, &flag);
		free(singleline);
		singleline = get_next_line(fd);
	}
	return (text);
}
