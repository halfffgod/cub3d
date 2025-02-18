/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziharuty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:00:46 by ziharuty          #+#    #+#             */
/*   Updated: 2024/05/21 14:00:49 by ziharuty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] && str)
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	if (!c)
		return ((char *)str + ft_strlen(str));
	while (*str != (unsigned char)c)
		if (!*str++)
			return (0);
	return ((char *)str);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	size_t	len;
	char	*str;

	len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	i = 0;
	while (*s1)
		str[i++] = *s1++;
	while (*s2)
		str[i++] = *s2++;
	str[i] = 0;
	return (str);
}

char	*ft_substr(const char *str, unsigned int start, size_t len)
{
	char	*s;
	char	*s_start;
	size_t	i;

	s = malloc(sizeof(char) * (len + 1));
	if (!s)
		return (0);
	s_start = (char *)str + start;
	i = 0;
	while (*s_start && i < len)
		s[i++] = *s_start++;
	s[i] = 0;
	return (s);
}
