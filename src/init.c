/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 20:53:57 by jcuzin            #+#    #+#             */
/*   Updated: 2024/03/28 23:29:36 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_map_struct(t_map *map)
{
	if (!map)
		return (EXIT_FAILURE);
	map->map = NULL;
	map->fd = 0;
	map->xlen = 0;
	map->ylen = 0;
	return (EXIT_SUCCESS);
}

int	init_player_struct(t_player *player)
{
	if (!player)
		return (EXIT_FAILURE);
	player->compass = 0;
	player->xpos = 0;
	player->ypos = 0;
	player->b_move = 0;
	player->b_interact = 0;
	return (EXIT_SUCCESS);
}

int	init_data_struct(t_data *data)
{
	if (!data)
		return (EXIT_FAILURE);
	data->arg_nb = 0;
	data->arg_tab = NULL;
	init_map_struct(&data->map);
	init_player_struct(&data->player);
	return (EXIT_SUCCESS);
}

int	initset_data_struct(t_data *data, int argc, char **argv)
{
	if (!data)
		return (EXIT_FAILURE);
	data->arg_nb = argc;
	data->arg_tab = argv;
	return (EXIT_SUCCESS);
}
