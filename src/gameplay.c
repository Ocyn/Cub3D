/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 04:57:10 by jcuzin            #+#    #+#             */
/*   Updated: 2024/04/29 23:17:58 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	gp_physic_engine(t_data *data)
{
	double		border;
	t_player	*mc;
	t_mlx		*mlx;

	border = 0.5;
	mc = &data->player;
	mlx = &data->mlx;
	if (data->map.map[(int)round(*mc->y + border)][(int)round(*mc->x)] == '1')
		*mc->y -= mlx->speed;
	if (data->map.map[(int)round(*mc->y - border)][(int)round(*mc->x)] == '1')
		*mc->y += mlx->speed;
	if (data->map.map[(int)round(*mc->y)][(int)round(*mc->x + border)] == '1')
		*mc->x -= mlx->speed;
	if (data->map.map[(int)round(*mc->y)][(int)round(*mc->x - border)] == '1')
		*mc->x += mlx->speed;
	if (mc->angle < 0)
		mc->angle = 360;
	if (mc->angle > 360)
		mc->angle = 0;
	return (EXIT_SUCCESS);
}

int	gp_mouse_camera(int x, int y, t_data *data)
{
	int			mouse;

	if (!data->mlx.mouse_cam)
		return (EXIT_SUCCESS);
	data->mlx.mouse_xy[0] = x;
	data->mlx.mouse_xy[1] = y;
	mouse = data->mlx.win_wmid - data->mlx.mouse_xy[0];
	if (abs(mouse) > 30 || abs(data->mlx.win_hmid - data->mlx.mouse_xy[1]) > 100)
	{
		mlx_mouse_move(data->mlx.init, data->mlx.win \
		, data->mlx.win_wmid, data->mlx.win_hmid);
		data->player.angle -= mouse * CAMERA_SPEED * 0.001;
	}
	return (EXIT_SUCCESS);
}

void	gp_move(t_data *data)
{
	t_player	*ply;

	gp_physic_engine(data);
	ply = &data->player;
	if (ply->turn_right && !ply->turn_left)
		ply->angle += (data->mlx.speed) * CAMERA_SPEED;
	if (ply->turn_left && !ply->turn_right)
		ply->angle -= (data->mlx.speed) * CAMERA_SPEED;
	if (!ply->b_move)
		return ;
	if (ply->move_up && !ply->move_down)
		math_coeff_circle(10, data->player.angle, data->player.a_move);
	if (ply->move_down && !ply->move_up)
		math_coeff_circle(10, data->player.angle + 180, data->player.a_move);
	if (ply->move_left && !ply->move_right)
		math_coeff_circle(5, data->player.angle - 90, data->player.a_move);
	if (ply->move_right && !ply->move_left)
		math_coeff_circle(5, data->player.angle + 90, data->player.a_move);
	if (ply->move_up || ply->move_down || ply->move_left || ply->move_right)
	{
		*ply->x += data->mlx.speed * ply->a_move[0] / 10;
		*ply->y += data->mlx.speed * ply->a_move[1] / 10;
	}
	return ;
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
	mlx_hook(winp, 17, 0, graph_close, data);
	mlx_key_hook(winp, bind_bindings, data);
	mlx_hook(winp, 6, 1L<<6, gp_mouse_camera, data);
	mlx_mouse_hook(winp, bind_mouse, data);
	mlx_hook(winp, 02, 1L<<0, bind_keyboard_press, data);
	mlx_hook(winp, 03, 1L<<1, bind_keyboard_release, data);
	return (EXIT_SUCCESS);
}
