/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 20:53:57 by jcuzin            #+#    #+#             */
/*   Updated: 2024/04/13 05:12:19 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_data_struct(t_data *data, int argc, char **argv)
{
	if (!data)
		return (err_return(EXIT_FAILURE, "Memory issue", 1));
	res_data_struct(data, 0);
	if (argc != 2)
		return (err_return(EXIT_FAILURE, "Invalid argument format", 0));
	data->arg_nb = argc;
	data->arg_tab = argv;
	data->win_h = WIN_HEIGHT;
	data->win_w = WIN_WIDTH;
	data->win_h_center = (data->win_h / 2);
	data->win_w_center = (data->win_w / 2);
	return (EXIT_SUCCESS);
}

int	init_map_struct(t_map *map, char *file)
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
	if (init_map_trim(map, temp))
		return (s_freetab(temp, me_tablen(temp)) \
		, err_return(EXIT_FAILURE, "Map trim failed", 1));
	map->map_bis = me_tabdup(map->map, me_tablen(map->map));
	if (!map->map_bis)
		err_return(EXIT_FAILURE, "Failed to clone", 1);
	return (s_freetab(temp, me_tablen(temp)), !map->map_bis);
}

int	init_player_struct(t_player *ply, t_map map)
{
	if (!ply || !map.map || !map.map[0])
		return (err_return(EXIT_FAILURE, "Memory issue", 1));
	res_player_struct(ply, 0);
	while (ply->ypos < map.ylen && !ft_strchr(map.map[ply->ypos], 'N') \
	&& !ft_strchr(map.map[ply->ypos], 'S') \
	&& !ft_strchr(map.map[ply->ypos], 'E') \
	&& !ft_strchr(map.map[ply->ypos], 'W'))
		ply->ypos++;
	while (map.map[ply->ypos][ply->xpos] \
	&& map.map[ply->ypos][ply->xpos] != 'N' \
	&& map.map[ply->ypos][ply->xpos] != 'S' \
	&& map.map[ply->ypos][ply->xpos] != 'E' \
	&& map.map[ply->ypos][ply->xpos] != 'W')
		ply->xpos++;
	if (ply->xpos == map.xlen && ply->ypos == map.ylen)
		return (err_return(EXIT_FAILURE, "Player position not found", 1));
	ply->compass = map.map[ply->ypos][ply->xpos];
	return (EXIT_SUCCESS);
}
