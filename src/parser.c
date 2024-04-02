/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 07:39:45 by jcuzin            #+#    #+#             */
/*   Updated: 2024/04/02 23:19:54 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	pa_checkfile(char *file)
{
	int	fd;

	fd = 0;
	if (!file)
		return (EXIT_FAILURE);
	fd = open(file, O_RDONLY);
	if (fd < 2)
	{
		err_stderr(1);
		return (EXIT_FAILURE);
	}
	close(fd);
	return (EXIT_SUCCESS);
}

int	pa_mapformat(t_map *map)
{
	size_t	mx;
	size_t	my;
	int		b_rep;

	my = 0;
	b_rep = 0;
	if (!map)
		return (EXIT_FAILURE);
	while (my < map->ylen)
	{
		mx = 0;
		while (mx < map->xlen)
		{
			b_rep += (map->map[my][mx] == 'N' || map->map[my][mx] == 'E' \
			|| map->map[my][mx] == 'W' || map->map[my][mx] == 'S');
			if (map->map[my][mx] != '0' && map->map[my][mx] != '1' \
			&& map->map[my][mx] != 'N' && map->map[my][mx] != 'E' \
			&& map->map[my][mx] != 'W' && map->map[my][mx] != 'S')
				return (EXIT_FAILURE);
			mx++;
		}
		my++;
	}
	return ((b_rep != 1));
}

int	pa_main(t_data *data)
{
	if (!data)
		return (EXIT_FAILURE);
	if (pa_checkfile(data->arg_tab[1]))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
