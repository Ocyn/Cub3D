/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 04:57:10 by jcuzin            #+#    #+#             */
/*   Updated: 2024/06/19 15:36:28 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	gp_physic_engine(t_data *data)
{
	t_player	*mc;
	t_mlx		*mlx;
	double		fps;
	int			cord[2];

	fps = data->mlx.fps + 1;
	mc = &data->player;
	mlx = &data->mlx;
	if (mc->angle < 0)
		mc->angle = 360;
	if (mc->angle > 360)
		mc->angle = 0;
	cord[0] = (int)(*data->player.x + (data->mlx.speed * data->player.a_move[0] \
	/ (fps * 1.2)));
	cord[1] = (int)(*data->player.y + (data->mlx.speed * data->player.a_move[1] \
	/ (fps * 1.2)));
	if ((cord[0] > data->map.xlen) || !data->map.map[(int)(*data->player.y)][cord[0]] \
	|| data->map.map[(int)(*data->player.y)][cord[0]] == '1')
		data->player.a_move[0] = 0;
	if ((cord[1] > data->map.ylen) || !data->map.map[cord[1]] \
	[(int)(*data->player.x)] || data->map.map[cord[1]] \
	[(int)(*data->player.x)] == '1')
		data->player.a_move[1] = 0;
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
	if (abs(mouse) > 20 || \
	abs(data->mlx.win_hmid - data->mlx.mouse_xy[1]) > 100)
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
	double		fps;

	fps = data->mlx.fps + 1;
	ply = &data->player;
	if (ply->turn_right && !ply->turn_left)
		ply->angle += CAMERA_SPEED / (fps / 10);
	if (ply->turn_left && !ply->turn_right)
		ply->angle -= CAMERA_SPEED / (fps / 10);
	if (ply->move_up && !ply->move_down)
		math_circle(10, data->player.angle + 180, data->player.a_move);
	if (ply->move_down && !ply->move_up)
		math_circle(10, data->player.angle, data->player.a_move);
	if (ply->move_left && !ply->move_right)
		math_circle(10 / 2, data->player.angle + 90, data->player.a_move);
	if (ply->move_right && !ply->move_left)
		math_circle(10 / 2, data->player.angle - 90, data->player.a_move);
	gp_physic_engine(data);
	if ((ply->a_move[0] || ply->a_move[1]) \
	&& (ply->move_up || ply->move_down || ply->move_left || ply->move_right))
	{
		*ply->x += ply->a_move[0] / (fps * 1.2);
		*ply->y += ply->a_move[1] / (fps * 1.2);
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
	mlx_hook(winp, 6, 1L << 6, gp_mouse_camera, data);
	mlx_mouse_hook(winp, bind_mouse, data);
	mlx_hook(winp, 02, 1L << 0, bind_keyboard_press, data);
	mlx_hook(winp, 03, 1L << 1, bind_keyboard_release, data);
	return (EXIT_SUCCESS);
}
