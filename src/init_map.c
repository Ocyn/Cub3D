/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 20:53:57 by jcuzin            #+#    #+#             */
/*   Updated: 2024/06/19 12:13:29 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_map_struct(t_data *data, t_map *map, char *file)
{
	char		**temp;
	long long	my;

	my = -1;
	temp = conv_file2tab(file);
	if (!map || !temp)
		return (err_return(EXIT_FAILURE, "Memory issue", 1));
	res_map_struct(map, 0);
	map->ylen = me_tablen(temp);
	while (++my < map->ylen)
	{
		if (ft_strchr(temp[my], '\n'))
			temp[my][ft_strlen(temp[my]) - 1] = 0;
		if ((long long)ft_strlen(temp[my]) > map->xlen)
			map->xlen = ft_strlen(temp[my]);
	}
	if (init_map_trim(map, temp, 0))
		return (s_freetab(temp, me_tablen(temp)) \
		, err_return(EXIT_FAILURE, "Map trim failed", 1));
	init_map_spaces(map);
	map->data = data;
	map->minimap = &data->minimap;
	s_freetab(temp, me_tablen(temp));
	return (EXIT_SUCCESS);
}

int	init_map_texture_bis(int *asset, char **map, char *set, size_t *pos)
{
	char		**col;
	long long	id;

	if (!asset)
		return (err_return(EXIT_FAILURE, "Memory issue", 3));
	me_set_color(asset, 0, 0, 0);
	id = me_find_str_in_tab(0, set, map);
	if (id == -1)
		return (err_return(EXIT_FAILURE, "Missing declaration", 3));
	if (id > (long long)*pos)
		*pos = id;
	col = ft_split(map[id] + ft_strlen(set), ',');
	if (!col || me_tablen(col) != 3)
		return (err_return(EXIT_FAILURE, "Asset extract failed", 3));
	else if (me_set_color(asset \
	, ft_atoi(col[0]), ft_atoi(col[1]), ft_atoi(col[2])))
		return (err_return(EXIT_FAILURE, "Asset extract failed", 3));
	id = -1;
	while (col[++id])
		if (me_scan_digit(col[id]))
			return (s_freetab(col, me_tablen(col)) \
			, err_return(EXIT_FAILURE, "Invalid color code format", 3));
	s_freetab(col, me_tablen(col));
	return (EXIT_SUCCESS);
}

int	init_map_texture(t_tex *asset, char **map, char *set, size_t *pos)
{
	long long	id;
	int			fd;

	id = -1;
	fd = 0;
	if (!asset)
		return (err_return(EXIT_FAILURE, "Memory issue", 3));
	res_tex_struct(asset, 0);
	id = me_find_str_in_tab(0, set, map);
	if (id == -1)
		return (err_return(EXIT_FAILURE, "Missing declaration", 3));
	if (id > (long long)*pos)
		*pos = id;
	if (me_find_str_in_tab(0, set, map + id + 1) != -1)
		return (err_return(EXIT_FAILURE, "Multiple declaration detected", 3));
	asset->file = ft_strdup(map[id] + ft_strlen(set));
	if (ft_strncmp(asset->file + (ft_strlen(asset->file) - 3), "xpm", 3))
		return (err_return(EXIT_FAILURE, "Texture not an xpm", 3));
	fd = open(asset->file, O_RDONLY);
	if (fd == -1)
		return (err_return(EXIT_FAILURE, "Texture file failed to open", 3));
	close(fd);
	if (!asset->file)
		return (err_return(EXIT_FAILURE, "Asset extract failed", 3));
	return (EXIT_SUCCESS);
}

int	init_map_spaces(t_map *map)
{
	long	i;
	long	u;

	i = 0;
	while (i < map->ylen && map && map->map[i])
	{
		u = 0;
		while (map->map[i][u])
		{
			if (map->map[i][u] == ' ')
				map->map[i][u] = '1';
			u++;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int	init_map_trim(t_map *map, char **temp, size_t trim)
{
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
	|| init_map_texture_bis(map->sky, temp, "C ", &trim))
		return (err_return(EXIT_FAILURE, "F / C not defined", 2));
	map->floor_h = conv_rgb(map->floor);
	map->sky_h = conv_rgb(map->sky);
	trim += (trim > 0);
	while (!ft_strlen(temp[trim]))
		trim++;
	map->map = me_tabdup_ratio(temp + trim, me_tablen(temp + trim));
	if (!map->map || !map->map[0])
		return (err_return(EXIT_FAILURE, "Map dup failed", 2));
	map->ylen = me_tablen(map->map);
	return (EXIT_SUCCESS);
}
