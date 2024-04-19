/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 04:57:10 by jcuzin            #+#    #+#             */
/*   Updated: 2024/04/19 16:43:25 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	gp_move_event(t_data *data)
{
	t_player	*player;
	t_mlx		*mlx;

	(void)player;
	player = &data->player;
	mlx = &data->mlx;
	player->b_move = 1;
	if (player->y < 0)
		player->y = 0;
	if (player->x < 0)
		player->x = 0;
	return (EXIT_SUCCESS);
}

int	gp_move(t_data *data)
{
	t_player	*ply;

	gp_move_event(data);
	ply = &data->player;
	if (ply->turn_right && !ply->turn_left && ply->angle_rot > -180)
		ply->angle_rot -= (data->mlx.speed * ply->invert);
	if (ply->turn_left && !ply->turn_right && ply->angle_rot < 180)
		ply->angle_rot += (data->mlx.speed * ply->invert);
	if (ply->angle_rot > 180 || ply->angle_rot < -180)
		ply->angle_rot *= -1;
	// if (ply->angle_rot > 180 || ply->angle_rot < -180)
	// 	ply->invert *= -1;
	if (!ply->b_move)
		return (EXIT_SUCCESS);
	if (ply->move_up && !ply->move_down && ply->y > 0)
		ply->y -= data->mlx.speed;
	if (ply->move_down && !ply->move_up && ply->y < data->map.ylen)
		ply->y += data->mlx.speed;
	if (ply->move_right && !ply->move_left && ply->x < data->map.xlen)
		ply->x += data->mlx.speed;
	if (ply->move_left && !ply->move_right && ply->x > 0)
		ply->x -= data->mlx.speed;
	return (EXIT_SUCCESS);
}


int	gp_gameplay(t_data *data)
{
	t_map	*map;
	void	*mlxp;
	void	*winp;

	(void)map;
	(void)mlxp;
	(void)winp;
	if (!data)
		return (err_return(EXIT_FAILURE, "Memory issue", 2));
	map = &data->map;
	mlxp = data->mlx.init;
	winp = data->mlx.win;
	mlx_hook(data->mlx.win, 02, 1L<<0, bind_keyboard_press, data);
	mlx_hook(data->mlx.win, 03, 1L<<1, bind_keyboard_release, data);
	//mlx_mouse_move(mlxp, winp, data->mlx.win_wmid, data->mlx.win_hmid);
	return (EXIT_SUCCESS);
}
