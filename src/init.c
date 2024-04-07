/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 20:53:57 by jcuzin            #+#    #+#             */
/*   Updated: 2024/04/07 05:22:57 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_data_struct(t_data *data, int argc, char **argv)
{
	if (!data)
		return (err_return(EXIT_FAILURE, "Memory issue", 1));
	res_data_struct(data);
	if (argc != 2)
		return (err_return(EXIT_FAILURE, "Invalid argument format", 1));
	data->arg_nb = argc;
	data->arg_tab = argv;
	return (EXIT_SUCCESS);
}

int	init_map_struct(t_map *map, char *file)
{
	char		**temp;
	long long	my;
	long long	xmax;

	my = -1;
	xmax = 0;
	temp = conv_file2tab(file);
	if (!map || !temp)
		return (err_return(EXIT_FAILURE, "Memory issue", 1));
	res_map_struct(map);
	map->ylen = me_tablen(temp);
	while (++my < map->ylen)
	{
		if (ft_strchr(temp[my], '\n'))
			temp[my][ft_strlen(temp[my]) - 1] = 0;
		if ((long long)ft_strlen(temp[my]) > xmax)
			xmax = ft_strlen(temp[my]);
	}
	if (init_map_trim(map, temp))
	{
		temp = s_freetab(temp, me_tablen(temp));
		return (err_return(EXIT_FAILURE, "Map trim failed", 1));
	}
	return (EXIT_SUCCESS);
}

int	init_player_struct(t_player *player, t_map map)
{
	if (!player)
		return (err_return(EXIT_FAILURE, "Memory issue", 1));
	res_player_struct(player);
	player->ypos = me_find_str_in_tab(0, "N", map.map);
	if (player->ypos == -1)
		player->ypos = me_find_str_in_tab(0, "E", map.map);
	if (player->ypos == -1)
		player->ypos = me_find_str_in_tab(0, "W", map.map);
	if (player->ypos == -1)
		player->ypos = me_find_str_in_tab(0, "S", map.map);
	if (player->ypos == -1)
		return (err_return(EXIT_FAILURE, "Player position not found", 1));
	player->xpos = me_find_str_in_str(map.map[(long)player->ypos], "N");
	if (player->xpos == -1)
		player->xpos = me_find_str_in_str(map.map[(long)player->ypos], "E");
	if (player->xpos == -1)
		player->xpos = me_find_str_in_str(map.map[(long)player->ypos], "W");
	if (player->xpos == -1)
		player->xpos = me_find_str_in_str(map.map[(long)player->ypos], "S");
	if (player->xpos == -1)
		return (err_return(EXIT_FAILURE, "Player position not found", 1));
	return (EXIT_SUCCESS);
}
