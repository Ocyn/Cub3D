/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 07:39:45 by jcuzin            #+#    #+#             */
/*   Updated: 2024/04/04 21:55:17 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_file(char *file)
{
	int	fd;

	fd = 0;
	if (!file)
		return (EXIT_FAILURE);
	printf("\nTEST FILE [%d]\n", ft_strlen(file) - me_find_str_in_str(file, ".cub"));
	if (ft_strlen(file) - me_find_str_in_str(file, ".cub") != 4)
		return (db_return(EXIT_FAILURE, "Invalid file name"));
	fd = open(file, O_RDONLY);
	if (fd < 2)
	{
		err_stderr(1);
		return (EXIT_FAILURE);
	}
	close(fd);
	return (EXIT_SUCCESS);
}

int	parse_map_borders(t_map *map)
{
	if (ft_strlen(map->map[0]) != me_strchrn(map->map[0], '1'))
		return (EXIT_FAILURE);
	if (ft_strlen(map->map[(size_t)map->ylen - 1]) \
	!= me_strchrn(map->map[(size_t)map->ylen - 1], '1'))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	parse_map(t_map *map)
{
	size_t	my;
	size_t	ct;

	my = 0;
	ct = 0;
	if (!map)
		return (db_return(EXIT_FAILURE, "Map address not found"));
	if (parse_map_borders(map))
		return (db_return(EXIT_FAILURE, "Map's borders open"));
	while (my < map->ylen)
	{
		if (me_str2strcmp(map->map[my], "01NSWE \n\t"))
			return (db_return(EXIT_FAILURE, "Invalid character detected"));
		ct += me_strchrn(map->map[my], 'N') + me_strchrn(map->map[my], 'S') \
		+ me_strchrn(map->map[my], 'W') + me_strchrn(map->map[my], 'E');
		if (ct > 1)
			return (db_return(EXIT_FAILURE, "Many players detected"));
		my++;
	}
	return (EXIT_SUCCESS);
}

int	parse_main(t_data *data)
{
	if (!data)
		return (EXIT_FAILURE);
	if (parse_file(data->arg_tab[1]))
		return (EXIT_FAILURE);
	/* DEBUG */	printf("\t\t\t\tImporting map");
	if (init_map_struct(&data->map, data->arg_tab[1]))
		return (EXIT_FAILURE);
	db_return(EXIT_SUCCESS, "");
	db_showmap(data->map);
	/* DEBUG */	printf("\t\t\t\tParsing map");
	if (parse_map(&data->map))
		return (EXIT_FAILURE);
	db_return(EXIT_SUCCESS, "");
	return (EXIT_SUCCESS);
}
