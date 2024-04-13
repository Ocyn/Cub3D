/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 04:57:10 by jcuzin            #+#    #+#             */
/*   Updated: 2024/04/13 14:45:53 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	gp_test(t_data *data) //Sandbox function
{
	t_tex	*north;

	north = &data->map.tex_no;
	mlx_mouse_get_pos(data->mlxinit, data->win, &north->lorem, &north->ipsum);
	north->lorem -= (north->wi / 2);
	north->ipsum -= (north->he / 2);
	return (EXIT_SUCCESS);
}

int	gp_move(t_data *data)
{
	t_player *player;

	player = &data->player;
	if (player->b_move == 'u')
		data->map.tex_no.ipsum -= 1;
	if (player->b_move == 'd')
		data->map.tex_no.ipsum += 1;
	if (player->b_move == 'r')
		data->map.tex_no.lorem += 1;
	if (player->b_move == 'l')
		data->map.tex_no.lorem -= 1;
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
	//mlx_key_hook(winp, bind_keyboard, data);
	mlx_hook(data->win, 02, 1L<<0, bind_keyboard_press, data);
	mlx_hook(data->win, 03, 1L<<1, bind_keyboard_release, data);
	//mlx_mouse_move(mlxp, winp, data->win_wmid, data->win_hmid);
	return (EXIT_SUCCESS);
}
