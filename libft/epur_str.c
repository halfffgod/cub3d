/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziharuty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:09:18 by ziharuty          #+#    #+#             */
/*   Updated: 2024/05/21 14:09:20 by ziharuty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	ft_isblank(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	if (c >= 9 && c <= 13)
		return (1);
	return (0);
}

char	*epurstr(char *s)
{
	int		len;
	char	*new_str;
	char	*p;

	len = ft_strlen(s);
	while (len && ft_isblank(s[len - 1]))
		--len;
	while (len && ft_isblank(*s) && *s++)
		--len;
	new_str = malloc((len + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	p = new_str;
	while (len--)
	{
		if (!ft_isblank(*s) || (*(s + 1) && !ft_isblank(*(s + 1))))
			*p++ = *s;
		s++;
	}
	*p = '\0';
	return (new_str);
}
