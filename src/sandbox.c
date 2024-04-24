/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sandbox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:04:50 by jcuzin            #+#    #+#             */
/*   Updated: 2024/04/24 18:47:34 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	sb_telecran(t_data *data)
{
	t_tex		*north;
	t_player	*player;

	(void)north;
	north = &data->map.tex_no;
	player = &data->player;
	re_pixeltoimg(data->mlx.game, player->xpos, player->ypos \
	, conv_rgb(data->map.floor));
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
	draw_grid_tab(mlx, map->map, 10 \
	,(size_t *)data->player.x_y);
	return (EXIT_SUCCESS);
}

int	sb_line(t_data *data)
{
	t_map		*map;
	t_mlx		*mlx;
	t_player	*player;

	(void)data;
	(void)map;
	(void)mlx;
	(void)player;
	player = &data->player;
	map = &data->map;
	mlx = &data->mlx;
	return (EXIT_SUCCESS);
}

int	sb_circle(t_data *data)
{
	t_map		*map;
	t_mlx		*mlx;
	t_player	*player;
	int			coeff[2];
	int			angle;

	player = &data->player;
	map = &data->map;
	mlx = &data->mlx;
	if (player->turn_left || player->turn_right)
	{
		angle = player->angle - 90;
		math_coeff_circle(10 * mlx->game_scale, angle - 1, coeff);
		draw_line_snap(mlx, (size_t[2]){mlx->win_wmid, mlx->win_hmid} \
		, (size_t[2]){mlx->win_wmid + coeff[0], mlx->win_hmid + coeff[1]} \
		, conv_rgbtab(255, 255, 255));
		math_coeff_circle(10 * mlx->game_scale, angle, coeff);
		draw_line_snap(mlx, (size_t[2]){mlx->win_wmid, mlx->win_hmid} \
		, (size_t[2]){mlx->win_wmid + coeff[0], mlx->win_hmid + coeff[1]}, 0);
		math_coeff_circle(10 * mlx->game_scale, angle + 1, coeff);
		draw_line_snap(mlx, (size_t[2]){mlx->win_wmid, mlx->win_hmid} \
		, (size_t[2]){mlx->win_wmid + coeff[0], mlx->win_hmid + coeff[1]} \
		, conv_rgbtab(255, 255, 255));
	}
	return (EXIT_SUCCESS);
}
