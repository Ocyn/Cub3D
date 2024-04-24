/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 13:05:49 by jcuzin            #+#    #+#             */
/*   Updated: 2024/04/24 15:34:23 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

inline void	re_pixeltoimg(t_img *img, int x, int y, int color)
{
	if ((size_t)x >= (size_t)img->width || (size_t)y >= (size_t)img->height)
		return ;
	((int *)img->data)[((y * img->width) + x)] = color;
}

inline void	re_draw_environnment(t_data *data, int mode)
{
	if (!mode)
	{
		misc_fill_screen(data->mlx.game, (size_t[2]){0, 0}, \
		(size_t[2]){data->mlx.win_w - 1, data->mlx.win_hmid - 1} \
		, conv_rgb(data->map.roof));
		misc_fill_screen(data->mlx.game \
		, (size_t[2]){0, data->mlx.win_hmid} \
		, (size_t[2]){data->mlx.win_w, data->mlx.win_h} \
		, conv_rgb(data->map.floor));
	}
	if (mode == 1)
	{
		draw_square_snap(&data->mlx, (size_t[2]){0, 0} \
		, (size_t[2]){data->mlx.win_w - 1, data->mlx.win_hmid - 1} \
		, conv_rgb(data->map.roof));
		draw_square_snap(&data->mlx \
		, (size_t[2]){0, data->mlx.win_hmid} \
		, (size_t[2]){data->mlx.win_w, data->mlx.win_h} \
		, conv_rgb(data->map.floor));
	}
}

int	re_events_loop(t_data *data)
{
	if (!data)
		return (EXIT_FAILURE);
	// mlx_mouse_get_pos(data->mlx.init, data->mlx.win \
	// , &data->mlx.mouse_pos[0], &data->mlx.mouse_pos[1]);
	gp_move(data);
	//sb_telecran(data);
	//sb_movingmap(data);
	sb_circle(data);
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
