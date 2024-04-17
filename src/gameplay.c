/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 04:57:10 by jcuzin            #+#    #+#             */
/*   Updated: 2024/04/17 14:51:21 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	gp_test(t_data *data) //Sandbox function
{
	t_tex	*north;

	(void)north;
	north = &data->map.tex_no;
	// mlx_mouse_get_pos(data->mlxinit, data->win, &north->lorem, &north->ipsum);
	// north->lorem -= (north->wi / 2);
	// north->ipsum -= (north->he / 2);
	re_pixeltoimg(data->game, north->lorem, north->ipsum, conv_rgb(data->map.floor));
	return (EXIT_SUCCESS);
}

int	gp_move(t_data *data)
{
	t_player	*player;
	size_t		speed;

	player = &data->player;
	speed = PLAYER_SPEED;
	if (!player->b_move)
		return (EXIT_SUCCESS);
	if (player->move_up)
		data->map.tex_no.ipsum -= speed;
	if (player->move_down)
		data->map.tex_no.ipsum += speed;
	if (player->move_right)
		data->map.tex_no.lorem += speed;
	if (player->move_left)
		data->map.tex_no.lorem -= speed;
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
	mlxp = data->mlxinit;
	winp = data->win;
	mlx_key_hook(winp, bind_bindings, data);
	mlx_hook(data->win, 02, 1L<<0, bind_keyboard_press, data);
	mlx_hook(data->win, 03, 1L<<1, bind_keyboard_release, data);
	//mlx_mouse_move(mlxp, winp, data->win_wmid, data->win_hmid);
	return (EXIT_SUCCESS);
}
