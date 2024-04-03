/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 20:53:57 by jcuzin            #+#    #+#             */
/*   Updated: 2024/04/03 23:49:14 by jcuzin           ###   ########.fr       */
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
	if (err_custom((argc != 2), "Invalid argument format", "\033[0;91m"))
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
	/* DEBUG */	printf("\tImporting map");
	map->map = conv_file2tab(file);
	map->ylen = me_tablen(map->map);
	if (map->map)
		printf("\r%sOK%s\n", "\033[0;92m", "\033[0m");
	else
		printf("\r%sKO%s\n", "\033[0;91m", "\033[0m");
	while (my < map->ylen)
	{
		if (ft_strlen(map->map[my]) > xmax)
			xmax = ft_strlen(map->map[my]);
		my++;
	}
	if (!map->map)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
