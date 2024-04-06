/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 07:39:45 by jcuzin            #+#    #+#             */
/*   Updated: 2024/04/07 01:04:10 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_file(char *file)
{
	int	fd;

	fd = 0;
	if (!file)
		return (EXIT_FAILURE);
	if (ft_strlen(file) - me_find_str_in_str(file, ".cub") != 4)
		return (err_return(EXIT_FAILURE, "Invalid file name", 1));
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
		return (err_return(EXIT_FAILURE, "Memory issue", 1));
	if (parse_map_borders(map))
		return (err_return(EXIT_FAILURE, "Map's borders open", 1));
	while (my < map->ylen)
	{
		if (me_str2strcmp(map->map[my], "01NSWE \n\t"))
			return (err_return(EXIT_FAILURE, "Invalid character detected", 1));
		ct += me_strchrn(map->map[my], 'N') + me_strchrn(map->map[my], 'S') \
		+ me_strchrn(map->map[my], 'W') + me_strchrn(map->map[my], 'E');
		if (ct > 1)
			return (err_return(EXIT_FAILURE, "Many players detected", 1));
		my++;
	}
	return (EXIT_SUCCESS);
}

int	parse_main(t_data *data)
{
	if (!data)
		return (err_return(EXIT_FAILURE, "Memory issue", 0));
	if (parse_file(data->arg_tab[1]))
		return (err_return(EXIT_FAILURE, "Parse file failed", 0));
	/* DEBUG */	printf("Importing map");
	if (init_map_struct(&data->map, data->arg_tab[1]))
		return (err_return(EXIT_FAILURE, "Map init failed", 0));
	err_return(EXIT_SUCCESS, "", 0);
	db_showmap(data->map);
	/* DEBUG */	printf("Parsing map");
	if (parse_map(&data->map))
		return (err_return(EXIT_FAILURE, "Parse map failed", 0));
	err_return(EXIT_SUCCESS, "", 0);
	return (EXIT_SUCCESS);
}
