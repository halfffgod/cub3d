/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziharuty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:04:25 by ziharuty          #+#    #+#             */
/*   Updated: 2024/05/21 14:04:26 by ziharuty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	init_vc(t_valid *v)
{
	v->foundmap = 0;
	v->foundtextures = 0;
	v->foundfloorcolor = 0;
	v->line = NULL;
}

int	validate_color_texture(char **texture, int numLines)
{
	t_valid	v;
	int		i;

	i = 0;
	init_vc(&v);
	while (i < numLines)
	{
		v.line = texture[i];
		if (!v.foundtextures && (ft_strncmp(v.line, "NO", 2) == 0 \
		|| ft_strncmp(v.line, "SO", 2) == 0 || \
		ft_strncmp(v.line, "WE", 2) == 0 || ft_strncmp(v.line, "EA", 2) == 0))
		{
			v.foundtextures = 1;
			continue ;
		}
		if (!v.foundfloorcolor && ft_strncmp(v.line, "F", 1) == 0)
		{
			v.foundfloorcolor = 1;
			continue ;
		}
		i++;
	}
	if (!v.foundtextures || !v.foundfloorcolor)
		return (ft_error("Error: Textures or color element not found.\n"));
	return (1);
}
