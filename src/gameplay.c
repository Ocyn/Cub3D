/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 04:57:10 by jcuzin            #+#    #+#             */
/*   Updated: 2024/04/18 20:39:59 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	gp_move(t_data *data)
{
	t_player	*player;
	double		speed;

	player = &data->player;
	speed = PLAYER_SPEED * 0.1;
	if (player->turn_right && !player->turn_left)
		player->angle_rot -= speed * (player->angle_rot > -360);
	if (player->turn_left && !player->turn_right)
		player->angle_rot += speed;
	player->angle_rot = (int)player->angle_rot % 360;
	player->look = player->angle_rot;
	if (!player->b_move)
		return (EXIT_SUCCESS);
	if (player->move_up && !player->move_down)
		player->y -= speed * (player->y > 0);
	if (player->move_down && !player->move_up)
		player->y += speed * (player->y + 1 < data->mlx.win_h);
	if (player->move_right && !player->move_left)
		player->x += speed * (player->x + 1 < data->mlx.win_w);
	if (player->move_left && !player->move_right)
		player->x -= speed * (player->x > 0);
	mmap_move(data);
	player->ypos = player->y;
	player->xpos = player->x;
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
