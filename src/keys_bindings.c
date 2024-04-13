/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_bindings.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 07:39:45 by jcuzin            #+#    #+#             */
/*   Updated: 2024/04/13 14:42:54 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	bind_mouse(int x, int y, void *vdata)
{
	t_data	*data;

	data = vdata;
	(void)data;
	//mlx_mouse_get_pos(data->mlxinit, data->win, &x, &y);
	printf("Mouse X/Y : %d/%d", x, y);
	return (EXIT_SUCCESS);
}

int	bind_keyboard_press(int key, t_data *data)
{
	//db_keylog(key);
	if (key == ESC_KEY)
		graph_close(data);
	if (key == A_KEY || key == Q_KEY || key == LEFT_ARROW_KEY)
		data->player.b_move = 'l';
	if (key == D_KEY || key == RIGHT_ARROW_KEY)
		data->player.b_move = 'r';
	if (key == Z_KEY || key == W_KEY || key == UP_ARROW_KEY)
		data->player.b_move = 'u';
	if (key == S_KEY || key == DOWN_ARROW_KEY)
		data->player.b_move = 'd';
	if (key == TAB_KEY)
		mlx_clear_window(data->mlxinit, data->win);
	return (EXIT_SUCCESS);
}

int	bind_keyboard_release(int key, t_data *data)
{
	//db_keylog(key);
	(void)key;
	data->player.b_move = 0;
	return (EXIT_SUCCESS);
}

int	bind_bindings(int key, t_data *data)
{
	if (key == ESC_KEY)
		graph_close(data);
	//bind_keyboard(key, data);
	return (EXIT_SUCCESS);
}
