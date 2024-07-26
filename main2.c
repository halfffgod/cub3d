/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziharuty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:02:16 by ziharuty          #+#    #+#             */
/*   Updated: 2024/05/25 08:11:31 by nbadalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

//check filename's validableity
char	*get_extension(char *filename)
{
	int	len;
	int	i;

	i = 0;
	len = strlen(filename) - 1;
	while (len >= 0 && filename[len] != '.')
	{
		len--;
		i++;
	}
	i++;
	if (i > 0)
		return (&filename[len]);
	return (NULL);
}

void	file_validity(char *filename)
{
	char	*extension;
	int		len;

	len = ft_strlen(filename) - 1;
	extension = NULL;
	while (filename[len])
	{
		if (filename[len] == '.')
		{
			extension = get_extension(filename);
			if (extension_compare(extension, ".cub") != 0)
				return ;
		}
		len--;
	}
	write(2, "Error: Not valid filename\n", 26);
	exit(1);
}

void	main_helper(t_map *map_struct, char **map, char **argv)
{
	file_validity(argv[1]);
	map_struct->map = map;
	get_textures(map, map_struct);
	get_playfield(map, map_struct);
	is_empty_line(map_struct->playfield);
	if (!dirs(map_struct->playfield))
		exit(1);
	if (!is_map_symb(map_struct->playfield))
		exit(1);
	if (!walls_spaces(map_struct->playfield))
		exit(1);
	if (!checking_walls(map))
		exit(1);
	epur_texture(map_struct->texture);
	if (!validate_color_texture(map_struct->texture, 6))
		exit(1);
}

void	main_helper2(t_map *mapp)
{
	mapp->result = (char **)malloc(sizeof(char *) * (7));
	mapp->result2 = (char **)malloc(sizeof(char *) * (7));
	if (!parse_textures(mapp->texture, mapp))
		ft_errorwithexit("Error: Invalid Map");
	if (!substring_one(mapp->result, "NO"))
		exit(1);
	if (!substring_one(mapp->result, "SO"))
		exit(1);
	if (!substring_one(mapp->result, "EA"))
		exit(1);
	if (!substring_one(mapp->result, "WE"))
		exit(1);
	if (!validate_colors(mapp->texture, mapp))
		exit(1);
}

void	free_texture(t_map *mapp)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		free(mapp->texture[i]);
		i++;
	}
	free(mapp->texture);
	mapp->texture = NULL;
}
