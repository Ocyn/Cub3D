/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 21:58:04 by jcuzin            #+#    #+#             */
/*   Updated: 2024/04/17 17:34:54 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	res_tex_struct(t_tex *tex, int free)
{
	if (!tex)
		return ;
	tex->life = 0;
	if (free && tex->file)
		tex->file = s_free(&tex->file);
	tex->file = NULL;
	tex->id = NULL;
	tex->he = 0;
	tex->wi = 0;
	tex->lorem = 0;
	tex->ipsum = 0;
}

void	res_map_struct(t_map *map, int free)
{
	if (!map)
		return ;
	if (free && map->map)
		map->map = s_freetab(map->map, me_tablen(map->map));
	if (free && map->map_bis)
		map->map_bis = s_freetab(map->map_bis, me_tablen(map->map_bis));
	map->map = NULL;
	map->map_bis = NULL;
	map->xlen = 0;
	map->ylen = 0;
	res_tex_struct(&map->tex_no, free);
	res_tex_struct(&map->tex_so, free);
	res_tex_struct(&map->tex_ea, free);
	res_tex_struct(&map->tex_we, free);
	me_set_color(map->floor, 0, 0, 0);
	me_set_color(map->roof, 0, 0, 0);
	map->floor[0] = 0;
}

void	res_player_struct(t_player *player, int free)
{
	(void)free;
	if (!player)
		return ;
	player->compass = 0;
	player->xpos = 0;
	player->ypos = 0;
	player->b_move = 0;
	player->b_touch = 0;
	player->move_up = 0;
	player->move_down = 0;
	player->move_right = 0;
	player->move_left = 0;
}

void	res_data_struct(t_data *data, int free)
{
	if (!data)
		return ;
	data->arg_nb = 0;
	data->arg_tab = NULL;
	data->mlx.init = NULL;
	data->mlx.win = NULL;
	data->extra = NULL;
	data->mlx.win_w = 0;
	data->mlx.win_h = 0;
	data->mlx.win_wmid = 0;
	data->mlx.win_hmid = 0;
	data->mlx.ips = 0;
	res_map_struct(&data->map, free);
	res_player_struct(&data->player, free);
}
