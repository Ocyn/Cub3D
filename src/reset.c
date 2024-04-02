/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 21:58:04 by jcuzin            #+#    #+#             */
/*   Updated: 2024/04/02 22:00:04 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	res_map_struct(t_map *map)
{
	if (!map)
		return ;
	map->map = NULL;
	map->fd = 0;
	map->xlen = 0;
	map->ylen = 0;
}

void	res_player_struct(t_player *player)
{
	if (!player)
		return ;
	player->compass = 0;
	player->xpos = 0;
	player->ypos = 0;
	player->b_move = 0;
	player->b_interact = 0;
}

void	res_data_struct(t_data *data)
{
	if (!data)
		return ;
	data->arg_nb = 0;
	data->arg_tab = NULL;
	res_map_struct(&data->map);
	res_player_struct(&data->player);
}
