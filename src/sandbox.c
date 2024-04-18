/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sandbox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:04:50 by jcuzin            #+#    #+#             */
/*   Updated: 2024/04/18 17:36:05 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//Sandbox function

int	sb_telecran(t_data *data) 
{
	t_tex		*north;
	t_player	*player;

	(void)north;
	north = &data->map.tex_no;
	player = &data->player;
	re_pixeltoimg(data->mlx.game, player->xpos, player->ypos, conv_rgb(data->map.floor));
	return (EXIT_SUCCESS);
}

int	sb_movingmap(t_data *data)
{
	t_map	*map;
	t_mlx	*mlx;

	(void)data;
	(void)map;
	(void)mlx;
	map = &data->map;
	mlx = &data->mlx;
	draw_grid_tab(mlx, map->map, 10, (size_t[2]){data->player.x, data->player.y});
	//draw_grid_sq(mlx, (size_t[2]){200, 200}, (size_t[2]){data->player.x, data->player.y}, conv_rgbtab(255, 255, 255));
	//draw_square(mlx, (size_t[2]){200, 200}, (size_t[2]){data->player.x, data->player.y}, conv_rgbtab(255, 255, 255));
	return (EXIT_SUCCESS);
}
