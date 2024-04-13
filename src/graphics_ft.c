/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_ft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 07:39:45 by jcuzin            #+#    #+#             */
/*   Updated: 2024/04/13 05:23:41 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	graph_close(t_data *data)
{
	if (!data)
		return (err_return(EXIT_FAILURE, "Memory issue", 1));
	mlx_destroy_window(data->mlxinit, data->win);
	mlx_destroy_display(data->mlxinit);
	free(data->mlxinit);
	data->mlxinit = NULL;
	res_data_struct(data, 1);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

int	graph_init(t_data *data)
{
	char	title[] = "Cub3D";

	data->mlxinit = mlx_init();
	if (!data->mlxinit)
		return (err_return(EXIT_FAILURE, "MLX init failed", 1));
	data->win = mlx_new_window(data->mlxinit, data->win_w, data->win_h, title);
	if (!data->win)
	{
		data->mlxinit = s_free(data->mlxinit);
		mlx_destroy_display(data->mlxinit);
		return (err_return(EXIT_FAILURE, "MLX windows failed to create", 1));
	}
	return (EXIT_SUCCESS);
}

int	graph_event(t_data *data)
{
	(void)data;
	return (EXIT_SUCCESS);
}

int	graph_main(t_data *data)
{
	(void)data;
	db_beacon("MLX", 41);
	if (graph_init(data))
	if (!data->mlxinit)
		return (err_return(EXIT_FAILURE, "MLX init failed", 1));
	mlx_hook(data->win, 17, 0, graph_close, data);
	mlx_key_hook(data->win, gp_gameplay, data);
	mlx_loop(data->mlxinit);
	return (EXIT_SUCCESS);
}
