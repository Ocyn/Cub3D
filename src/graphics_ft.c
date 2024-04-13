/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_ft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 07:39:45 by jcuzin            #+#    #+#             */
/*   Updated: 2024/04/13 13:11:42 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	graph_close(t_data *data)
{
	if (!data)
		return (err_return(EXIT_FAILURE, "Memory issue", 1));
	// db_showmap(data->map, 0);
	if (data->map.tex_no.id)
		mlx_destroy_image(data->mlxinit, data->map.tex_no.id);
	if (data->map.tex_so.id)
		mlx_destroy_image(data->mlxinit, data->map.tex_so.id);
	if (data->map.tex_ea.id)
		mlx_destroy_image(data->mlxinit, data->map.tex_ea.id);
	if (data->map.tex_we.id)
		mlx_destroy_image(data->mlxinit, data->map.tex_we.id);
	if (data->mlxinit)
	{
		if (data->win)
			mlx_destroy_window(data->mlxinit, data->win);
		mlx_destroy_display(data->mlxinit);
		free(data->mlxinit);
	}
	res_data_struct(data, 1);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

int	graph_init(t_data *data)
{
	char	title[] = "Cub3D";

	if (init_mlx_struct(data))
		return (err_return(EXIT_FAILURE, "MLX init failed", 2));
	data->win = mlx_new_window(data->mlxinit, data->win_w, data->win_h, title);
	if (!data->win)
		return (err_return(EXIT_FAILURE, "MLX windows failed to create", 2));
	if (init_texture_struct(data, &data->map.tex_no))
		return (err_return(EXIT_FAILURE, "North texture loading failed", 2));
	if (init_texture_struct(data, &data->map.tex_so))
		return (err_return(EXIT_FAILURE, "South texture loading failed", 2));
	if (init_texture_struct(data, &data->map.tex_ea))
		return (err_return(EXIT_FAILURE, "East texture loading failed", 2));
	if (init_texture_struct(data, &data->map.tex_we))
		return (err_return(EXIT_FAILURE, "West texture loading failed", 2));
	return (EXIT_SUCCESS);
}

int	graph_test(t_data *data) //Testing image openning
{
	t_tex	*north;

	north = &data->map.tex_no;
	// north->lorem = data->win_wmid - (north->wi / 2);
	// north->ipsum = data->win_hmid - (north->he / 2);
	mlx_mouse_get_pos(data->mlxinit, data->win, &north->lorem, &north->ipsum);
	north->lorem -= (north->wi / 2);
	north->ipsum -= (north->he / 2);
	return (EXIT_SUCCESS);
}


int	graph_main(t_data *data)
{
	(void)data;
	db_beacon("MLX", 41);
	if (graph_init(data))
	{
		graph_close(data);
		return (err_return(EXIT_FAILURE, "MLX init failed", 1));
	}
	//graph_test(data);
	mlx_hook(data->win, 17, 0, graph_close, data);
	mlx_loop_hook(data->mlxinit, re_render, data);
	gp_gameplay(data);
	mlx_loop(data->mlxinit);
	return (EXIT_SUCCESS);
}
