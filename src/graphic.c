/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 07:39:45 by jcuzin            #+#    #+#             */
/*   Updated: 2024/04/25 22:09:25 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	graph_close(t_data *data)
{
	if (!data)
		return (err_return(EXIT_FAILURE, "Memory issue", 1));
	// db_showmap(data->map, 0);
	if (data->map.tex_no.id)
		mlx_destroy_image(data->mlx.init, data->map.tex_no.id);
	if (data->map.tex_so.id)
		mlx_destroy_image(data->mlx.init, data->map.tex_so.id);
	if (data->map.tex_ea.id)
		mlx_destroy_image(data->mlx.init, data->map.tex_ea.id);
	if (data->map.tex_we.id)
		mlx_destroy_image(data->mlx.init, data->map.tex_we.id);
	if (data->mlx.game)
		mlx_destroy_image(data->mlx.init, data->mlx.game);
	if (data->mlx.init)
	{
		if (data->mlx.win)
			mlx_destroy_window(data->mlx.init, data->mlx.win);
		mlx_destroy_display(data->mlx.init);
		free(data->mlx.init);
	}
	res_data_struct(data, 1);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

int	graph_init(t_data *data)
{
	char	title[] = "Cub3D";

	if (init_mlx_struct(data, &data->mlx))
		return (err_return(EXIT_FAILURE, "MLX init failed", 2));
	if (init_texture_struct(data, &data->map.tex_no))
		return (err_return(EXIT_FAILURE, "North texture loading failed", 2));
	if (init_texture_struct(data, &data->map.tex_so))
		return (err_return(EXIT_FAILURE, "South texture loading failed", 2));
	if (init_texture_struct(data, &data->map.tex_ea))
		return (err_return(EXIT_FAILURE, "East texture loading failed", 2));
	if (init_texture_struct(data, &data->map.tex_we))
		return (err_return(EXIT_FAILURE, "West texture loading failed", 2));
	data->mlx.game = mlx_new_image(data->mlx.init, data->mlx.win_w, data->mlx.win_h);
	re_draw_environnment(data, 1);
	if (!data->mlx.game)
		return (err_return(EXIT_FAILURE, "Rendering image failed to init", 2));
	data->mlx.win = mlx_new_window(data->mlx.init, data->mlx.win_w, data->mlx.win_h, title);
	if (!data->mlx.win)
		return (err_return(EXIT_FAILURE, "MLX windows failed to create", 2));
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
	db_game_info(data);
	gp_gameplay(data);
	mlx_loop_hook(data->mlx.init, re_render, data);
	mlx_loop(data->mlx.init);
	return (EXIT_SUCCESS);
}
