/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 04:57:10 by jcuzin            #+#    #+#             */
/*   Updated: 2024/04/17 19:02:39 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	gp_test(t_data *data) //Sandbox function
{
	t_tex	*north;
	t_player	*player;

	(void)north;
	north = &data->map.tex_no;
	player = &data->player;
	// mlx_mouse_get_pos(data->mlx.init, data->mlx.win, &north->lorem, &north->ipsum);
	// north->lorem -= (north->wi / 2);
	// north->ipsum -= (north->he / 2);
	player->ypos = player->y;
	player->xpos = player->x;
	re_pixeltoimg(data->mlx.game, player->xpos, player->ypos, conv_rgb(data->map.floor));
	return (EXIT_SUCCESS);
}

int	gp_move(t_data *data)
{
	t_player	*player;
	double		speed;

	player = &data->player;
	speed = PLAYER_SPEED * 0.1;
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
	mlx_key_hook(winp, bind_bindings, data);
	mlx_hook(data->mlx.win, 02, 1L<<0, bind_keyboard_press, data);
	mlx_hook(data->mlx.win, 03, 1L<<1, bind_keyboard_release, data);
	//mlx_mouse_move(mlxp, winp, data->mlx.win_wmid, data->mlx.win_hmid);
	return (EXIT_SUCCESS);
}
