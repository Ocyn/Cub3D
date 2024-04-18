/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 13:05:49 by jcuzin            #+#    #+#             */
/*   Updated: 2024/04/18 18:09:50 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

inline void	re_pixeltoimg(t_img *img, int x, int y, int color)
{
	if ((size_t)x >= (size_t)img->width || (size_t)y >= (size_t)img->height)
		return ;
	((int *)img->data)[((y * img->width) + x)] = color;
}

int	re_events_loop(t_data *data)
{
	if (!data)
		return (EXIT_FAILURE);
	gp_move(data);
	//sb_telecran(data);
	//sb_movingmap(data);
	mmap_minimap(data);
	db_game_monitoring(data);
	return (EXIT_SUCCESS);
}

int	re_render(t_data *data)
{
	if (!data)
		return (EXIT_FAILURE);
	re_events_loop(data);
	mlx_put_image_to_window(data->mlx.init, data->mlx.win, data->mlx.game, 0, 0);
	return (EXIT_SUCCESS);
}

int	re_nothing(void *data)
{
	(void)data;
	return (0);
}
