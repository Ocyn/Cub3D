/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 07:39:45 by jcuzin            #+#    #+#             */
/*   Updated: 2024/04/03 20:54:07 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_file(char *file)
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

int	parse_map(t_map *map)
{
	size_t	my;
	int		b_rep;

	my = 0;
	b_rep = 0;
	/* DEBUG */	printf("\tParsing map");
	if (!map)
		return (EXIT_FAILURE);
	while (my < map->ylen)
	{
		b_rep += (!me_str2strcmp(map->map[my], "NSWE"));
		if (me_str2strcmp(map->map[my], "01NSWE"))
			return (EXIT_FAILURE);
		my++;
	}
	if (b_rep == 1)
		/* DEBUG */	printf("\r%sOK%s\n", "\033[0;92m", "\033[0m");
	else
		/* DEBUG */	printf("\r%sKO%s\n", "\033[0;91m", "\033[0m");
	err_custom((b_rep != 1), "Invalid map", F_RED);
	return ((b_rep != 1));
}

int	parse_main(t_data *data)
{
	if (!data)
		return (EXIT_FAILURE);
	if (parse_file(data->arg_tab[1]))
		return (EXIT_FAILURE);
	if (init_map_struct(&data->map, data->arg_tab[1])
		|| parse_map(&data->map))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
