/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_bindings.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 07:39:45 by jcuzin            #+#    #+#             */
/*   Updated: 2024/04/19 00:52:45 by jcuzin           ###   ########.fr       */
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

int	bind_bindings(int key, t_data *data)
{
	if (key == ESC_KEY)
		graph_close(data);
	if (key == TAB_KEY)
	{
		misc_clear_screen(data->mlx.game);
		data->player.x = data->player.xpos;
		data->player.y = data->player.ypos;
		data->mlx.minimap_y = (data->mlx.minimap_size[1] / 2) - data->player.ypos * GAME_SCALING;
		data->mlx.minimap_x = (data->mlx.minimap_size[0] / 2) - data->player.xpos * GAME_SCALING;
	}
	return (EXIT_SUCCESS);
}
