/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_bindings.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 07:39:45 by jcuzin            #+#    #+#             */
/*   Updated: 2024/04/19 16:20:04 by jcuzin           ###   ########.fr       */
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
	//db_key_event(key);
	if (key == ESC_KEY)
		graph_close(data);
	if (key == PLUS_KEY)
	{
		misc_default_game(data, 0);
		data->mlx.game_scale += (data->mlx.game_scale / 8);
	}
	if (key == MINUS_KEY)
	{
		misc_default_game(data, 0);
		data->mlx.game_scale -= (data->mlx.game_scale / 8) * (data->mlx.game_scale > 2);
	}
	while (data->mlx.game_scale > 100)
		data->mlx.game_scale -= (data->mlx.game_scale / 8);
	while (data->mlx.game_scale < 2)
		data->mlx.game_scale += (data->mlx.game_scale / 8);
	if (key == TAB_KEY)
	{
		misc_default_game(data, 1);
		misc_default_game(data, 0);
	}
	return (EXIT_SUCCESS);
}
