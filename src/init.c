/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 20:53:57 by jcuzin            #+#    #+#             */
/*   Updated: 2024/04/04 21:14:21 by jcuzin           ###   ########.fr       */
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

int	init_map_struct(t_map *map, char *file)
{
	size_t	my;
	size_t	xmax;

	my = 0;
	xmax = 0;
	if (!map)
		return (EXIT_FAILURE);
	res_map_struct(map);
	map->map = conv_file2tab(file);
	map->ylen = me_tablen(map->map);
	while (my < map->ylen)
	{
		if (ft_strchr(map->map[my], '\n'))
			map->map[my][ft_strlen(map->map[my]) - 1] = 0;
		if (ft_strlen(map->map[my]) > xmax)
			xmax = ft_strlen(map->map[my]);
		my++;
	}
	if (!map->map)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
