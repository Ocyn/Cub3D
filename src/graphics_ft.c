/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_ft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 07:39:45 by jcuzin            #+#    #+#             */
/*   Updated: 2024/04/13 03:48:56 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	graph_window_size(t_data *data)
{
	if (data->map.xlen == 0 || data->map.xlen == 0)
		return (err_return(EXIT_FAILURE, "Invalid map size", 2));
	data->win_h = 1000;
	data->win_w = 1000;
	data->win_h_center = (data->win_h / 2);
	data->win_w_center = (data->win_w / 2);
	return (EXIT_SUCCESS);
}

int	graph_init(t_data *data)
{
	char	title[] = "Cub3D";

	(void)data;
	data->mlxinit = mlx_init();
	if (!data->mlxinit || graph_window_size(data))
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

	return (EXIT_SUCCESS);
}
