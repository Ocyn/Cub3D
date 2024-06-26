/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_bindings.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 07:39:45 by jcuzin            #+#    #+#             */
/*   Updated: 2024/06/05 19:10:47 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	bind_keyboard_press(int key, t_data *data)
{
	bind_bindings(key, data);
	if (key == A_KEY || key == Q_KEY)
		data->player.move_left = 1;
	if (key == D_KEY)
		data->player.move_right = 1;
	if (key == Z_KEY || key == W_KEY)
		data->player.move_up = 1;
	if (key == S_KEY)
		data->player.move_down = 1;
	if (key == RIGHT_ARROW_KEY)
		data->player.turn_right = 1;
	if (key == LEFT_ARROW_KEY)
		data->player.turn_left = 1;
	return (EXIT_SUCCESS);
}

int	bind_keyboard_release(int key, t_data *data)
{
	(void)key;
	if (key == A_KEY || key == Q_KEY)
		data->player.move_left = 0;
	if (key == D_KEY)
		data->player.move_right = 0;
	if (key == Z_KEY || key == W_KEY)
		data->player.move_up = 0;
	if (key == S_KEY)
		data->player.move_down = 0;
	if (key == RIGHT_ARROW_KEY)
		data->player.turn_right = 0;
	if (key == LEFT_ARROW_KEY)
		data->player.turn_left = 0;
	return (EXIT_SUCCESS);
}

int	bind_mouse(int key, int m_x, int m_y, t_data *data)
{
	data->mlx.mouse_xy[0] = m_x;
	data->mlx.mouse_xy[1] = m_y;
	if (key == MOUSE_LCLICK)
	{
		data->mlx.mouse_cam = (!data->mlx.mouse_cam);
		if (data->mlx.mouse_cam)
			mlx_mouse_hide(data->mlx.init, data->mlx.win);
		else
			mlx_mouse_show(data->mlx.init, data->mlx.win);
	}
	if (key == MOUSE_RCLICK)
		(void)data;
	if (key == MOUSE_MCLICK)
		(void)data;
	if (key == MOUSE_USCROLL && data->mlx.fov > 10)
		data->mlx.fov--;
	if (key == MOUSE_DSCROLL && data->mlx.fov < 180)
		data->mlx.fov++;
	if (key == MOUSE_USCROLL || key == MOUSE_DSCROLL)
		misc_default_game(data, 0);
	return (EXIT_SUCCESS);
}

int	bind_bindings(int key, t_data *data)
{
	if (key == ESC_KEY)
		graph_close(data);
	if (key == PLUS_KEY && data->mlx.gscale < 50)
		data->mlx.gscale += 1;
	if (key == MINUS_KEY && data->mlx.gscale > 4)
		data->mlx.gscale -= 1;
	if (key == PLUS_KEY || key == MINUS_KEY || key == TAB_KEY)
		misc_default_game(data, 0);
	if (key == TAB_KEY)
		misc_default_game(data, 1);
	return (EXIT_SUCCESS);
}
