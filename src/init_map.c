/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 20:53:57 by jcuzin            #+#    #+#             */
/*   Updated: 2024/04/07 03:26:34 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_map_texture_bis(int *asset, char **map, char *set, size_t *pos)
{
	char		**col;
	long long	id;

	id = -1;
	col = NULL;
	if (!asset)
		return (err_return(EXIT_FAILURE, "Memory issue", 3));
	me_set_color(asset, 0, 0, 0);
	id = me_find_str_in_tab(0, set, map);
	if (id == -1)
		return (err_return(EXIT_FAILURE, "Missing declaration", 3));
	if (id > (long long)*pos)
		*pos = id;
	col = ft_split(map[id] + ft_strlen(set), ',');
	if (!col)
		return (err_return(EXIT_FAILURE, "Asset extract failed", 3));
	if (me_tablen(col) == 3)
		me_set_color(asset, ft_atoi(col[0]), ft_atoi(col[1]), ft_atoi(col[2]));
	s_freetab(col, me_tablen(col));
	return (EXIT_SUCCESS);
}

int	init_map_texture(t_tex *asset, char **map, char *set, size_t *pos)
{
	long long	id;

	id = -1;
	if (!asset)
		return (err_return(EXIT_FAILURE, "Memory issue", 3));
	res_tex_struct(asset);
	id = me_find_str_in_tab(0, set, map);
	if (id == -1)
		return (err_return(EXIT_FAILURE, "Missing declaration", 3));
	if (id > (long long)*pos)
		*pos = id;
	if (me_find_str_in_tab(0, set, map + id + 1) != -1)
		return (err_return(EXIT_FAILURE, "Multiple declaration detected", 3));
	asset->file = ft_strdup(map[id] + ft_strlen(set));
	if (!asset->file)
		return (err_return(EXIT_FAILURE, "Asset extract failed", 3));
	return (EXIT_SUCCESS);
}

int	init_map_trim(t_map *map, char **temp)
{
	size_t	trim;

	trim = 0;
	if (!map || !temp)
		return (err_return(EXIT_FAILURE, "Memory issue", 2));
	if (init_map_texture(&map->tex_no, temp, "NO ", &trim))
		return (err_return(EXIT_FAILURE, "North texture missing", 2));
	if (init_map_texture(&map->tex_so, temp, "SO ", &trim))
		return (err_return(EXIT_FAILURE, "South texture missing", 2));
	if (init_map_texture(&map->tex_ea, temp, "EA ", &trim))
		return (err_return(EXIT_FAILURE, "East texture missing", 2));
	if (init_map_texture(&map->tex_we, temp, "WE ", &trim))
		return (err_return(EXIT_FAILURE, "West texture missing", 2));
	if (init_map_texture_bis(map->floor, temp, "F ", &trim) \
	|| init_map_texture_bis(map->roof, temp, "C ", &trim))
		return (err_return(EXIT_FAILURE, "F / C not defined", 2));
	trim += (trim > 0);
	while (!ft_strlen(temp[trim]))
		trim++;
	map->map = me_tabdup(temp + trim, me_tablen(temp + trim));
	if (!map->map)
		return (err_return(EXIT_FAILURE, "Map dup failed", 2));
	map->ylen = me_tablen(map->map);
	return (EXIT_SUCCESS);
}

