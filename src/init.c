/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 20:53:57 by jcuzin            #+#    #+#             */
/*   Updated: 2024/04/07 00:57:28 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_data_struct(t_data *data, int argc, char **argv)
{
	if (!data)
		return (EXIT_FAILURE);
	res_data_struct(data);
	data->arg_nb = argc;
	data->arg_tab = argv;
	if (err_custom((argc != 2), "Invalid argument format", 0))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	init_map_texture(t_tex *asset, char **map, char *set)
{
	long long	id;

	id = -1;
	if (!asset)
		return (err_return(EXIT_FAILURE, "Memory issue", 3));
	res_tex_struct(asset);
	id = me_find_str_in_tab(0, set, map);
	if (id == -1)
		return (err_return(EXIT_FAILURE, "Missing declaration", 3));
	asset->file = ft_strdup(map[id] + ft_strlen(set));
	return (EXIT_SUCCESS);
}

static int	init_map_trim(t_map *map, char **temp)
{
	size_t	trim;

	trim = 0;
	if (!map || !temp)
		return (err_return(EXIT_FAILURE, "Memory issue", 2));
	printf("\n");
	if (init_map_texture(&map->tex_no, temp, "NO "))
		return (err_return(EXIT_FAILURE, "NO missing", 2));
	if (init_map_texture(&map->tex_so, temp, "SO "))
		return (err_return(EXIT_FAILURE, "SO missing", 2));
	if (init_map_texture(&map->tex_ea, temp, "EA "))
		return (err_return(EXIT_FAILURE, "EA missing", 2));
	if (init_map_texture(&map->tex_we, temp, "WE "))
		return (err_return(EXIT_FAILURE, "WE missing", 2));
	map->map = me_tabdup(temp + trim, me_tablen(temp + trim));
	if (!map->map)
		return (err_return(EXIT_FAILURE, "Map dup failed", 2));
	return (EXIT_SUCCESS);
}

int	init_map_struct(t_map *map, char *file)
{
	char	**temp;
	size_t	my;
	size_t	xmax;

	my = 0;
	xmax = 0;
	temp = NULL;
	if (!map)
		return (EXIT_FAILURE);
	res_map_struct(map);
	temp = conv_file2tab(file);
	if (!temp)
		return (EXIT_FAILURE);
	map->ylen = me_tablen(temp);
	while (my < map->ylen)
	{
		if (ft_strchr(temp[my], '\n'))
			temp[my][ft_strlen(temp[my]) - 1] = 0;
		if (ft_strlen(temp[my]) > xmax)
			xmax = ft_strlen(temp[my]);
		my++;
	}
	if (init_map_trim(map, temp))
		return (err_return(EXIT_FAILURE, "Map trim failed", 1));
	return (EXIT_SUCCESS);
}
