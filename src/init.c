/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 20:53:57 by jcuzin            #+#    #+#             */
/*   Updated: 2024/04/03 20:40:06 by jcuzin           ###   ########.fr       */
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
	if (!map)
		return (EXIT_FAILURE);
	res_map_struct(map);
	/* DEBUG */	printf("\tImporting map");
	map->map = conv_file2tab(open(file, O_RDONLY));
	if (map->map)
		/* DEBUG */	printf("\r%sOK%s\n", "\033[0;92m", "\033[0m");
	else
	/* DEBUG */	printf("\r%sKO%s\n", "\033[0;91m", "\033[0m");
	return (EXIT_SUCCESS);
}
